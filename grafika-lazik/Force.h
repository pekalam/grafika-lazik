#pragma once
#include "glm/glm.hpp"

class Force
{
private:
	/** Si�y sk�adowe */
	glm::vec3 N;
public:
	Force(glm::vec3 N);
	~Force();
};

