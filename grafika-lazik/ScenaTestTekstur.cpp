#include "stdafx.h"
#include "ScenaTestTekstur.h"
#include "ScianaG.h"
#include "SzescianG.h"
#include "KulaG.h"
#include "WalecG.h"


void ScenaTestTekstur::drawObject()
{

}

ScenaTestTekstur::ScenaTestTekstur(Vector3 position, Vector3 rotation, Vector3 color) : SceneObject(position, rotation, color)
{
	//join(new ScianaG(100, 100, 10, 10, {}, {0, 0, 0}, {1, 0, 0}));
	/*auto sze = new SzescianG(20, 20, 20, { 0, 15, 0 }, {0, 180,0}, 
		4,4,1, {1,1,1});
	sze->addTexture(new Texture2D("prz.bmp"));
	join(sze);*/

	/*auto kul = new KulaG(10, 10, 10, {}, {}, { 1,1,1 });
	kul->addTexture(new Texture2D("prz.bmp"));
	join(kul);

	auto sc = new ScianaG(20, 20, 20, 20);
	sc->addTexture(new Texture2D("prz.bmp"));
	join(sc);*/

	auto walc = new WalecG(10, 5);
	walc->color({ 1,1,1 });
	walc->addTexture(new Texture2D("prz.bmp"));
	join(walc);
}

ScenaTestTekstur::~ScenaTestTekstur()
{
}
