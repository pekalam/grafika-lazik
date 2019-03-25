#pragma once
#include "SceneObject.h"

class SzescianG : public SceneObject
{
protected:
	void drawObject() override;
private:
	GLfloat _divStep;
	GLfloat _dl, _wys, _szer;
public:
	SzescianG(GLfloat dl, GLfloat wys, GLfloat szer,
		Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }, GLfloat divStep = 1.0f) : SceneObject(position, rotation),  _divStep(divStep), _wys(wys), _dl(dl), _szer(szer) {};
	SzescianG(std::string name, GLfloat dl, GLfloat wys, GLfloat szer,
		Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }, GLfloat divStep = 1.0f) : SceneObject(name, position, rotation), _divStep(divStep), _wys(wys), _dl(dl), _szer(szer) {};
};

