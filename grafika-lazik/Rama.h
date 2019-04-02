#pragma once
#include "SceneObject.h"
#include "PierscienG.h"
#include "WalecG.h"
#include "SzescianG.h"
class Rama : public SceneObject
{
protected:
	void drawObject() override;
public:
	GLfloat dlugosc();
	Rama(Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }) : SceneObject("rama", position, rotation)
	{
		
		join(new SceneObject("podwozie", {}, {}, {
			new WalecG(1,0.5,{8,-2.0,2.0},{0,90,0},1.0),
			new WalecG(1,0.5,{-8,-2.0,2.0},{0,90,0},1.0),
			new WalecG(2,0.5,{9.5,-2.0,10.0},{0,90,0},1.0),
			new WalecG(2,0.5,{-9.5,-2.0,10.0},{0,90,0},1.0),
			new WalecG(8.5,0.5,{8.5,-2.0,6.0},{0,5.5,0},1.0),
			new WalecG(8.5,0.5,{-8.5,-2.0,6.0},{0,-5.5,0},1.0),
			new WalecG(6,0.5,{10,-3.5,7.0},{-27.5,0,0},1.0),
			new WalecG(6,0.5,{-10,-3.5,7.0},{-27.5,0,0},1.0),
			new WalecG(12,0.5,{10,-3.5,16},{13.0,0,0},1.0),
			new WalecG(12,0.5,{-10,-3.5,16},{13.0,0,0},1.0),
			new WalecG(1,0.5,{10,-4.75,4.5},{0,90,0},1.0), 
			new WalecG(1,0.5,{-10,-4.75,4.5},{0,90,0},1.0), 
			new WalecG(1,0.5,{10,-4.75,21.75},{0,90,0},1.0), 
			new WalecG(1,0.5,{-10,-4.75,21.75},{0,90,0},1.0), 
			new WalecG(1,0.5,{-9.85,-4.75,-13.75},{0,90,0},1.0), 
			new WalecG(1,0.5,{9.85,-4.75,-13.75},{0,90,0},1.0), 
			new WalecG(2,0.125,{11,-4.75,4.5},{0,90,0}), // os srodkowa
			new WalecG(2,0.125,{-11,-4.75,4.5},{0,90,0}), // os srodkowa
			new WalecG(2,0.125,{11,-4.75,21.75},{0,90,0}), // os tylnia
			new WalecG(2,0.125,{-11,-4.75,21.75},{0,90,0}), // os tylnia
			new WalecG(2,0.125,{10.85,-4.75,-13.75},{0,90,0}), // os przednia
			new WalecG(2,0.125,{-10.85,-4.75,-13.75},{0,90,0}), // os przednia
			new PierscienG(1.25,2.0,0.5,20.0,{11.5,-4.75,4.5},{0,90,0}), // kolo srodkowe
			new PierscienG(1.25,2.0,0.5,20.0,{-11.5,-4.75,4.5},{0,90,0}), // kolo srodkowe
			new PierscienG(1.25,2.0,0.5,20.0,{11.5,-4.75,21.75},{0,90,0}), // kolo tylnie
			new PierscienG(1.25,2.0,0.5,20.0,{-11.5,-4.75,21.75},{0,90,0}), // kolo tylnie
			new PierscienG(1.25,2.0,0.5,20.0,{10.85,-4.75,-13.75},{0,90,0}), // kolo przednie
			new PierscienG(1.25,2.0,0.5,20.0,{-10.85,-4.75,-13.75},{0,90,0}), // kolo przednie
			new WalecG(16.0,0.5,{9,-2.0,-6},{0,-6,0},1.0),
			new WalecG(16.0,0.5,{-9,-2.0,-6},{0,6,0},1.0),
			new WalecG(2.0,0.5,{9.85,-2.0,-13.75},{90,0,0},1.0),
			new WalecG(2.0,0.5,{-9.85,-2.0,-13.75},{90,0,0},1.0),
			new SzescianG(1.4,0.5,1,{9.65,-3.75,-13.75},{0,0,90}),
			new SzescianG(1.4,0.5,1,{-9.65,-3.75,-13.75},{0,0,90}),
			new SzescianG(2,0.5,1,{10.75,-3.25,-13.75},{0,0,0}),
			new SzescianG(2,0.5,1,{-10.75,-3.25,-13.75},{0,0,0})
			}));
	}
};
inline void Rama::drawObject()
{
}

