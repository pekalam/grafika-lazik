#include "stdafx.h"
#include "ScenaTestTekstur.h"
#include "ScianaG.h"
#include "SzescianG.h"


void ScenaTestTekstur::drawObject()
{

}

ScenaTestTekstur::ScenaTestTekstur(Vector3 position, Vector3 rotation, Vector3 color) : SceneObject(position, rotation, color)
{
	//join(new ScianaG(100, 100, 10, 10, {}, {0, 0, 0}, {1, 0, 0}));
	auto sze = new SzescianG(20, 20, 20, { 0, 15, 0 }, {0, 180,0}, 
		4,4,1, {1,1,1});
	sze->setTexture2D(new Texture2D("crate.bmp"));
	join(sze);
}

ScenaTestTekstur::~ScenaTestTekstur()
{
}
