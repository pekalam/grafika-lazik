#pragma once
#include "SceneObject.h"
#include "KulaG.h"
#include "SzescianG.h"
#include "WalecG.h"
#include "PierscienG.h"
#include "GlownaKamera.h"
#include "ScianaG.h"
#include "TrapezRownoramiennyG.h"
#include "BrylaGlowna.h"
#include "Pojemnik.h"


class Lazik :
	public SceneObject
{
protected:
	void drawObject() override;
public:
	Lazik(Vector3 position = {0, 0, 0}, Vector3 rotation = {0, 0, 0}) : SceneObject("lazik", position, rotation)
	{
		join(new GlownaKamera({6, 8, -7.5}));
		join(new BrylaGlowna());
		join(new Pojemnik({0,3,17}, {-25, 0,0}));
		this->position({ 0,0,0 });
	}
};



inline void Lazik::drawObject()
{
	//child("sz1")->positionX(10);
	//child("kula1")->positionY(10);

}
