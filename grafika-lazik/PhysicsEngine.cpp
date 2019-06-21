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
	auto sceneObjects = viewEngine.getNonStaticSceneObjects();
	
	if(sceneObjects != nullptr && sceneObjects->size() > 0)
	{
		for (int i = 0; i < sceneObjects->size(); i++)
		{
			bool grav = true;
			SceneObject& object = sceneObjects->at(i).get();
			if (!object.isStatic() && object._boundingBox){
				object._physics.update(dt);
				auto velocity = object._physics.getVelocity();

				for(int j = 0; j < sceneObjects->size(); j++)
				{
					if(i == j)
						continue;
					SceneObject& objectB = sceneObjects->at(j).get();
					Vector3 dst;
					Collision collision = object._boundingBox->intersects(&object, &objectB, dst);

					if(std::get<0>(std::get<0>(collision)))
					{
						

						
						// jesli obiekt zderza sie z obiektemB po Y
						if (std::get<1>(collision).y == 1) {

							if (std::get<1>(std::get<0>(collision)).y)
							{
								GLfloat pos = object._position.y + std::get<1>(std::get<0>(collision)).y;
								object.positionY(pos);
							}

							// tarcie
							if (objectB.isGround()) {
								if (object._physics.getVelocity().x > 0)
									object._physics.addDynamicFrictionFrom(objectB.getPhysics(), { -1, 0, 0 });
								else if (object._physics.getVelocity().x < 0)
									object._physics.addDynamicFrictionFrom(objectB.getPhysics(), { 1, 0, 0 });

								if (object._physics.getVelocity().z > 0)
									object._physics.addDynamicFrictionFrom(objectB.getPhysics(), { 0, 0, -1 });
								else if (object._physics.getVelocity().z < 0)
									object._physics.addDynamicFrictionFrom(objectB.getPhysics(), { 0, 0, 1 });
							}
							object._physics.setConstantAccelerationY(0);
							object._physics.setInitialVelocityY(0);
							object._physics.setConstantVelocityY(0);
							grav = false;
						}

					}
					if (grav) {
						object._physics.setConstantAcceleration(-PhysicsConfig::Default.g);
					}

					if (velocity.x != 0 || velocity.z != 0)
					{
						object.translateY(velocity.y);
						object.translateX(velocity.x);
						object.translateZ(velocity.z);
						Vector3 dst2;
						auto collision2 = object._boundingBox->intersects(&object, &objectB, dst2);
						object.translateY(-velocity.y);
						object.translateX(-velocity.x);
						object.translateZ(-velocity.z);
						if (!std::get<0>(std::get<0>(collision2)))
						{
							continue;
						}
					}
					if (std::get<1>(collision).x == 1 || std::get<1>(collision).x == -1)
					{

						if (!objectB.isGround()) {
							


							object._physics.setConstantAccelerationX(0);
							object._physics.setInitialVelocityX(0);
							object._physics.setConstantAccelerationX(0);
							object._physics.setConstantVelocityX(0);
						}

					}
					if (std::get<1>(collision).z == 1 || std::get<1>(collision).z == -1)
					{

						if (!objectB.isGround()) {
							
							object._physics.setConstantAccelerationZ(0);
							object._physics.setInitialVelocityZ(0);
							object._physics.setConstantAccelerationZ(0);
							object._physics.setConstantVelocityZ(0);
						}
					}
				}

				

				
				
				object.translateY(velocity.y);
				object.translateX(velocity.x);
				object.translateZ(velocity.z);
			}
		}
	}
}
