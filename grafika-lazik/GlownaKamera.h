#pragma once
#include "SceneObject.h"

class GlownaKamera : public SceneObject
{
protected:
	void drawObject() override{}
public:
	GlownaKamera(Vector3 position = {0, 0, 0}, Vector3 rotation = {0, 0, 0});;
};


