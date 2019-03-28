#pragma once
#include "SceneObject.h"

class WalecG : public SceneObject
{
protected:
	void drawObject() override;
private:
	GLfloat _divStep;
	GLfloat _r, _wys;
public:
	WalecG(GLfloat wys, GLfloat rad,
		Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }, GLfloat divStep = 1.0f) : SceneObject(position, rotation), _divStep(divStep), _wys(wys), _r(rad) {};
	WalecG(std::string name, GLfloat wys, GLfloat rad,
		Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }, GLfloat divStep = 1.0f) : SceneObject(name, position, rotation), _divStep(divStep), _wys(wys), _r(rad) {};
};
