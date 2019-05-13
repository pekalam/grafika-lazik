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
	join(new ScianaG(500, 500, 50, 50, {}, {}, {1,1,1}));
}


