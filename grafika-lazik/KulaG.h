#pragma once
#include "Vector3.h"
#include "SceneObject.h"

class KulaG : public SceneObject
{
private:
	float _stacks, _sectors;
	GLfloat _R;
	Vector3 fKula2(GLfloat sec, GLfloat sta, GLfloat r);
public:
	int stacks() const
	{
		return _stacks;
	}
	void stacks(int stacks)
	{
		_stacks = stacks;
	}
	int sectors() const
	{
		return _sectors;
	}
	void sectors(int sectors)
	{
		_sectors = sectors;
	}
	GLfloat R() const
	{
		return _R;
	}
	GLfloat R(GLfloat R)
	{
		_R = R;
	}
protected:
	void drawObject() override;
public:
	KulaG(std::string name, GLfloat r, int stacks, int sectors, Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }, Vector3 color = { 0,0,0 }) : SceneObject(name, position, rotation, {}, color), _stacks(stacks), _sectors(sectors), _R(r) {};
	KulaG(GLfloat r, int stacks, int sectors, Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }, Vector3 color = { 0,0,0 }) 
		: SceneObject(position, rotation, color, 0.1f), _stacks(stacks), _sectors(sectors), _R(r) {};
};

