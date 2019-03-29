#pragma once
#include "SceneObject.h"

class ScianaG : public SceneObject
{
private:
	int _sectorsX, _sectorsZ;
	GLfloat _dl, _szer;
protected:
	void drawObject() override;
public:
	ScianaG(GLfloat dl, GLfloat szer, int sectorsX, int sectorsZ, Vector3 position = {0,0,0}, Vector3 rotation = { 0,0,0 }) : SceneObject(position, rotation), _dl(dl), _szer(szer), _sectorsZ(sectorsZ), _sectorsX(sectorsX){};
	ScianaG(std::string name, GLfloat dl, GLfloat szer, int sectorsX, int sectorsZ, Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }) 
		: SceneObject(name, position, rotation), _dl(dl), _szer(szer), _sectorsZ(sectorsZ), _sectorsX(sectorsX) {};
};

