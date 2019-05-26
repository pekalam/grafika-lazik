#pragma once
#include "SceneObject.h"

class BrylaGlowna : public SceneObject
{
protected:
	void drawObject() override{}
public:
	BrylaGlowna(Vector3 position = {0, 0, 0}, Vector3 rotation = {0, 0, 0}, std::vector<SceneObject*> children = {},
	            Vector3 color = {0, 0, 0});;
};

