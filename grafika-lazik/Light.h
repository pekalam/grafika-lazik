#pragma once
#include "SceneObject.h"

class Light : public SceneObject
{
protected:
	void drawObject() override;
public:
	Light(Vector3 position = {0, 0, 0}, Vector3 rotation = {0, 0, 0});
};

