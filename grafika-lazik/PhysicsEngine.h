#pragma once
#include "ViewEngine_defs.h"

class ViewEngine;


class PhysicsEngine
{
private:
	bool _initialized = false;
	ViewEngine &viewEngine;
	void checkCollisions(SceneObjectList* sceneObjects);
public:
	PhysicsEngine(ViewEngine &viewEngine);
	~PhysicsEngine();
	/** Wywoływane co określony czas. */
	void update(float dt);
};

