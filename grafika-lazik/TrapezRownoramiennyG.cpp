#include "stdafx.h"
#include "TrapezRownoramiennyG.h"


void TrapezRownoramiennyG::drawObject()
{
	GLfloat stepX = _b / _sectorsX;
	GLfloat stepZ = _h / _sectorsY;

	for (int i = 1; i <= _sectorsY; i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (int j = 1; j <= _sectorsX + 1; j++) {
			glVertex3f(-_b / 2 + (j - 1) * stepX, 0, _h / 2 + -(i - 1) * stepZ);
			glVertex3f(-_b / 2 + (j - 1) * stepX, 0, _h / 2 + -i * stepZ);
		}
		glEnd();
	}
	
	//int secT = (_a - _b) / stepX;
	int t = _pr ? -1 : 1;
	GLfloat stepB = (_a-_b)/_sectorsX;
	
		for(int i = 0; i < _sectorsY; i++)
		{
			glBegin(GL_TRIANGLE_STRIP);
			glVertex3f(t * _b / 2 + t* (_sectorsX-i)*stepB, 0, _h / 2 + -(i)* stepZ);
			for(int j = _sectorsX - i - 1; j > 0; j--)
			{
				glVertex3f(t * _b / 2 + t * j * stepB, 0, _h / 2 + -(i + 1)* stepZ);
				glVertex3f(t * _b / 2 + t * j * stepB, 0, _h / 2 + -(i)* stepZ);
			}
			glVertex3f(t * _b / 2, 0, _h / 2 + -(i + 1)* stepZ);
			glVertex3f(t * _b / 2, 0, _h / 2 + -(i)* stepZ);
			glEnd();
		}

	if(_two)
	{
		t = t * -1;
		for (int i = 0; i < _sectorsY; i++)
		{
			glBegin(GL_TRIANGLE_STRIP);
			glVertex3f(t * _b / 2 + t * (_sectorsX - i)*stepB, 0, _h / 2 + -(i)* stepZ);
			for (int j = _sectorsX - i - 1; j > 0; j--)
			{
				glVertex3f(t * _b / 2 + t * j * stepB, 0, _h / 2 + -(i + 1)* stepZ);
				glVertex3f(t * _b / 2 + t * j * stepB, 0, _h / 2 + -(i)* stepZ);
			}
			glVertex3f(t * _b / 2, 0, _h / 2 + -(i + 1)* stepZ);
			glVertex3f(t * _b / 2, 0, _h / 2 + -(i)* stepZ);
			glEnd();
		}
	}
	
}
