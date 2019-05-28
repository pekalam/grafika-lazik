#include "stdafx.h"
#include "ScianaG.h"


void ScianaG::drawObject()
{
	GLfloat stepX = _dl / _sectorsX;
	GLfloat stepZ = _szer / _sectorsZ;
	for (int i = 1; i <= _sectorsZ; i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (int j = 1; j <= _sectorsX + 1; j++) {
			glNormal3f(0, 1, 0);
			glVertex3f(-_dl / 2 + (j - 1) * stepX, 0, _szer / 2 + -i * stepZ);
			glNormal3f(0, 1, 0);
			glVertex3f(-_dl / 2 + (j - 1) * stepX, 0, _szer / 2 + -(i - 1) * stepZ);
			
		}
		glEnd();
	}
}


