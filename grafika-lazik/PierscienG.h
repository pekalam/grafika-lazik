#pragma once
#include "SceneObject.h"

class PierscienG : public SceneObject
{
private:
	GLfloat _r;
private:
	GLfloat _h;
	int _sections;
	GLfloat _szer;
protected:
	void drawObject() override;
public:
	PierscienG(GLfloat r, GLfloat h, GLfloat szer, int sections, Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }) 
		: SceneObject(position, rotation), _r(r),_h(h), _szer(szer), _sections(sections) {};
	PierscienG(std::string name, GLfloat r, GLfloat h, GLfloat szer, int sections, Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 })
		: SceneObject(name, position, rotation), _r(r), _h(h), _szer(szer), _sections(sections) {};
public:
	GLfloat r() const
	{
		return _r;
	}

	void r(GLfloat lfloat)
	{
		_r = lfloat;
	}

	GLfloat h() const
	{
		return _h;
	}

	void h(GLfloat lfloat)
	{
		_h = lfloat;
	}

	int sections() const
	{
		return _sections;
	}

	void sections(int sections)
	{
		_sections = sections;
	}

	GLfloat szer() const
	{
		return _szer;
	}

	void szer(GLfloat lfloat)
	{
		_szer = lfloat;
	}
};

