#include "stdafx.h"
#include "GlownaKamera.h"
#include "KulaG.h"
#include "WalecG.h"
#include "SzescianG.h"
#include "PierscienG.h"
#include "TrapezRownoramiennyG.h"
#include "ScianaG.h"

GlownaKamera::GlownaKamera(Vector3 position, Vector3 rotation) : SceneObject("kamera", position, rotation)
{
	join(new SzescianG("podstawa", 9, 0.3, 5.2, { 0, 0, 0 }, { 0, 0, 0 }, 9, 1, 4, { .289,.289,.289 }));
	auto br1 = new SzescianG("bryla1", 7, 4, 5, { 0, 2.15, 0 }, { 0, 0, 0 }, 7, 4, 5, { 0.19, .63, .92 });
	
	br1->addTexture(nullptr);
	
	br1->addTexture(new Texture2D("kia2.bmp"));
	br1->addTexture(new Texture2D("kia.bmp"));
	
	br1->addTexture(nullptr);
	br1->addTexture(nullptr);
	br1->addTexture(nullptr);
	join(br1);
	join(new PierscienG("ramka-obiektywu", 0.7, 0.2, 0.1, 18, { -1.15, 2.7, -2.6 }));
	join(new SceneObject("brylaboczna-l", { 4, 0.15, 0 }, { 0, 0, 0 }, {
		new TrapezRownoramiennyG("s1", 2, 1, 0.5, false, false, 1, {-.25, 1, 2.5}, {90, 0, 0}),
		new TrapezRownoramiennyG("s2", 2, 1, 0.5, false, false, 1, {-.25, 1, -2.5}, {90, 0, 0}),
		new ScianaG("s3", 0.5, 5, 1, 5, {-.25, 2, 0}),
		new ScianaG("s4", 2.0615, 5, 2, 5, {0.25, 1, 0}, {0, 0, -std::atan(2.0f / 0.5f) * 180.0f / GL_PI}),
		}));
	join(new SceneObject("brylaboczna-r", { -4, 0.15, 0 }, { 0, 0, 0 }, {
		new TrapezRownoramiennyG("s1", 2, 1, 0.5, false, false, 1, {.25, 1, 2.5}, {90, 0, 180}),
		new TrapezRownoramiennyG("s2", 2, 1, 0.5, false, false, 1, {.25, 1, -2.5}, {90, 0, 180}),
		new ScianaG("s3", 0.5, 5, 1, 5, {.25, 2, 0}),
		new ScianaG("s4", 2.0615, 5, 2, 5, {-.25, 1, 0}, {0, 0, std::atan(2.0f / 0.5f) * 180.0f / GL_PI}),
		}));
	join(new WalecG(2, 0.15, { 3, 5.2, 0 }, { 90, 0, 0 }));
	join(new PierscienG(0.1, 0.1, 0.1, 15, { 3, 6.2, 0 }, { 90, 0, 0 }));
	join(new KulaG(0.3, 12, 12, { 3, 6.5, 0 }));
}
