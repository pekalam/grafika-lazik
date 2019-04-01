#pragma once
#include "SceneObject.h"
#include "SzescianG.h"

class BrylaGlowna : public SceneObject
{
protected:
	void drawObject() override;
public:
	BrylaGlowna(Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }, std::vector<SceneObject*> children = {}, Vector3 color = { 0,0,0 }) : SceneObject("bryla-glowna",position, rotation, children, color)
	{
		join(new SzescianG("bryla-glowna-cz1", 15, 6, 20, { 0,0,0 }, { 0,0,0 }, 15, 6, 20, { 0.5, 1.0f, 0.5 }));
	};
};

inline void BrylaGlowna::drawObject()
{
	
}

