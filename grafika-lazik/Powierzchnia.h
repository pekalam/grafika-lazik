#pragma once
#include "SceneObject.h"
#include "ScianaG.h"
#include "WalecG.h"
#include "KulaG.h"
#include <random>
#include <ctime>

class Powierzchnia :
	public SceneObject
{
protected:
	void drawObject() override
	{

	}

public:
	Powierzchnia();
};

inline Powierzchnia::Powierzchnia()
{
	join(new ScianaG(60, 60, 60, 60));

	int min = 0;
	int max = 58;
	std::random_device generator;
	std::uniform_real<GLfloat> rnd(-58.0f/2, 58.0f/2);
	
	for (int i = 0; i < 100; i++) {
		GLfloat x = rnd(generator);
		GLfloat z = rnd(generator);
	//	join(new KulaG(1, 3, 3, {x ,0.5, z}, { 0,0,0 }, { 0.63f, 0.4726f, 0.2851f }));
	}
}


