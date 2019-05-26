#include "stdafx.h"
#include "Lazik.h"

void Lazik::drawObject()
{

}

void Lazik::driveForward(float v)
{
	velocity = v;
	getPhysics().setConstantVelocity({ 0, 0, -v });
	getPhysics().rotateYVconst(_rotation.y * GL_PI / 180.0f);
}

void Lazik::stop()
{
	auto vConst = getPhysics().getConstantVelocity();
	getPhysics().setInitialVelocity(vConst);
	getPhysics().setConstantVelocity({ 0, 0, 0 });
}

void Lazik::rotateLeft()
{
	rotateY(_rotation.y + rotStep);
	getPhysics().rotateYVconst(rotStep * GL_PI / 180.0f);
}

void Lazik::rotateRight()
{
	rotateY(_rotation.y - rotStep);
	getPhysics().rotateYVconst(-rotStep * GL_PI / 180.0f);
}