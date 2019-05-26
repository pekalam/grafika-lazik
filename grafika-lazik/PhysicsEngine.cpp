#include "stdafx.h"
#include "PhysicsEngine.h"
#include "ViewEngine.h"
#include "BoundingBox.h"



PhysicsEngine::PhysicsEngine(ViewEngine& viewEngine) : viewEngine(viewEngine)
{
	
}

PhysicsEngine::~PhysicsEngine()
{
}

void PhysicsEngine::checkCollisions(SceneObjectList* sceneObjects)
{
	
}

void dynamicFriction()
{
	
}

void PhysicsEngine::update(float dt)
{
	static auto sceneObjects = viewEngine.getNonStaticSceneObjects();
	
	if(sceneObjects != nullptr && sceneObjects->size() > 0)
	{
		for (int i = 0; i < sceneObjects->size(); i++)
		{
			bool grav = true;
			SceneObject& object = sceneObjects->at(i).get();
			if (!object.isStatic() && object._boundingBox){
				object._physics.update(dt);

				for(int j = 0; j < sceneObjects->size(); j++)
				{
					if(i == j)
						continue;
					SceneObject& objectB = sceneObjects->at(j).get();
					Collision collision = object._boundingBox->intersects(&object, &objectB);
					if(std::get<0>(collision))
					{
						// jesli obiekt zderza sie z obiektemB po Y
						if (std::get<1>(collision).y == 1) {

							// tarcie dziala zawsze przeciwnie do kierunku poruszania sie 
							if(object._physics.getVelocity().x > 0)
								object._physics.addDynamicFrictionFrom(objectB.getPhysics(), { -1, 0, 0 });
							else if(object._physics.getVelocity().x < 0)
								object._physics.addDynamicFrictionFrom(objectB.getPhysics(), { 1, 0, 0 });

							if (object._physics.getVelocity().z > 0)
								object._physics.addDynamicFrictionFrom(objectB.getPhysics(), { 0, 0, -1 });
							else if (object._physics.getVelocity().z < 0)
								object._physics.addDynamicFrictionFrom(objectB.getPhysics(), { 0, 0, 1 });

							object._physics.setConstantAcceleration({ 0,0,0 });
							object._physics.setInitialVelocityY(0);
							grav = false;
						}
					}
				}

				if (grav) {
					object._physics.setConstantAcceleration(-PhysicsConfig::Default.g);
				}

				
				auto velocity = object._physics.getVelocity();
				object.translateY(velocity.y);
				object.translateX(velocity.x);
				object.translateZ(velocity.z);
			}
		}
	}
}
