#pragma once
#include "SceneObject.h"


typedef std::tuple<std::tuple<bool, Vector3>, Vector3> Collision;

class BoundingBox : public SceneObject
{
public:
	static bool draw;
protected:
	void drawObject() override;
	int length, height, width;
public:
	BoundingBox(Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }, Vector3 color = { 1,1,0 }) : SceneObject(position, rotation, color)
	{
		
	}
	void setSizes(int lenx, int heighty, int widthz)
	{
		if(lenx <= 0 || heighty <= 0 || widthz <= 0)
		{
			throw new std::exception();
		}
		length = lenx/2;
		height = heighty/2;
		width = widthz/2;
	}
	int getLength() { return length; }
	int getWidth() { return width; }
	int getHeight() { return height; }
	void setBoundingBox(int lengthx, int heighty, int widthz)
	{
		throw std::exception("Cannot set bounding box of bounding box");
	}
	static Collision intersects(SceneObject* objectA, SceneObject* objectB, Vector3& dst);
	~BoundingBox();
};

