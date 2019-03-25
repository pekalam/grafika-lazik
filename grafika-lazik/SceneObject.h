#pragma once
#include "Vector3.h"
#include <vector>
#include <memory>
#include <functional>


#define RAD(deg) deg*GL_PI/180.0f;

class ViewEngine;

// Obiekt / grupa obiektow na scenie
class SceneObject
{
private:
	std::vector<std::unique_ptr<SceneObject>> _children;
	std::string _name;
	bool _hide = false;
	bool _isChild = false;
	std::string getBaseName() const;
	void _create();
public:
	void hide(){_hide = true;}
	void show() { _hide = false; }
	bool isVisible() { return !_hide; }
	bool isChild() const{return _isChild;}
protected:
	Vector3 _position;
protected:
	Vector3 _rotation;
	virtual void drawObject() {};
public:
	SceneObject(Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }) : _position(position), _rotation(rotation) { _create(); };
	SceneObject(std::string name, Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }) : _name(name), _position(position), _rotation(rotation) { _create(); };
	virtual ~SceneObject();

	// obrot obiektu / grupy obiektow (w radianach)
	void rotate(GLfloat x, GLfloat y, GLfloat z) { _rotation.x = x; _rotation.y = y; _rotation.z = z; }
	void rotate(Vector3 angles) { _rotation = angles; }
	void rotateX(GLfloat x) { _rotation.x = x; }
	void rotateY(GLfloat y) { _rotation.y = y; }
	void rotateZ(GLfloat z) { _rotation.z = z; }

	// przesuniecie obiektu / grupy obiektow
	void translate(GLfloat x, GLfloat y, GLfloat z) { _position.x += x; _position.y += y; _position.z += z; }
	void translate(Vector3 p) { _position += p; }
	void translateX(GLfloat x) { _position.x += x; }
	void translateY(GLfloat y) { _position.y += y; }
	void translateZ(GLfloat z) { _position.z += z; }

	// dodanie obiektu do grupy obiektow potomnych
	void join(SceneObject* obj);
	void join(std::unique_ptr<SceneObject>& obj);

	// usuniecie obiektu z grupy obiektow potomnych
	std::unique_ptr<SceneObject> disjoin(const std::string name);

	// zwraca obiekt potomny
	SceneObject* child(const std::string name);


	// ustala pozycje obiektu
	void position(const Vector3& vector3){_position = vector3;}
	void positionX(GLfloat x){_position.x = x;}
	void positionY(GLfloat y) { _position.y = y; }
	void positionZ(GLfloat z) { _position.z = z; }
	Vector3 position() const { return _position; }

	// ustala obrot obiektu (w radianach)
	void rotation(const Vector3& vector3){_rotation = vector3;}
	void rotationX(GLfloat x) { _rotation.x = x; }
	void rotationY(GLfloat y) { _rotation.y = y; }
	void rotationZ(GLfloat z) { _rotation.z = z; }
	Vector3 rotation() const { return _rotation; }

	// rysuje obiekt i obiekty potomne na scenie
	void render();


	int childrenCount() const { return _children.size(); }
	const std::string &name() const { return _name; }
	void name(const std::string &newName) { _name = newName; }
};


