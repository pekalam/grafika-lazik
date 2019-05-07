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
	Scena();

};

inline Scena::Scena()
{
	join(new Powierzchnia());
	join(new Lazik({0, 0, 0}));
	std::random_device rd;
	std::mt19937 e2(rd());
	std::uniform_real_distribution<> distX(-15, 15);
	std::uniform_real_distribution<> distY(-15, 15);
	for(int i = 0; i < 1000; i++)
		join(new Kamien(1, {(float)distX(e2), 0, -(float)distY(e2)}));
}


