#pragma once
#include "SceneObject.h"

class SzescianG : public SceneObject
{
protected:
	void drawObject() override;
private:
	int _sectorsX, _sectorsY, _sectorsZ;
	GLfloat _dl, _wys, _szer;
public:
	SzescianG(GLfloat dl, GLfloat wys, GLfloat szer,
		Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }, 
		int sectorsX = 1, int sectorsY = 1, int sectorsZ = 1) : SceneObject(position, rotation), _sectorsX(sectorsX), _sectorsY(sectorsY) , _sectorsZ(sectorsZ), _wys(wys), _dl(dl), _szer(szer) {};
	SzescianG(std::string name, GLfloat dl, GLfloat wys, GLfloat szer,
		Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }, 
		int sectorsX = 1, int sectorsY = 1, int sectorsZ = 1) : SceneObject(name, position, rotation), _sectorsX(sectorsX), _sectorsY(sectorsY), _sectorsZ(sectorsZ), _wys(wys), _dl(dl), _szer(szer) {};
};

