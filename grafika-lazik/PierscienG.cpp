#include "stdafx.h"
#include "PierscienG.h"


void PierscienG::drawObject()
{
	GLfloat step = 2 * GL_PI / _sections;

	glBegin(GL_TRIANGLE_STRIP);
	for(int i = 0; i <= _sections; i++)
	{
		glVertex3f(_r*cos(i * step), _r*sin(i * step), _h/2);
		glVertex3f(_r*cos(i * step), _r*sin(i * step), -_h / 2);
	}
	glEnd();

	GLfloat r2 = _r + _szer;
	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i <= _sections; i++)
	{
		glVertex3f(r2*cos(i * step), r2*sin(i * step), _h / 2);
		glVertex3f(r2*cos(i * step), r2*sin(i * step), -_h / 2);
	}
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i <= _sections; i++)
	{
		glVertex3f(_r*cos(i * step), _r*sin(i * step), _h / 2);
		glVertex3f(r2*cos(i * step), r2*sin(i * step), _h / 2);
	}
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i <= _sections; i++)
	{
		glVertex3f(_r*cos(i * step), _r*sin(i * step), -_h / 2);
		glVertex3f(r2*cos(i * step), r2*sin(i * step), -_h / 2);
	}
	glEnd();
}
