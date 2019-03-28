#pragma once
#include "SceneObject.h"
#include "KulaG.h"
#include "SzescianG.h"
#include "WalecG.h"


class Lazik :
	public SceneObject
{
protected:
	void drawObject() override;
public:
	Lazik(Vector3 position = {0, 0, 0}, Vector3 rotation = {0, 0, 0}) : SceneObject("lazik", position, rotation)
	{
		join(new SzescianG{"sz1", 20, 5, 20});
		join(new KulaG{ "kula1",5,12,12 , {0,0,0}});
		join(new WalecG("walec1", 20, 5));
		this->position({ 0,10,0 });
	}
};



inline void Lazik::drawObject()
{
	child("sz1")->positionX(10);
	child("kula1")->positionY(10);
}
