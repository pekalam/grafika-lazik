#include "stdafx.h"
#include "WalecG.h"


void WalecG::drawObject()
{
	GLfloat angle = 0.0f;
	GLfloat step = (2 * GL_PI) / _sections;


	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0, 0, _wys / 2.0f);
		for(int i = 1; i <= _sections + 1; i++)
		{
			GLfloat x = _r * cos(angle);
			GLfloat y = _r * sin(angle);
			glVertex3f(x, y, _wys / 2.0f);
			angle = i * step;
		}
	glEnd();

	angle = 0.0f;
	glBegin(GL_TRIANGLE_STRIP);
		for (int i = 1; i <= _sections + 1; i++)
		{
			GLfloat x = _r * cos(angle);
			GLfloat y = _r * sin(angle);
			glVertex3f(x, y, _wys / 2.0f);
			glVertex3f(x, y, -_wys / 2.0f);
			angle = i * step;
		}	
	glEnd();

	angle = 0.0f;
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0, 0, -_wys / 2.0f);
	for (int i = 1; i <= _sections + 1; i++)
	{
		GLfloat x = _r * cos(angle);
		GLfloat y = _r * sin(angle);
		glVertex3f(x, y, -_wys / 2.0f);
		angle = i * step;
	}
	glEnd();

}
