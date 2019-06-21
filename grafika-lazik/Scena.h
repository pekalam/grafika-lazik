#pragma once
#include "SceneObject.h"
#include "Powierzchnia.h"
#include "Lazik.h"
#include "Icosphere42.h"
#include "Kamien.h"
#include "Stacja.h"
#include "SzescianG.h"
#include "PierscienG.h"


class Scena :
	public SceneObject
{
protected:
	void drawObject() {};
public:
	Scena(Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,165,0 }, Vector3 color = { 0,1,0 });

};


inline Scena::Scena(Vector3 position, Vector3 rotation, Vector3 color) : SceneObject("scena", position, rotation, {}, color)
{
	auto pow = new Powierzchnia({ 0,0 });
	pow->addTexture(new Texture2D("piach.bmp", true));
	join(pow);
	join(new Lazik({ 0, 2, 0 }));
	
	std::random_device rd;
	std::mt19937 e2(rd());
	float rg = 100;
	std::uniform_real_distribution<> distX(-100, 100);
	std::uniform_real_distribution<> distY(-100, 100);
	std::uniform_real_distribution<> distR(1, 3);
	std::uniform_int_distribution<> distPatt(0, 99);
	Kamien* patt[200];
	for (int i = 0; i < 200; i++)
	{
		patt[i] = new Kamien(distR(e2), { (float)distX(e2), 2, -(float)distY(e2) });
		join(patt[i]);
	}
	/*
	for (int i = 0; i < 1700; i++) {
		auto r = distPatt(e2);
		auto rock = new Kamien(*patt[r]);
		rock->positionX((float)distX(e2));
		rock->positionZ(-(float)distY(e2));
		join(rock);
	}
	for (int i = 0; i < 500; i++) {
		auto r = distPatt(e2);
		auto rock = new Kamien(*patt[r]);
		rock->positionX((float)distX(e2));
		rock->positionZ(-(float)distY(e2));
		rock->positionY(1);
		join(rock);
	}*/
	auto prz = new SzescianG(10, 10, 10, { 50, 40, 0 });
	prz->setBoundingBox(15,10,10);
	prz->setHasPhysics(true);
	join(prz);
	auto prz2 = new SzescianG(10, 10, 10, { -80, 40, 20 });
	prz2->setBoundingBox(15, 10, 10);
	prz2->setHasPhysics(true);
	join(prz2);


	auto k1 = new Kamien(40, { 50, 0, -10 });
	Vector3 g[3] = { { 0.456f,0.328f,0.1328f }, { 0.456f,0.328f,0.1328f }, { 0.456f,0.328f,0.1328f } };
	k1->setGradient(g);
	auto k2 = new Kamien(60, { 60, 0, 20 });
	k2->setGradient(g);
	auto k3 = new Kamien(40, { 50, 0, 40 });
	k3->setGradient(g);
	auto k4 = new Kamien(40, { 50, 0, 60 });
	k4->setGradient(g);

	join(k1);
	join(k2);
	join(k3);
	join(k4);
	join(new Stacja({ -40, -1.5, 200 }, { 0,190, 0 }));
}

