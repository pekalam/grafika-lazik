#include "stdafx.h"
#include "Physics.h"
#include "glm/glm.hpp"
#include "glm/gtx/rotate_vector.inl"

Physics::Physics(const PhysicsConfig& config, float m) : config(config), m(m)
{
}

void Physics::friction(float dt)
{
	if (v.x >= 0 && v.x + aFriction.x * dt < 0)
	{
		v.x = 0;
		a.x = 0;
		v0.x = 0;
	}
	else if (v.x <= 0 && v.x + aFriction.x * dt > 0)
	{
		v.x = 0;
		a.x = 0;
		v0.x = 0;
	}
	else
		v.x += aFriction.x * dt;

	if (v.z >= 0 && v.z + aFriction.z * dt < 0)
	{
		v.z = 0;
		a.z = 0;
		v0.z = 0;
	}
	else if (v.z <= 0 && v.z + aFriction.z * dt > 0)
	{
		v.z = 0;
		a.z = 0;
		v0.z = 0;
	}
	else
		v.z += aFriction.z * dt;
}



void Physics::update(float dt)
{
	v = v0 + (a + aConst) * dt;
	friction(dt);
	v0 = v;
	v += vConst;
	//zatrzymanie obiektu pod wplywem tarcia


	aFriction.x = 0;
	aFriction.z = 0;
}

void Physics::rotateYV0(float rot)
{
	v0 = glm::rotateY(v0, rot);
}

void Physics::rotateYVconst(float rot)
{
	vConst = glm::rotateY(vConst, rot);
}
