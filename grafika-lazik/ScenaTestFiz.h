#pragma once
#include "SceneObject.h"
#include "KulaG.h"

class ScenaTestFiz : public SceneObject
{
public:
	ScenaTestFiz();
};

inline ScenaTestFiz::ScenaTestFiz() : SceneObject("scenafiz")
{
	/*auto kula = new KulaG(10, 40, 40, { 0, 50, 0 }, {}, {});
	kula->setHasPhysics(true);
	kula->setBoundingBox(20, 20, 20);
	join(kula);


	auto kula2 = new KulaG("por",10, 40, 40, { -20, 11, 0 }, {}, {});
	kula2->setHasPhysics(true);
	kula2->setBoundingBox(20, 20, 20);
	join(kula2);*/

	join(new Lazik({ 0, 20, 0 }));

	auto ziemia = new ScianaG(500, 500, 25, 25);
	ziemia->getPhysics().setDynamicFrictionCoefficient(0.9);
	ziemia->setBoundingBox(500, 4, 500);
	ziemia->setHasPhysics(true);
	ziemia->setStatic(true);
	join(ziemia);
}

