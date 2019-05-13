#include "stdafx.h"
#include "Kamien.h"
#include <random>


Kamien::Kamien(GLfloat r, Vector3 position, Vector3 rotation, Vector3 color) : Icosphere42(r, position, rotation, color)
{
	std::random_device rd;
	std::mt19937 e2(rd());
	std::uniform_real_distribution<> dist(1234, 2000000);
	noise.SetNoiseType(FastNoise::Perlin);
	noise.SetSeed(dist(e2));
	noise.SetFrequency(0.009);
	for(int x = 0; x < 42; x++)
	{
		auto nval = noise.GetNoise(1, x);
	
		verticesX[x] *= nval;
		verticesY[x] *= nval;
		verticesZ[x] *= nval;
	}

	float maxY = *std::max_element(verticesY, verticesY + 80);
	float minY = *std::min_element(verticesY, verticesY + 80);
	if(minY * r < 0)
	{
		_position.y += -minY/2 * r;
	}
}

Kamien::~Kamien()
{
}
