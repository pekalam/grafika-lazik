#include "stdafx.h"
#include "SzescianG.h"


void SzescianG::drawObject()
{
	int i, j;
	GLfloat stepX = _dl / _sectorsX;
	GLfloat stepY = _wys / _sectorsY;
	GLfloat stepZ = _szer / _sectorsZ;
	for (i = 1; i <= _sectorsX; i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (j = 1; j <= _sectorsY + 1; j++) {
			glVertex3f(-_dl/2 + (i - 1) * stepX, -_wys / 2 + (j - 1) * stepY, _szer/2);
			glVertex3f(-_dl/2 + i * stepX, -_wys / 2 + (j - 1) * stepY, _szer / 2);
		}
		glEnd();
	}

	for (i = 1; i <= _sectorsX; i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (j = 1; j <= _sectorsY + 1; j++) {
			glVertex3f(-_dl / 2 + (i - 1) * stepX, -_wys/2 + (j - 1) * stepY, -_szer/2);
			glVertex3f(-_dl / 2 + i * stepX, -_wys/2 + (j - 1) * stepY, -_szer/2);
		}
		glEnd();
	}

	for (i = 1; i <= _sectorsZ; i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (j = 1; j <= _sectorsY + 1; j++) {
			glVertex3f(-_dl/2, -_wys/2 + (j - 1) * stepY, _szer/2 + -(i - 1) * stepZ);
			glVertex3f(-_dl/2, -_wys/2 + (j - 1) * stepY, _szer/2 + -i * stepZ);
		}
		glEnd();
	}

	for (i = 1; i <= _sectorsZ; i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (j = 1; j <= _sectorsY + 1; j++) {
			glVertex3f(_dl/2, -_wys / 2 + (j - 1) * stepY, _szer/2 + -(i - 1) * stepZ);
			glVertex3f(_dl/2, -_wys / 2 + (j - 1) * stepY, _szer/2 + -i * stepZ);
		}
		glEnd();
	}

	for (i = 1; i <= _sectorsZ; i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (j = 1; j <= _sectorsX + 1; j++) {
			glVertex3f(-_dl / 2 + (j - 1) * stepX, -_wys/2, _szer / 2 + -(i - 1) * stepZ);
			glVertex3f(-_dl / 2 + (j - 1) * stepX, -_wys / 2, _szer / 2 + -i * stepZ);
		}
		glEnd();
	}

	for (i = 1; i <= _sectorsZ; i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (j = 1; j <= _sectorsX + 1; j++) {
			glVertex3f(-_dl / 2 + (j - 1) * stepX, _wys / 2, _szer/2 + -(i - 1) * stepZ);
			glVertex3f(-_dl / 2 + (j - 1) * stepX, _wys / 2, _szer/2 + -i * stepZ);
		}
		glEnd();
	}
}
