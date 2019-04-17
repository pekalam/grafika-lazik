#pragma once
#include "SceneObject.h"

class WalecG : public SceneObject
{
protected:
	void drawObject() override;
private:
	int _sections;
	GLfloat _r, _wys;
public:
	WalecG(GLfloat wys, GLfloat rad,
		Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }, int sections = 20) : SceneObject(position, rotation), _sections(sections), _wys(wys), _r(rad) {};
	WalecG(std::string name, GLfloat wys, GLfloat rad,
		Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }, int sections = 20) : SceneObject(name, position, rotation), _sections(sections), _wys(wys), _r(rad) {};
};
