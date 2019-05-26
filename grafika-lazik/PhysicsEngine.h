#pragma once
#include "ViewEngine_defs.h"
#include <memory>

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
	/** Wywo�ywane co okre�lony czas. */
	void update(float dt);
};

