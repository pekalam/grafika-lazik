#include "stdafx.h"
#include "WalecG.h"

void WalecG::drawObject()
{
	int i;
	GLfloat angle;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3d(0.0, 0.0, -_wys/2);
	for (angle = 0.0; angle <= (2 * 3.14); angle += (3.14 / 8.0))
	{
		glVertex3d(_r*sin(angle), _r*cos(angle), -_wys / 2);
	}
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	for (i = 0; i < (int)_divStep; i++)
	{
		for (angle = 0.0; angle <= (2 * 3.14); angle += (3.14 / 8.0))
		{

			glVertex3f(_r*sin(angle), _r*cos(angle), i*-_wys/2 / _divStep + _wys/2);
			glVertex3f(_r*sin(angle), _r*cos(angle), (i + 1)*-_wys/2 / _divStep);
		}
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0f, 0.0f, _wys/2);
	for (angle = 0.0; angle <= (2 * 3.14); angle += (3.14 / 8.0))
	{
		glVertex3f(_r*sin(angle), _r*cos(angle), _wys/2);
	}
	glEnd();

}