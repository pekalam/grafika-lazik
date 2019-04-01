#pragma once
#include "SceneObject.h"
#include "SzescianG.h"
#include "ViewEngine.h"
#include "PierscienG.h"
#include "ScianaG.h"
#include "TrapezRownoramiennyG.h"

class GlownaKamera : public SceneObject
{
protected:
	void drawObject() override;
public:
	GlownaKamera(Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }) : SceneObject("kamera", position, rotation)
	{
		join(new SzescianG("podstawa", 9, 0.3, 5.2, { 0,0,0 }, { 0,0,0 }, 9, 1, 4, {0.94, 0.23, 0.70}));
		join(new SzescianG("bryla1", 7, 4, 5, { 0, 2.15,0 }, { 0,0,0 }, 7, 4, 5, {0.19, .63, .92}));
		join(new PierscienG("ramka-obiektywu", 0.7, 0.2, 0.1, 9, {-1.5, 2.7, -2.6}));
		join(new SceneObject("brylaboczna-l", { 4,0.15,0 }, { 0,0,0 }, {
			new TrapezRownoramiennyG("s1", 2, 1, 0.5, false, false, 1, {-.25,1,2.5}, {90,0,0}),
			new TrapezRownoramiennyG("s2", 2, 1, 0.5, false, false, 1, {-.25,1,-2.5}, {90,0,0}),
			new ScianaG("s3", 0.5, 5, 1, 5, {-.25,2,0}),
			new ScianaG("s4", 2.0615, 5, 2, 5, {0.25,1,0}, {0,0, -std::atan(2.0f/0.5f) * 180.0f / GL_PI}),
		}));
		join(new SceneObject("brylaboczna-r", { -4,0.15,0 }, { 0,0,0 }, {
			new TrapezRownoramiennyG("s1", 2, 1, 0.5,false, false, 1, {.25,1,2.5}, {90,0,180}),
			new TrapezRownoramiennyG("s2", 2, 1, 0.5,false, false, 1, {.25,1,-2.5}, {90,0,180}),
			new ScianaG("s3", 0.5, 5, 1, 5, {.25,2,0}),
			new ScianaG("s4", 2.0615, 5, 2, 5, {-.25,1,0}, {0, 0, std::atan(2.0f / 0.5f) * 180.0f / GL_PI}),
		}));
		//join(new SzescianG("brylaboczna-l", 1, 2, 5, { 4, 1.15,0 }, { 0,0,0 }, 1, 2, 5));
		//join(new SzescianG("brylaboczna-r", 1, 2, 5, { -4, 1.15,0 }, { 0,0,0 }, 1, 2, 5));
	};
};

inline void GlownaKamera::drawObject()
{

}