#pragma once
#include "SceneObject.h"
#include "Icosphere42.h"

class Kamien :
	public Icosphere42
{
private:
	FastNoise noise;
public:
	Kamien(GLfloat r, Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }, Vector3 color = { 0,1,0 });
	~Kamien();
};

