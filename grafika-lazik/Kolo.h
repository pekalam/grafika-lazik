#pragma once
#include "SceneObject.h"
#include "PierscienG.h"

class Kolo :
	public SceneObject
{
private:
	GLfloat r;
	GLfloat h;
	GLfloat szer;
protected:
	void drawObject() override
	{
	}

public:
	Kolo(std::string name ,Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }) : SceneObject(name, position, rotation), r(1.25f), h(2.0f), szer(0.5f)
	{
		auto t = new PierscienG(r, h, szer, 20.0);
		t->addTexture(new Texture2D("tyre.bmp"));
		join(t);
		join(new WalecG("os", 2, 0.125, {0,0, .25f}));
	}
	GLfloat wysokosc()
	{
		return r * 2;
	}
	GLfloat szerokosc()
	{
		return h;
	}
	GLfloat gruboscOpony()
	{
		return szer;
	}
};



