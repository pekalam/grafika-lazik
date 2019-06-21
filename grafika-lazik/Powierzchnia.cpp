#include "stdafx.h"
#include "Powierzchnia.h"
#include <iostream>
#include <string>
#include <istream>
#include <fstream>
//#include "IL/il.h"
#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"

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
	glBegin(GL_TRIANGLES);
	for (size_t s = 0; s < shapes1.size(); s++) {
		// Loop over faces(polygon)
		size_t index_offset = 0;
		for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
			int fv = shapes[s].mesh.num_face_vertices[f];
			
			// Loop over vertices in the face.
			for (size_t v = 0; v < fv; v++) {
				// access to vertex
				tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
				tinyobj::real_t vx = attrib.vertices[3 * idx.vertex_index + 0];
				tinyobj::real_t vy = attrib.vertices[3 * idx.vertex_index + 1];
				tinyobj::real_t vz = attrib.vertices[3 * idx.vertex_index + 2];
				/*tinyobj::real_t nx = attrib.normals[3 * idx.normal_index + 0];
				tinyobj::real_t ny = attrib.normals[3 * idx.normal_index + 1];
				tinyobj::real_t nz = attrib.normals[3 * idx.normal_index + 2];*/
				tinyobj::real_t tx = attrib.texcoords[2 * idx.texcoord_index + 0];
				tinyobj::real_t ty = attrib.texcoords[2 * idx.texcoord_index + 1];

				TEXTURE2D(tx, ty);
				glVertex3f(vx, vy+_position.y, vz);
				// Optional: vertex colors
				// tinyobj::real_t red = attrib.colors[3*idx.vertex_index+0];
				// tinyobj::real_t green = attrib.colors[3*idx.vertex_index+1];
				// tinyobj::real_t blue = attrib.colors[3*idx.vertex_index+2];
			}
			
			index_offset += fv;

			// per-face material
			//shapes[s].mesh.material_ids[f];
		}
	}
	glEnd();
}

Powierzchnia::Powierzchnia(Vector3 position) : SceneObject(position)
{
	getPhysics().setDynamicFrictionCoefficient(0.7);
	setHasPhysics(true);
	setStatic(true);
	isGround(true);
	setBoundingBox(500, 4, 500);
	//join(new ScianaG(500, 500, 250, 250, {}, {}, { 0.2656, 0.2109, 0.144 }));



	bool ret = tinyobj::LoadObj(&attrib, &shapes1, &materials, &warn, &err, inputfile.c_str());
	shapes = new tinyobj::shape_t[shapes1.size()];
	std::copy(shapes1.begin(), shapes1.end(), shapes);

	if (!warn.empty())
		OutputDebugStringA(warn.c_str());
	if (!err.empty())
		OutputDebugStringA(err.c_str());
	if (!ret)
		throw new std::exception();


}

