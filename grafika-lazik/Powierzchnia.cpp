#include "stdafx.h"
#include "Powierzchnia.h"
#include <iostream>
#include <string>
#include <istream>
#include <sstream>
#include <fstream>

int read_binary_STL_file(std::string STL_filename, std::vector<triangle> & facet)
{
	std::ifstream file;

	file.open(STL_filename.c_str(), std::ifstream::in | std::ifstream::binary);

	if (file.fail())
	{
		std::cout << "ERROR: Input STL file could not be opened!" << std::endl;
		return (1);
	}

	file.seekg(80);

	int numberOfTriangles;
	file.read((char*)&numberOfTriangles, sizeof(int));

	triangle tri;

	char unused_bytes[2];

	float temp_float_var;

	for (int count = 0; count < numberOfTriangles; count++)
	{

		file.read((char*)&temp_float_var, 4); tri.normal.x = (double)temp_float_var;
		file.read((char*)&temp_float_var, 4); tri.normal.y = (double)temp_float_var;
		file.read((char*)&temp_float_var, 4); tri.normal.z = (double)temp_float_var;


		file.read((char*)&temp_float_var, 4); tri.point.x = (double)temp_float_var;
		file.read((char*)&temp_float_var, 4); tri.point.y = (double)temp_float_var;
		file.read((char*)&temp_float_var, 4); tri.point.z = (double)temp_float_var;


		file.read((char*)&temp_float_var, 4); tri.point.x = (double)temp_float_var;
		file.read((char*)&temp_float_var, 4); tri.point.y = (double)temp_float_var;
		file.read((char*)&temp_float_var, 4); tri.point.z = (double)temp_float_var;


		file.read((char*)&temp_float_var, 4); tri.point.x = (double)temp_float_var;
		file.read((char*)&temp_float_var, 4); tri.point.y = (double)temp_float_var;
		file.read((char*)&temp_float_var, 4); tri.point.z = (double)temp_float_var;


		file.read(unused_bytes, 2);

		facet.push_back(tri);
	}

	file.close();
}

void Powierzchnia::drawObject()
{
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.593, 0.3906, 0.1953);
	for (int i = 0; i < triangles->size(); i++)
	{
		glVertex3f(triangles->at(i).point.x, triangles->at(i).point.y, triangles->at(i).point.z);
	}
	glEnd();
}

Powierzchnia::Powierzchnia(Vector3 position) : SceneObject(position)
{
	triangles = new std::vector<triangle>();
	read_binary_STL_file("C:\\Users\\Marek\\Desktop\\grafika-lazik\\landscape.stl", *triangles);
}

