#include "stdafx.h"
#include "Scena.h"
#include "Stacja.h"




void Scena::drawObject()
{

}

Scena::Scena(Vector3 position, Vector3 rotation, Vector3 color) : SceneObject(position, rotation, color)
{
	join(new Powierzchnia({ 0,-13.7 }));
	join(new Lazik({ 0, 0, 0 }));
	std::random_device rd;
	std::mt19937 e2(rd());
	float rg = 100;
	std::uniform_real_distribution<> distX(-45, 55);
	std::uniform_real_distribution<> distY(-50, 30);
	std::uniform_real_distribution<> distR(1, 3);
	std::uniform_int_distribution<> distPatt(0, 99);
	Kamien* patt[100];
	for (int i = 0; i < 100; i++)
	{
		patt[i] = new Kamien(distR(e2), { (float)distX(e2), 0, -(float)distY(e2) });
		join(patt[i]);
	}
	for (int i = 0; i < 1700; i++) {
		auto r = distPatt(e2);
		auto rock = new Kamien(*patt[r]);
		rock->positionX((float)distX(e2));
		rock->positionZ(-(float)distY(e2));
		join(rock);
	}
	std::uniform_real_distribution<> distY2(30, 40);
	for (int i = 0; i < 500; i++) {
		auto r = distPatt(e2);
		auto rock = new Kamien(*patt[r]);
		rock->positionX((float)distX(e2));
		rock->positionZ(-(float)distY2(e2));
		rock->positionY(1);
		join(rock);
	}
	auto k1 = new Kamien(40, { 50, 0, -10 });
	Vector3 g[3] = { { 0.456f,0.328f,0.1328f }, { 0.456f,0.328f,0.1328f }, { 0.456f,0.328f,0.1328f } };
 	k1->setGradient(g);
	auto k2 = new Kamien(60, { 60, 0, 20 });
	k2->setGradient(g);
	auto k3 = new Kamien(40, { 50, 0, 40 });
	k3->setGradient(g);
	auto k4 = new Kamien(40, { 50, 1, 60 });
	k4->setGradient(g);

	join(k1);
	join(k2);
	join(k3);
	join(k4);
	join(new Stacja({-40, -1.5, 200}, {0,190, 0}));
}
