#include "stdafx.h"
#include "Scena.h"


Scena::Scena(Vector3 position, Vector3 rotation, Vector3 color) : SceneObject(position, rotation, color)
{
	join(new Powierzchnia());
	join(new Lazik({ 0, 0, 0 }));
	std::random_device rd;
	std::mt19937 e2(rd());
	std::uniform_real_distribution<> distX(-15, 15);
	std::uniform_real_distribution<> distY(-15, 15);
	for (int i = 0; i < 1000; i++)
		join(new Kamien(1, { (float)distX(e2), 0, -(float)distY(e2) }));
}
