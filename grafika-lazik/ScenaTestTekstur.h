#pragma once
#include "SceneObject.h"

class Texture2D;

class ScenaTestTekstur : public SceneObject
{
protected:
	void drawObject() override;
	Texture2D *t;
public:
	ScenaTestTekstur(Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,165,0 }, Vector3 color = { 0,1,0 });
	~ScenaTestTekstur();
};

