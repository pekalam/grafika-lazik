#pragma once
#include "SceneObject.h"
#include "GlownaKamera.h"
#include "BrylaGlowna.h"
#include "Pojemnik.h"
#include "Rama.h"


class Lazik :
	public SceneObject
{
private:
	float rotStep = 3;
	float velocity = 0;
protected:
	void drawObject() override;
public:
	Lazik(Vector3 position = {0, 0, 0}, Vector3 rotation = {0, -90, 0}) : SceneObject("lazik", position, rotation)
	{
		
		auto kam = new GlownaKamera({ 6, 13.75, -7.5 });
		
		join(new BrylaGlowna());
		join(kam);
		join(new Pojemnik({0,3,17}, {-25, 0,0}));
		SceneObject& rama = join(new Rama());
		rama.positionY(-1.5f);
		positionY(.75+((Rama&)rama).wysokosc()+position.y);

		setStatic(false);
		setHasPhysics(true);
		
		setBoundingBox(24, 12, 24);
	}

	void driveForward(float v);

	void stop();
	bool stopped()
	{
		return getPhysics().getVelocity().x == 0 && getPhysics().getVelocity().z == 0;
	}

	void rotateLeft();

	void rotateRight();
};




