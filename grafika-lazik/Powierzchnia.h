#pragma once
#include "SceneObject.h"
#include "ScianaG.h"
#include "WalecG.h"
#include "KulaG.h"
#include <random>
#include <ctime>
#include "tiny_obj_loader.h"



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
	std::string inputfile = "C:\\Users\\Marek\\Desktop\\grafika-lazik\\landscape1.obj";

	std::string warn;
	std::string err;
	tinyobj::attrib_t attrib;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;
protected:
	void drawObject();

public:
	Powierzchnia(Vector3 position = {0,0,0});
};


