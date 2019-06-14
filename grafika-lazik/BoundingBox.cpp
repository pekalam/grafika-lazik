#include "stdafx.h"
#include "BoundingBox.h"


bool BoundingBox::draw = true;

void BoundingBox::drawObject()
{
	/*
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
	*/
	if(!draw)
	{
		return;
	}
	glPushMatrix();

	glRotatef(90, 1, 0, 0);
	int _sections = 20;
	GLfloat angle = 0.0f;
	GLfloat step = (2 * GL_PI) / _sections;


	glBegin(GL_LINE_STRIP);

	for (int i = 1; i <= _sections + 1; i++)
	{
		GLfloat x = length * cos(angle);
		GLfloat y = length * sin(angle);
		glNormal3f(0, 0, 1);
		glVertex3f(0, 0, height);
		glNormal3f(0, 0, 1);
		glVertex3f(x, y, height);
		angle = i * step;
	}
	glEnd();

	angle = 0.0f;
	glBegin(GL_LINE_STRIP);
	for (int i = 1; i <= _sections + 1; i++)
	{
		GLfloat x = length * cos(angle);
		GLfloat y = length * sin(angle);
		glNormal3f(x, y, 0);
		glVertex3f(x, y, height);
		glNormal3f(x, y, 0);
		glVertex3f(x, y, -height);
		angle = i * step;
	}
	glEnd();

	angle = 0.0f;
	glBegin(GL_LINE_STRIP);

	for (int i = 1; i <= _sections + 1; i++)
	{
		GLfloat x = length * cos(angle);
		GLfloat y = length * sin(angle);
		glNormal3f(0, 0, -1);
		glVertex3f(0, 0, -height);
		glNormal3f(0, 0, -1);
		glVertex3f(x, y, -height);
		angle = i * step;
	}
	glEnd();

	glPopMatrix();
}

Collision BoundingBox::intersects(SceneObject* objectA, SceneObject* objectB)
{
	auto colliding = false;
	Vector3 coldir{ 0,0,0 };

	auto aBox = objectA->getBoundingBox();
	auto bBox = objectB->getBoundingBox();
	if (bBox == nullptr || aBox == nullptr)
		return Collision({ colliding,false }, coldir);
	auto aPos = objectA->position();
	auto aLen = aBox->length;
	auto aWidth = aBox->width;
	auto aHeight = aBox->height;

	auto bPos = objectB->position();
	auto bLen = bBox->length;
	auto bWidth = bBox->width;
	auto bHeight = bBox->height;

	bool xInters = false;
	bool yInters = false;
	bool zInters = false;
	GLfloat depth = 0;


	if (std::fabs(aPos.y - bPos.y) - (aHeight + bHeight) < 0.01f)
	{
		if (std::fabs(aPos.y - bPos.y) < (aHeight + bHeight))
		{
			depth = (aHeight + bHeight) - std::fabs(aPos.y - bPos.y);
		}
		yInters = true;
		if (aPos.y > bPos.y)
			coldir.y = 1;
		else
			coldir.y = -1;
	}

	float dst = sqrt((aPos.x - bPos.x) * (aPos.x - bPos.x) +
		(aPos.z - bPos.z) * (aPos.z - bPos.z));
	if (dst - (bLen + aLen) < 0.01f)
	{
		xInters = zInters = true;
		coldir.x = 1; coldir.z = 1;
	}


	
	/*if (aPos.x + aLen >= bPos.x - bLen && aPos.x + aLen <= bPos.x + bLen) {
		xContains = true;
		coldir.x = 1;
	}
	else if (aPos.x - aLen <= bPos.x + bLen && aPos.x - aLen >= bPos.x - bLen) {
		xContains = true;
		coldir.x = -1;
	}

	if (aPos.y - aHeight <= bPos.y + bHeight && aPos.y - aHeight >= bPos.y - bHeight) {
		yContains = true;
		coldir.y = 1;
	}
	else if (aPos.y + aHeight >= bPos.y - bHeight && aPos.y + aHeight <= bPos.y + bHeight) {
		yContains = true;
		coldir.y = -1;
	}

	if (aPos.z + aWidth >= bPos.z - bWidth && aPos.z + aWidth <= bPos.z + bWidth) {
		zContains = true;
		coldir.z = 1;
	}
	else if (aPos.z - aWidth <= bPos.z + bWidth && aPos.z - aWidth >= bPos.z - bWidth) {
		zContains = true;
		coldir.z = -1;
	}*/
	
	
	return Collision(
		{ xInters && yInters && zInters , depth}, 
		coldir);
}

BoundingBox::~BoundingBox()
{
}
