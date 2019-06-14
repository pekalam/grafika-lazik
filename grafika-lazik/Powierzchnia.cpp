#include "stdafx.h"
#include "Powierzchnia.h"
#include <iostream>
#include <string>
#include <istream>
#include <fstream>
//#include "IL/il.h"
//#define TINYOBJLOADER_IMPLEMENTATION
//#include "tiny_obj_loader.h"

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



/*int LoadImage()
{
	ILboolean success;
	ILuint image;

	ilGenImages(1, &image); 
	ilBindImage(image); 
	success = ilLoadImage((wchar_t const*)"C:\\Users\\Marek\\Desktop\\grafika-lazik\\piach.png"); 

	if (success)
	{
		success = ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);

		if (!success)
		{
			return -1;
		}
	}
	else
		return -1;

	return image;
}*/

void Powierzchnia::drawObject()
{

}

Powierzchnia::Powierzchnia(Vector3 position) : SceneObject(position)
{
	getPhysics().setDynamicFrictionCoefficient(0.7);
	setHasPhysics(true);
	setStatic(true);
	isGround(true);
	setBoundingBox(500, 4, 500);
	join(new ScianaG(500, 500, 250, 250, {}, {}, { 0.2656, 0.2109, 0.144 }));



	/*bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, inputfile.c_str());
	if (!warn.empty())
		OutputDebugStringA(warn.c_str());
	if (!err.empty())
		OutputDebugStringA(err.c_str());
	if (!ret)
		throw new std::exception();*/


}

