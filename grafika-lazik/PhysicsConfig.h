#pragma once
#include "glm/glm.hpp"

class PhysicsConfig
{
public:
	static PhysicsConfig Default;
	glm::vec3 g;
	float airFrictionCoeff;
	PhysicsConfig(glm::vec3 g = { 0, 9.80665f, 0 }, float airFricCoef = 12) : g(g), airFrictionCoeff(airFricCoef)
	{
		
	}
};

