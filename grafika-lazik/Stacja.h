#pragma once
#include "SceneObject.h"

class Stacja : public SceneObject
{
public:
	Stacja(Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }, Vector3 color = { 0,0,0 });
	~Stacja();
};

