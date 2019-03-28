#pragma once
#include "SceneObject.h"
#include "SzescianG.h"
#include "ViewEngine.h"
#include "PierscienG.h"

class GlownaKamera : public SceneObject
{
protected:
	void drawObject() override;
public:
	GlownaKamera(Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }) : SceneObject("kamera", position, rotation)
	{
		join(new SzescianG("podstawa", 18, 0.5, 11, { 0,0,0 }, { 0,0,0 }, 0.5));
		join(new SzescianG("bryla1", 15, 10, 10, { 0,5.25f,0 }, { 0,0,0 }));
		join(new PierscienG("ramka-obiektywu",1.7, 0.5, 0.2, 8, {-4.0, 6.5f, -5.2}));
		join(new SzescianG("brylaboczna-l", 1.5, 5.5, 10, { 8.25,3.0f,0 }, { 0,0,0 }, 0.5));
		join(new SzescianG("brylaboczna-r", 1.5, 5.5, 10, { -8.25,3.0f,0 }, { 0,0,0 }, 0.5));
	};
};

inline void GlownaKamera::drawObject()
{

}