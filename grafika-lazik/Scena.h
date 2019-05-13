#pragma once
#include "SceneObject.h"
#include "Powierzchnia.h"
#include "Lazik.h"
#include "Icosphere42.h"
#include "Kamien.h"

class Scena :
	public SceneObject
{
protected:
	void drawObject() override
	{
	}

public:
	Scena(Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,125,0 }, Vector3 color = { 0,1,0 });

};




