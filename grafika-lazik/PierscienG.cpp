#include "stdafx.h"
#include "PierscienG.h"


void PierscienG::drawObject()
{
	prx_beginFigure();
	GLfloat step = 2 * GL_PI / _sections;

	prx_glBegin(GL_TRIANGLE_STRIP);
	for(int i = 0; i <= _sections; i++)
	{
		GLfloat x = _r * cos(i * step);
		GLfloat y = _r * sin(i * step);
		glNormal3f(x,y,0);
		prx_glVertex3f(x, y, -_h / 2);
		glNormal3f(x, y, 0);
		prx_glVertex3f(x, y, _h/2);
		
	}
	prx_glEnd();

	GLfloat r2 = _r + _szer;
	prx_glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i <= _sections; i++)
	{
		GLfloat x = r2 * cos(i * step);
		GLfloat y = r2 * sin(i * step);
		glNormal3f(x, y, 0);
		prx_glVertex3f(x, y, -_h / 2);
		glNormal3f(x, y, 0);
		prx_glVertex3f(x, y, _h / 2);
		
	}
	prx_glEnd();

	prx_glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i <= _sections; i++)
	{
		GLfloat x1 = _r * cos(i * step);
		GLfloat x2 = r2 * cos(i * step);
		GLfloat y1 = _r * sin(i * step);
		GLfloat y2 = r2 * sin(i * step);
		glNormal3f(0,0,1);
		prx_glVertex3f(x1,y1, _h / 2);
		glNormal3f(0, 0, 1);
		prx_glVertex3f(x2,y2, _h / 2);
	}
	prx_glEnd();

	prx_glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i <= _sections; i++)
	{
		glNormal3f(0, 0, -1);
		prx_glVertex3f(_r*cos(i * step), _r*sin(i * step), -_h / 2);
		glNormal3f(0, 0, -1);
		prx_glVertex3f(r2*cos(i * step), r2*sin(i * step), -_h / 2);
	}
	prx_glEnd();

	prx_finishFigure();
}
