#include "stdafx.h"
#include "TrapezProstG.h"


void TrapezProstG::drawObject()
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
	GLfloat stepB = (_a-_b)/_sectorsX;
	glBegin(GL_TRIANGLE_STRIP);
		
		for(int i = 0; i <= _sectorsY; i++)
		{
			glVertex3f(_b / 2, 0, _h / 2 + -(i)* stepZ);
			for(int j = 1; j <= _sectorsX-i; j++)
			{
				glVertex3f(_b / 2 + (j*stepB), 0, _h/2 + -(i) * stepZ);
				glVertex3f(_b / 2 + ((j-1)*stepB), 0, _h / 2 + -(i+1)* stepZ);
			}
		}
	glEnd();
}
