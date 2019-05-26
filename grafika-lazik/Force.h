#pragma once
#include "glm/glm.hpp"

class Force
{
private:
	/** Si³y sk³adowe */
	glm::vec3 N;
public:
	Force(glm::vec3 N);
	~Force();
};

