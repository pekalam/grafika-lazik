#pragma once
#include "SceneObject.h"
#include "PierscienG.h"
#include "WalecG.h"
#include "SzescianG.h"
#include "Kolo.h"

class Rama : public SceneObject
{
private:
	GLfloat osWys = 1.25f;
	GLfloat os2Wys = 2.75f;
protected:
	void drawObject() override;
public:
	GLfloat wysokosc()
	{
		return ((Kolo*)child("kolo-srodek-l"))->wysokosc() + os2Wys;
	}
	Rama(Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }) : SceneObject("rama", position, rotation)
	{
		GLfloat pos = 0.0f;
		GLfloat pos2 = pos - osWys;
		GLfloat osPos = pos - os2Wys;
		
		
		join(new WalecG(1,0.75,{8, pos,2.0},{0,90,0},1.0));
		join(new WalecG(1,0.75,{-8, pos,2.0},{0,90,0},1.0));
		join(new WalecG(2,0.75,{9.5, pos,10.0},{0,90,0},1.0));
		join(new WalecG(2,0.75,{-9.5, pos,10.0},{0,90,0},1.0));
		join(new WalecG(8.5,0.5,{8.5, pos,6.0},{0,5.5,0},1.0));
		join(new WalecG(8.5,0.5,{-8.5,pos,6.0},{0,-5.5,0},1.0));
		join(new WalecG(6,0.5,{10,pos2,7.0},{-27.5,0,0},1.0));
		join(new WalecG(6,0.5,{-10,pos2,7.0},{-27.5,0,0},1.0));
		join(new WalecG(12,0.5,{10,pos2,16},{13.0,0,0},1.0));
		join(new WalecG(12,0.5,{-10,pos2,16},{13.0,0,0},1.0));
		join(new WalecG(1,0.6,{10,osPos,4.5},{0,90,0},1.0)); 
		join(new WalecG(1,0.6,{-10,osPos,4.5},{0,90,0},1.0)); 
		join(new WalecG(1,0.6,{10,osPos,21.75},{0,90,0},1.0));
		join(new WalecG(1,0.6,{-10,osPos,21.75},{0,90,0},1.0)); 
		join(new WalecG(1,0.6,{-9.85,osPos,-13.75},{0,90,0},1.0));
		join(new WalecG(1,0.6,{9.85,osPos,-13.75},{0,90,0},1.0)); 

		join(new WalecG(16.0,0.5,{9,pos,-6},{0,-6,0},1.0));
		join(new WalecG(16.0,0.5,{-9,pos,-6},{0,6,0},1.0));
		join(new WalecG(2.0,0.6,{9.75,pos,-13.75},{90,0,0},1.0));
		join(new WalecG(2.0,0.6,{-9.75,pos,-13.75},{90,0,0},1.0));
		join(new SzescianG(1.4,0.5,1,{9.65,pos2-.25f,-13.75},{0,0,90}));
		join(new SzescianG(1.4,0.5,1,{-9.65,pos2 - .25f,-13.75},{0,0,90}));
		join(new SzescianG(2,0.5,1,{10.75,pos2+.25f,-13.75},{0,0,0}));
		join(new SzescianG(2,0.5,1,{-10.75,pos2+.25f,-13.75},{0,0,0}));

		join(new Kolo("kolo-srodek-r", {11.5, osPos,4.5}, {0,-90,0})); // kolo srodkowe
		join(new Kolo("kolo-srodek-l", {-11.5, osPos,4.5}, {0,90,0})); // kolo srodkowe
		join(new Kolo("kolo-tyl-r", {11.5, osPos,21.75}, {0,-90,0}));// kolo tylnie
		join(new Kolo("kolo-tyl-l", {-11.5, osPos,21.75}, {0,90,0}));// kolo tylnie
		join(new Kolo("kolo-przednie-r", {10.85, osPos,-13.75}, {0,-90,0}));// kolo przednie
		join(new Kolo("kolo-przednie-l", {-10.85, osPos,-13.75}, {0,90,0}));// kolo przednie
	}
};
inline void Rama::drawObject()
{
}

