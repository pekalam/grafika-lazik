#include "stdafx.h"
#include "Scena.h"
#include "Stacja.h"


Scena::Scena(Vector3 position, Vector3 rotation, Vector3 color) : SceneObject(position, rotation, color)
{
	join(new Powierzchnia());
	join(new Lazik({ 0, 0, 0 }));
	std::random_device rd;
	std::mt19937 e2(rd());
	float rg = 100;
	std::uniform_real_distribution<> distX(-rg, rg);
	std::uniform_real_distribution<> distY(-rg, rg);
	std::uniform_real_distribution<> distR(1, 3);
	std::uniform_int_distribution<> distPatt(0, 99);
	Kamien* patt[100];
	for(int i = 0; i < 100; i++)
	{
		patt[i] = new Kamien(distR(e2), { (float)distX(e2), 0, -(float)distY(e2) });
		join(patt[i]);
	}
	for (int i = 0; i < 2000; i++) {
		auto r = distPatt(e2);
		auto rock = new Kamien(*patt[r]);
		rock->positionX((float)distX(e2));
		rock->positionZ(-(float)distY(e2));
		join(rock);
	}
	join(new Stacja({80, 0, 150}, {0,190, 0}));
}
