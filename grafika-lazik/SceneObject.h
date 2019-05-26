#pragma once
#include "Vector3.h"
#include <vector>
#include <memory>
#include <functional>
#include "Physics.h"


#define RAD(deg) deg*GL_PI/180.0f

class ViewEngine;
class BoundingBox;

// Obiekt / grupa obiektow na scenie
class SceneObject
{
	friend class PhysicsEngine;
private:
	std::vector<std::unique_ptr<SceneObject>> _children;
	std::string _name;
	bool _hide = false;
	bool _isChild = false;
	/** Czy silnik fizyki nie ma uwzgledniac obiektu */
	bool _hasPhysics = false;
	/** Czy dzialaja na niego sily i grawitacja */
	bool _isStatic = false;
	Physics _physics;
private:
	void _create();
	std::string getBaseName() const;
	BoundingBox* _boundingBox = nullptr;
protected:
	Vector3 _position;
	Vector3 _rotation;
	Vector3 _color;
	Vector3 _coordRotation;
	virtual void drawObject() {};
public:
	static Vector3 currentColor;
	SceneObject(Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }, Vector3 color = {0,0,0}, float m = 0) : 
		_position(position), 
		_rotation(rotation),
		_color(color),
		_physics(PhysicsConfig::Default, m)
	{
		_create();
	};
	SceneObject(std::string name, Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }, std::vector<SceneObject*> children = {}, Vector3 color = {0,0,0}, float m = 0) 
		: _name(name), 
		_position(position), 
		_rotation(rotation),
		_color(color),
		_physics(PhysicsConfig::Default, m)
	{
		for (auto it = children.begin(); it != children.end(); ++it)
			join(*it);

		_create();
	};
	virtual ~SceneObject();

	// obrot obiektu / grupy obiektow (w radianach)
	void rotate(GLfloat x, GLfloat y, GLfloat z) { _rotation.x = x; _rotation.y = y; _rotation.z = z; }
	void rotate(Vector3 angles) { _rotation = angles; }
	void rotateX(GLfloat x) { _rotation.x = x; }
	void rotateY(GLfloat y) { _rotation.y = y; }
	void rotateZ(GLfloat z) { _rotation.z = z; }
	void coordRotate(GLfloat x, GLfloat y, GLfloat z) { _coordRotation.x = x; _coordRotation.y = y; _coordRotation.z = z; }
	void coordRotateX(GLfloat x) { _coordRotation.x = x; }
	void coordRotateY(GLfloat y) { _coordRotation.y = y; }
	void coordRotateZ(GLfloat z) { _coordRotation.z = z; }

	/** Zmiana polozenia o x, y, z */
	void translate(GLfloat x, GLfloat y, GLfloat z) { _position.x += x; _position.y += y; _position.z += z; }
	/** Zmiana polozenia dodajac wektor p */
	void translate(Vector3 p) { _position += p; }
	/** Zmiana polozenia o x */
	void translateX(GLfloat x) { _position.x += x; }
	/** Zmiana polozenia o y */
	void translateY(GLfloat y) { _position.y += y; }
	/** Zmiana polozenia o z */
	void translateZ(GLfloat z) { _position.z += z; }

	// dodanie obiektu do grupy obiektow potomnych
	SceneObject& join(SceneObject* obj);
	SceneObject& join(std::unique_ptr<SceneObject>& obj);

	/** usuniecie obiektu z grupy obiektow potomnych */
	std::unique_ptr<SceneObject> disjoin(const std::string name);

	/** zwraca obiekt potomny */
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

	/** rysuje obiekt i obiekty potomne na scenie */
	void render();
	

	int childrenCount() const { return _children.size(); }
	const std::string &name() const { return _name; }
	void name(const std::string &newName) { _name = newName; }
	void hide() { _hide = true; }
	void show() { _hide = false; }
	bool isVisible() { return !_hide; }
	bool isChild() const { return _isChild; }
	Vector3 color() const{return _color;}
	void color(const Vector3& vector3){_color = vector3;}

	Physics& getPhysics()
	{
		return _physics;
	}

	void setBoundingBox(int lengthx, int heighty, int widthz);
	BoundingBox* getBoundingBox();
	/** Uwzglednienie obiektu przez silnik fizyki */
	bool hasPhysics() { return _hasPhysics; }
	void setHasPhysics(bool s) { _hasPhysics = s; }
	bool isStatic() { return _isStatic; }
	void setStatic(bool s) { _isStatic = s; }
};


