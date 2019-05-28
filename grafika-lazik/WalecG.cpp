#include "stdafx.h"
#include "WalecG.h"


void WalecG::drawObject()
{
	prx_beginFigure();
	GLfloat angle = 0.0f;
	GLfloat step = (2 * GL_PI) / _sections;


	prx_glBegin(GL_TRIANGLE_STRIP);
		
		for(int i = 1; i <= _sections + 1; i++)
		{
			GLfloat x = _r * cos(angle);
			GLfloat y = _r * sin(angle);
			glNormal3f(0, 0, 1);
			prx_glVertex3f(0, 0, _wys / 2.0f);
			glNormal3f(0, 0, 1);
			prx_glVertex3f(x, y, _wys / 2.0f);
			angle = i * step;
		}
	prx_glEnd();

	angle = 0.0f;
	prx_glBegin(GL_TRIANGLE_STRIP);
		for (int i = 1; i <= _sections + 1; i++)
		{
			GLfloat x = _r * cos(angle);
			GLfloat y = _r * sin(angle);
			glNormal3f(x, y, 0);
			prx_glVertex3f(x, y, _wys / 2.0f);
			glNormal3f(x, y, 0);
			prx_glVertex3f(x, y, -_wys / 2.0f);
			angle = i * step;
		}	
	prx_glEnd();

	angle = 0.0f;
	prx_glBegin(GL_TRIANGLE_STRIP);
		
		for (int i = 1; i <= _sections + 1; i++)
		{
			GLfloat x = _r * cos(angle);
			GLfloat y = _r * sin(angle);
			glNormal3f(0, 0, -1);
			prx_glVertex3f(0, 0, -_wys / 2.0f);
			glNormal3f(0, 0, -1);
			prx_glVertex3f(x, y, -_wys / 2.0f);
			angle = i * step;
		}
	prx_glEnd();
	prx_finishFigure();
}

void WalecG::color(Vector3 color)
{
	_color = color;
}
