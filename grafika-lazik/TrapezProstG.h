#pragma once
#include "SceneObject.h"

/*         b
	|============\ 
	| h   	      \
    |==============\
			a
 */
class TrapezProstG : public SceneObject
{
private:
	GLfloat _h;
	GLfloat _a;
	GLfloat _b;
	int _sectorsX, _sectorsY;
protected:
	void drawObject() override;
public:
	TrapezProstG(GLfloat h, GLfloat a, GLfloat b, int sectorsX, int sectorsY, Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }) 
		: SceneObject(position, rotation), _h(h), _a(a), _b(b), _sectorsX(sectorsX), _sectorsY(sectorsY) {};
	TrapezProstG(std::string name, GLfloat h, GLfloat a, GLfloat b, int sectorsX, int sectorsY, Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 })
		: SceneObject(name, position, rotation), _h(h), _a(a), _b(b), _sectorsX(sectorsX), _sectorsY(sectorsY) {};
};

