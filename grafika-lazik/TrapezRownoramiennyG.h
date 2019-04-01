#pragma once
#include "SceneObject.h"

/*         b
	|============\ 
	| h   	      \
    |==============\
			a
 */
class TrapezRownoramiennyG : public SceneObject
{
private:
	GLfloat _h;
	GLfloat _a;
	GLfloat _b;
	int _sectorsX, _sectorsY;
	bool _pr; //trojkat po lewej czy po prawej
	bool _two; //czy 2 trojkaty
protected:
	void drawObject() override;
public:
	TrapezRownoramiennyG(GLfloat h, GLfloat a, GLfloat b, bool pr, bool two, int sectors, Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 })
		: SceneObject(position, rotation), _h(h), _a(a), _b(b), _sectorsX(sectors), _sectorsY(sectors), _pr(pr), _two(two) {};
	TrapezRownoramiennyG(std::string name, GLfloat h, GLfloat a, GLfloat b, bool pr, bool two, int sectors, Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 })
		: SceneObject(name, position, rotation), _h(h), _a(a), _b(b), _sectorsX(sectors), _sectorsY(sectors), _pr(pr), _two(two) {};
};

