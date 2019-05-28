#pragma once
#include "SceneObject.h"
#include "KulaG.h"
#include "PierscienG.h"
#include "SzescianG.h"
#include "WalecG.h"
#include "Stacja.h"
#include "ScianaG.h"
#include "Lazik.h"

class ScenaTestowa : public SceneObject
{
public:
	ScenaTestowa();
};

inline ScenaTestowa::ScenaTestowa() : SceneObject("scenatest")
{
	//join(new KulaG("kulka",5, 10, 10, { 0,10, 0 }));
	//join(new PierscienG("PIER", 10, 5, 0.5, 10, {10, 0,0}));
	//join(new SzescianG("chu", 4, 4, 4));
	//join(new WalecG(5, 5));
	//auto stacja = new Stacja();
	//join(stacja);
	join(new Lazik());
	//join(new ScianaG(10, 10, 10, 10));
}
