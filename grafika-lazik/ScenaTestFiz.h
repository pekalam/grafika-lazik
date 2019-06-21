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
	auto kula = new KulaG("l1",10, 40, 40, { 20, 200, 0 }, {}, {});
	kula->setHasPhysics(true);
	kula->setBoundingBox(20, 20, 20);
	join(kula);


	auto kula2 = new KulaG("l2",10, 40, 40, { -25, 11, 0 }, {}, {});
	kula2->setHasPhysics(true);
	kula2->setBoundingBox(20, 20, 20);
	//kula2->getPhysics().setConstantAcceleration({ 0.5,0,0 });
	join(kula2);

	auto kula3 = new KulaG("l3", 10, 40, 40, { 20, 11, 0 }, {}, {});
	kula3->setHasPhysics(true);
	kula3->setBoundingBox(20, 20, 20);
	//kula3->getPhysics().setConstantAcceleration({ -0.5,0,0 });
	join(kula3);

	auto ziemia = new ScianaG(500, 500, 25, 25, {}, {}, {1,1,1});
	ziemia->getPhysics().setDynamicFrictionCoefficient(0.001);
	ziemia->setBoundingBox(500, 10, 500);
	ziemia->setHasPhysics(true);
	ziemia->setStatic(true);
	ziemia->isGround(true);
	join(ziemia);
}

