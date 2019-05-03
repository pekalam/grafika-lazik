#pragma once
#include "Vector3.h"
#include <vector>
#include "SceneObject.h"
#include "FastNoise.h"

class Icosphere42 : public SceneObject
{
public:
	Icosphere42(GLfloat r = 1, Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }, Vector3 color = { 0,1,0 });
protected:
	void drawObject() override;
public:
	std::vector<float> verticesX;
	std::vector<float> verticesY;
	std::vector<float> verticesZ;
private:
	inline void _initVertices();
	static std::vector<Vector3> indices;
	GLfloat r;
};

