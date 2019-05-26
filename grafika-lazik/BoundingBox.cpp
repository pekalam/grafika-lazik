#include "stdafx.h"
#include "BoundingBox.h"


void BoundingBox::drawObject()
{
	glBegin(GL_LINES);
	glVertex3f(-length, -height, width);
	glVertex3f(length, -height, width);
	glVertex3f(-length, height, width);
	glVertex3f(length, height, width);

	glVertex3f(-length, -height, -width);
	glVertex3f(length, -height, -width);
	glVertex3f(-length, height, -width);
	glVertex3f(length, height, -width);

	glVertex3f(length, -height, -width);
	glVertex3f(length, height, -width);
	glVertex3f(length, -height, width);
	glVertex3f(length, height, width);

	glVertex3f(-length, -height, -width);
	glVertex3f(-length, height, -width);
	glVertex3f(-length, -height, width);
	glVertex3f(-length, height, width);

	glVertex3f(-length, height, -width);
	glVertex3f(-length, height, width);
	glVertex3f(length, height, -width);
	glVertex3f(length, height, width);

	glVertex3f(-length, -height, -width);
	glVertex3f(-length, -height, width);
	glVertex3f(length, -height, -width);
	glVertex3f(length, -height, width);
	glEnd();

}

Collision BoundingBox::intersects(SceneObject* objectA, SceneObject* objectB)
{
	auto colliding = false;
	glm::vec3 coldir{ 0,0,0 };

	auto aBox = objectA->getBoundingBox();
	auto bBox = objectB->getBoundingBox();
	if (bBox == nullptr || aBox == nullptr)
		return Collision(colliding, coldir);
	auto aPos = objectA->position();
	auto aLen = aBox->length;
	auto aWidth = aBox->width;
	auto aHeight = aBox->height;

	auto bPos = objectB->position();
	auto bLen = bBox->length;
	auto bWidth = bBox->width;
	auto bHeight = bBox->height;

	bool xContains = false;
	bool yContains = false;

	if (aPos.x + aLen > bPos.x - bLen && aPos.x + aLen < bPos.x + bLen) {
		xContains = true;
		coldir.x = 1;
	}
	else if (aPos.x - aLen < bPos.x + bLen && aPos.x - aLen > bPos.x - bLen) {
		xContains = true;
		coldir.x = -1;
	}

	if (aPos.y - aHeight < bPos.y + bHeight && aPos.y - aHeight > bPos.y - bHeight) {
		yContains = true;
		coldir.y = 1;
	}
	else if (aPos.y + aHeight > bPos.y - bHeight && aPos.y + aHeight < bPos.y + bHeight) {
		yContains = true;
		coldir.y = -1;
	}

	
	return Collision(xContains && yContains, coldir);
}

BoundingBox::~BoundingBox()
{
}
