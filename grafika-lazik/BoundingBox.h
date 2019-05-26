#pragma once
#include "SceneObject.h"

typedef std::tuple<bool, glm::vec3> Collision;

class BoundingBox : public SceneObject
{
protected:
	void drawObject() override;
	int length, height, width;
public:
	BoundingBox(Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }, Vector3 color = { 1,1,0 }) : SceneObject(position, rotation, color)
	{
		
	}
	void setSizes(int lenx, int heighty, int widthz)
	{
		length = lenx/2;
		height = heighty/2;
		width = widthz/2;
	}
	void setBoundingBox(int lengthx, int heighty, int widthz)
	{
		throw std::exception("Cannot set bounding box of bounding box");
	}
	static Collision intersects(SceneObject* objectA, SceneObject* objectB);
	~BoundingBox();
};

