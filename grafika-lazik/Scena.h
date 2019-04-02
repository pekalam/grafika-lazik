#pragma once
#include "SceneObject.h"
#include "Powierzchnia.h"
#include "Lazik.h"

class Scena :
	public SceneObject
{
protected:
	void drawObject() override
	{
	}

public:
	Scena();

};

inline Scena::Scena()
{
	join(new Powierzchnia());
	join(new Lazik({0, 6.5, 0}));
}


