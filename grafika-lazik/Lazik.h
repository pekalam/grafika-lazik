#pragma once
#include "SceneObject.h"
#include "KulaG.h"
#include "SzescianG.h"
#include "WalecG.h"
#include "PierscienG.h"
#include "GlownaKamera.h"
#include "ScianaG.h"
#include "TrapezProstG.h"


class Lazik :
	public SceneObject
{
protected:
	void drawObject() override;
public:
	Lazik(Vector3 position = {0, 0, 0}, Vector3 rotation = {0, 0, 0}) : SceneObject("lazik", position, rotation)
	{
		join(new GlownaKamera({6, 8, -7.5}));
		join(new SzescianG("czglowna", 15, 6, 20, {0,0,0}, {0,0,0}, 1, 1, 1, {0.5, 1.0f, 0.5}));
		this->position({ 0,0,0 });
	}
};



inline void Lazik::drawObject()
{
	//child("sz1")->positionX(10);
	//child("kula1")->positionY(10);

}
