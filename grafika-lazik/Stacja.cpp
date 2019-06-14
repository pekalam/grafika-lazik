#include "stdafx.h"
#include "Stacja.h"
#include "WalecG.h"
#include "KulaG.h"
#include "SzescianG.h"
#include "TrapezRownoramiennyG.h"
#include "ScianaG.h"
#include "PierscienG.h"

Stacja::Stacja(Vector3 position, Vector3 rotation, Vector3 color) : SceneObject("stacja", position, rotation, {}, color)
{
	setHasPhysics(true);
	setStatic(true);
	setBoundingBox(180, 140, 140);
	//Vector3 pos = { -220, 4, -50 };
	Vector3 pos = { 0, 4, 0 };
	auto podstawa = new WalecG(8, 78, pos, {90, 0, 0});
	podstawa->color({ 0.3984,0.3984,0.3984 });

	
	auto kula = new KulaG(76, 20, 20, { pos.x, 36, pos.z }, {}, { 0,0,1 });
	join(podstawa);
	join(kula);

	auto bok1 = new SceneObject("bok1", {75}, {}, {
		new TrapezRownoramiennyG(20, 20, 10, true, false, 5, {0, 38, 5}, {90, 0, 180}),
		new TrapezRownoramiennyG(20, 20, 10, true, false, 5, { 0, 38, -5 }, { 90, 0, 180 }),
		new ScianaG(10, 10, 1, 1, {0, 38 + 10, 0}),
		new ScianaG(10, 22.36f, 1, 1, {0 + 10, 38}, { 90, std::atan(.5f) * 180.0f / GL_PI, 90}),
		new SzescianG(20, 28, 10, {5, 14})
	});
	auto bok2 = new SceneObject("bok2", { -75 }, {0, 180}, {
		new TrapezRownoramiennyG(20, 20, 10, true, false, 5, {0, 38, 5}, {90, 0, 180}),
		new TrapezRownoramiennyG(20, 20, 10, true, false, 5, { 0, 38, -5 }, { 90, 0, 180 }),
		new ScianaG(10, 10, 1, 1, {0, 38 + 10, 0}),
		new ScianaG(10, 22.36f, 1, 1, {0 + 10, 38}, { 90, std::atan(.5f) * 180.0f / GL_PI, 90}),
		new SzescianG(20, 28, 10, {5, 14})
		});
	auto bok3 = new SceneObject("bok2", { 0,0,-75 }, { 0, 90 }, {
		new TrapezRownoramiennyG(20, 20, 10, true, false, 5, {0, 38, 5}, {90, 0, 180}),
		new TrapezRownoramiennyG(20, 20, 10, true, false, 5, { 0, 38, -5 }, { 90, 0, 180 }),
		new ScianaG(10, 10, 1, 1, {0, 38 + 10, 0}),
		new ScianaG(10, 22.36f, 1, 1, {0 + 10, 38}, { 90, std::atan(.5f) * 180.0f / GL_PI, 90}),
		new SzescianG(20, 28, 10, {5, 14})
		});
	join(bok1);
	join(bok2);
	join(bok3);
	join(new PierscienG(67, 2, 10, 67, {0, 35}, {90}));

}


Stacja::~Stacja()
{
}
