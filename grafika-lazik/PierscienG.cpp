#include "stdafx.h"
#include "PierscienG.h"


void PierscienG::drawObject()
{
	GLfloat step = 2 * GL_PI / _sections;

	glBegin(GL_TRIANGLE_STRIP);
	for(int i = 0; i <= _sections; i++)
	{
		GLfloat x = _r * cos(i * step);
		GLfloat y = _r * sin(i * step);
		glNormal3f(x,y,0);
		glVertex3f(x, y, -_h / 2);
		glNormal3f(x, y, 0);
		glVertex3f(x, y, _h/2);
		
	}
	glEnd();

	nextTex();

	GLfloat r2 = _r + _szer;
	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i <= _sections; i++)
	{
		GLfloat x = r2 * cos(i * step);
		GLfloat y = r2 * sin(i * step);
		glNormal3f(x, y, 0);
		TEXTURE2D(i / (float)_sections, 0);
		glVertex3f(x, y, -_h / 2);
		glNormal3f(x, y, 0);
		TEXTURE2D(i / (float)_sections, 1);
		glVertex3f(x, y, _h / 2);
		
	}
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i <= _sections; i++)
	{
		GLfloat x1 = _r * cos(i * step);
		GLfloat x2 = r2 * cos(i * step);
		GLfloat y1 = _r * sin(i * step);
		GLfloat y2 = r2 * sin(i * step);
		glNormal3f(0,0,1);
		glVertex3f(x1,y1, _h / 2);
		glNormal3f(0, 0, 1);
		glVertex3f(x2,y2, _h / 2);
	}
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i <= _sections; i++)
	{
		glNormal3f(0, 0, -1);
		glVertex3f(_r*cos(i * step), _r*sin(i * step), -_h / 2);
		glNormal3f(0, 0, -1);
		glVertex3f(r2*cos(i * step), r2*sin(i * step), -_h / 2);
	}
	glEnd();
}
