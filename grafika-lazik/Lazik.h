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
#include "Rama.h"


class Lazik :
	public SceneObject
{
protected:
	void drawObject() override;
public:
	Lazik(Vector3 position = {0, 0, 0}, Vector3 rotation = {0, 0, 0}) : SceneObject("lazik", position, rotation)
	{
		auto kam = new GlownaKamera({ 6, 13.75, -7.5 });
		join(kam);
		join(new BrylaGlowna());
		join(new Pojemnik({0,3,17}, {-25, 0,0}));
		SceneObject& rama = join(new Rama());
		rama.positionY(-1.5f);
		positionY(.75+((Rama&)rama).wysokosc());
	}
};



inline void Lazik::drawObject()
{
	//child("sz1")->positionX(10);
	//child("kula1")->positionY(10);

}
