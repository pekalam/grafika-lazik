#pragma once
#include "SceneObject.h"
#include "SzescianG.h"
#include "ScianaG.h"
#include "TrapezRownoramiennyG.h"

class BrylaGlowna : public SceneObject
{
protected:
	void drawObject() override;
public:
	BrylaGlowna(Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }, std::vector<SceneObject*> children = {}, Vector3 color = { 0,0,0 }) : SceneObject("bryla-glowna",position, rotation, children, color)
	{
		join(new SzescianG("bryla-glowna-cz1", 15, 6, 20, { 0,0,0 }, { 0,0,0 }, 15, 6, 20, { 0.1875f, 0.218f, 0.4179f }));
		join(new SceneObject("bryla-glowna-cz2", { 0, 0, 10 }, { 0,0,0 }, {
			new ScianaG("bryla-glowna-cz2-1", 15, 3, 15, 3, {0, 3, 1.5}),
			new TrapezRownoramiennyG("bryla-glowna-cz2-2", 3, 6, 4, true, false, 4, {7.5,1,1.5}, {0,180,90}, {1,1,0}),
			new TrapezRownoramiennyG("bryla-glowna-cz2-3", 3, 6, 4, true, false, 4, {-7.5,1,1.5}, {0,180,90}, {1,1,0}),
			new ScianaG("bryla-glowna-cz2-4", 15, std::sqrt(3 * 3 + 2 * 2), 15, 3, {0, -2, 1.5}, {-33.691,0,0}, {0,0,0}),
			new ScianaG("bryla-glowna-cz2-5", 11, 4, 11, 4, {0, 1, 3}, {90,0,0}, {0.2,0.7,0.7}),
			new TrapezRownoramiennyG("bryla-glowna-cz2-6", 3, 4, 2, true, false, 4, {7.5,2,4.5}, {0,180,90}),
			new TrapezRownoramiennyG("bryla-glowna-cz2-6", 3, 4, 2, true, false, 4, {-7.5,2,4.5}, {0,180,90}),
			new TrapezRownoramiennyG("bryla-glowna-cz2-7", 3, 4, 2, true, false, 4, {5.5,2,4.5}, {0,180,90}),
			new TrapezRownoramiennyG("bryla-glowna-cz2-8", 3, 4, 2, true, false, 4, {-5.5,2,4.5}, {0,180,90}),
			new ScianaG("bryla-glowna-cz9", 2, 3, 2, 4, {6.5,3,4.5}, {0,0,0}),
			new ScianaG("bryla-glowna-cz10", 2, 3, 2, 4, {-6.5,3,4.5}, {0,0,0}),
			new ScianaG("bryla-glowna-cz2-11", 2, std::sqrt(3 * 3 + 2 * 2), 2, 3, {-6.5,0,4.5}, {-33.691f,0,0}, {1,1,0}),
			new ScianaG("bryla-glowna-cz2-12", 2, std::sqrt(3 * 3 + 2 * 2), 2, 3, {6.5,0,4.5}, {-33.691f,0,0}, {1,1,0}),
			new ScianaG("bryla-glowna-cz2-13", 2, 2, 2, 2, {-6.5,2,6}, {90,0,0}, {0,0,1}),
			new ScianaG("bryla-glowna-cz2-14", 2, 2, 2, 2, {6.5,2,6}, {90,0,0}, {0,0,1})
		}));
		join(new SceneObject("szyja", { 6,8,-7.5 }, { 90,0,0 }, {
			new WalecG(10, 0.5, {0,0,0},{0,0,0}),
			new PierscienG(0.5,0.12,0.5,20.0,{0.0,0.0,-4.5},{0,0,0},{0,0,0}),
			new PierscienG(0.5,0.25,0.5,20.0,{0.0,0.0,-4.0},{0,0,0},{0,0,0}),
			new SzescianG(2.0,0.5,0.5,{0.25,0,-5.25},{0,0,90}),
			new WalecG(1,0.25,{-0.5,0,-5.25},{90,90,0})
			}));
	};
};

inline void BrylaGlowna::drawObject()
{
	
}

