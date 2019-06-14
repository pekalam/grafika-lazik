#pragma once
#include "glm/glm.hpp"
#include "glm/ext.hpp"
#include "PhysicsConfig.h"


class Physics
{
private:
	/** Masa w kg */
	float m;
	glm::vec3 a = { 0,0,0 };
	const PhysicsConfig &config;
	glm::vec3 v0 = { 0,0,0 };
	glm::vec3 vConst = { 0,0,0 };
	glm::vec3 aConst = { 0,0,0 };

	float dynFrictionCoeff = 0;
	//na podstawie innych wartosci
	glm::vec3 v = { 0,0,0 };

	glm::vec3 aFriction = { 0,0,0 };

	inline void friction(float dt);
public:
	Physics(const PhysicsConfig& config, float m);
	float getAcceleration();
	float setAcceleration(float a);
	/** Masa w kg */
	float getMass();
	/** Zmiana masy m[kg] */
	void setMass(float new_m)
	{
		m = new_m;
	}
	void addAcceleration(const glm::vec3& acceleration)
	{
		a += acceleration;
	}
	void setDynamicFrictionCoefficient(float u){dynFrictionCoeff = u;}
	float getDynamicFrictionCoefficient(){return dynFrictionCoeff;}
	void setAcceleration(const glm::vec3& acceleration){a = acceleration;}
	void setConstantAcceleration(const glm::vec3& acceleration){aConst = acceleration;}
	void setConstantAccelerationX(float x){aConst.x = x;}
	void setConstantAccelerationZ(float z){aConst.z = z;}
	void setConstantAccelerationY(float y){aConst.y = y;}

	glm::vec3 getConstantVelocity() { return vConst; }
	void setConstantVelocity(const glm::vec3& velocity){vConst = velocity;}
	void setConstantVelocityX(float x) { vConst.x = x; }
	void setConstantVelocityY(float y) { vConst.y = y; }
	void setConstantVelocityZ(float z) { vConst.z = z; }

	glm::vec3 getInitialVelocity(){return v0;}
	void setInitialVelocity(const glm::vec3& velocity){v0 = velocity;}
	void setInitialVelocityX(float x) { v0.x = x; }
	void setInitialVelocityY(float y) { v0.y = y; }
	void setInitialVelocityZ(float z) { v0.z = z; }

	void addDynamicFrictionFrom(Physics& ph, glm::vec3 dir)
	{
		//jezeli obiekt porusza sie wystepuje tarcie dynamiczne
		auto norm = glm::normalize(v);
		aFriction.x += dir.x * abs(norm.x) * PhysicsConfig::Default.g.y * ph.getDynamicFrictionCoefficient();
		aFriction.y += dir.y * abs(norm.y) * PhysicsConfig::Default.g.y * ph.getDynamicFrictionCoefficient();
		aFriction.z += dir.z * abs(norm.z) * PhysicsConfig::Default.g.y * ph.getDynamicFrictionCoefficient();
	}
	void addForce(const glm::vec3& force)
	{
		// a = F/m
		a += force / m;
	}


	void update(float dt);

	glm::vec3 getVelocity()
	{
		return v;
	}


	void rotateYV0(float rot);

	void rotateYVconst(float rot);


};

