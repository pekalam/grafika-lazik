#include "stdafx.h"
#include "Pojemnik.h"
#include "ScianaG.h"
#include "TrapezRownoramiennyG.h"

Pojemnik::Pojemnik(Vector3 position, Vector3 rotation) : SceneObject("pojemnik", position, rotation)
{
	join(new TrapezRownoramiennyG(3.5, 11, 9, true, true, 5, { 0, 0, 3.75 }, { 90, 180, 0 }));
	join(new TrapezRownoramiennyG(3.5, 11, 9, true, true, 5, { 0, 0, -3.75 }, { 90, 180, 0 }));
	join(new ScianaG(std::sqrt(3.5 * 3.5 + 4), 7.5, std::sqrt(3.5 * 3.5 + 4), 7.5, { -5.5, 0, 0 }, { 0, 0, -60.255f }));
	join(new ScianaG(std::sqrt(3.5 * 3.5 + 4), 7.5, std::sqrt(3.5 * 3.5 + 4), 7.5, { 5.5, 0, 0 }, { 0, 0, 60.255f }));
	join(new ScianaG(6.5, 7.5, 5, 7, { 3.25, 1.75, 0 }, { 0, 0, 180 }, { 0, 0, 0.8f }));
	join(new ScianaG(6.5, 7.5, 5, 7, { -3.25, 1.75, 0 }, { 0, 0, 180 }, { 0, 0, 0.7f }));
	join(new ScianaG(9, 7.5, 5, 7, { 0, -1.75, 0 }, { 0, 0, 0 }, { 0, 0, 1 }));
}
