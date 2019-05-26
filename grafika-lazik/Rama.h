#pragma once
#include "SceneObject.h"

class Rama : public SceneObject
{
private:
	GLfloat osWys = 1.25f;
	GLfloat os2Wys = 2.75f;
protected:
	void drawObject() override {};
public:
	GLfloat wysokosc();

	Rama(Vector3 position = {0, 0, 0}, Vector3 rotation = {0, 0, 0});
};

