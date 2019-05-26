#pragma once
#include "SceneObject.h"

class Pojemnik : public SceneObject
{
protected:
	void drawObject() override{}
public:
	Pojemnik(Vector3 position = {0, 0, 0}, Vector3 rotation = {0, 0, 0});
};
