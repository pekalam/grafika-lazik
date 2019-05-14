#pragma once
#include "SceneObject.h"
#include "ScianaG.h"
#include "WalecG.h"
#include "KulaG.h"
#include <random>
#include <ctime>

struct triangle
{
	Vector3 point;
	Vector3 normal;
};

class Powierzchnia :
	public SceneObject
{
private:
	std::vector<triangle>* triangles;
protected:
	void drawObject();

public:
	Powierzchnia(Vector3 position = {0,0,0});
};

/*inline Powierzchnia::Powierzchnia()
{
	//join(new ScianaG(500, 500, 50, 50, {}, {}, {1,1,1}));
}*/


