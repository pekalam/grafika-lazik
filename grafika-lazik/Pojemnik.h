#pragma once
#include "SceneObject.h"
#include "TrapezRownoramiennyG.h"
#include "ScianaG.h"

class Pojemnik : public SceneObject
{
protected:
	void drawObject() override;
public:
	Pojemnik(Vector3 position = {0,0,0}, Vector3 rotation = {0,0,0}) : SceneObject("pojemnik", position, rotation)
	{
		join(new TrapezRownoramiennyG(3.5, 11, 9, true, true, 5, {0,0,3.75}, {-90,0,0}));
		join(new TrapezRownoramiennyG(3.5, 11, 9, true, true, 5, { 0,0,-3.75 }, { -90,0,0 }));
		join(new ScianaG(std::sqrt(3.5*3.5 + 4),7.5, std::sqrt(3.5*3.5 + 4), 7.5, { 5.5,0,0 }, { 0,0,60 }));
		join(new ScianaG(std::sqrt(3.5*3.5 + 4), 7.5, std::sqrt(3.5*3.5 + 4), 7.5, { -5.5,0,0 }, { 0,0,-60 }));
		join(new ScianaG(6.5, 7.5, 5, 7, { 3.25,1.75,0 }, {0,0,0}, {0,1,0}));
		join(new ScianaG(6.5, 7.5, 5, 7, { -3.25,1.75,0 }, {0,0,0}, {0,0,1}));
	}
};

inline void Pojemnik::drawObject()
{
}