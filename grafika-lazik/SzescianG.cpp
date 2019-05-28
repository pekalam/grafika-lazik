#include "stdafx.h"
#include "SzescianG.h"


void SzescianG::drawObject()
{
	prx_beginFigure();
	int i, j;
	GLfloat stepX = _dl / _sectorsX;
	GLfloat stepY = _wys / _sectorsY;
	GLfloat stepZ = _szer / _sectorsZ;
	for (i = 1; i <= _sectorsX; i++) {
		prx_glBegin(GL_TRIANGLE_STRIP);
		for (j = 1; j <= _sectorsY + 1; j++) {
			glNormal3f(0, 0, 1);
			prx_glVertex3f(-_dl/2 + (i - 1) * stepX, -_wys / 2 + (j - 1) * stepY, _szer/2);
			glNormal3f(0, 0, 1);
			prx_glVertex3f(-_dl/2 + i * stepX, -_wys / 2 + (j - 1) * stepY, _szer / 2);
		}
		prx_glEnd();
	}

	for (i = 1; i <= _sectorsX; i++) {
		prx_glBegin(GL_TRIANGLE_STRIP);
		for (j = 1; j <= _sectorsY + 1; j++) {
			glNormal3f(0, 0, -1);
			prx_glVertex3f(-_dl / 2 + (i - 1) * stepX, -_wys/2 + (j - 1) * stepY, -_szer/2);
			glNormal3f(0, 0, -1);
			prx_glVertex3f(-_dl / 2 + i * stepX, -_wys/2 + (j - 1) * stepY, -_szer/2);
		}
		prx_glEnd();
	}

	for (i = 1; i <= _sectorsZ; i++) {
		prx_glBegin(GL_TRIANGLE_STRIP);
		for (j = 1; j <= _sectorsY + 1; j++) {
			glNormal3f(-1, 0, 0);
			prx_glVertex3f(-_dl/2, -_wys/2 + (j - 1) * stepY, _szer/2 + -(i - 1) * stepZ);
			glNormal3f(-1, 0, 0);
			prx_glVertex3f(-_dl/2, -_wys/2 + (j - 1) * stepY, _szer/2 + -i * stepZ);
		}
		prx_glEnd();
	}

	for (i = 1; i <= _sectorsZ; i++) {
		prx_glBegin(GL_TRIANGLE_STRIP);
		for (j = 1; j <= _sectorsY + 1; j++) {
			glNormal3f(1, 0, 0);
			prx_glVertex3f(_dl/2, -_wys / 2 + (j - 1) * stepY, _szer/2 + -(i - 1) * stepZ);
			glNormal3f(1, 0, 0);
			prx_glVertex3f(_dl/2, -_wys / 2 + (j - 1) * stepY, _szer/2 + -i * stepZ);
		}
		prx_glEnd();
	}

	for (i = 1; i <= _sectorsZ; i++) {
		prx_glBegin(GL_TRIANGLE_STRIP);
		for (j = 1; j <= _sectorsX + 1; j++) {
			glNormal3f(0, -1, 0);
			prx_glVertex3f(-_dl / 2 + (j - 1) * stepX, -_wys/2, _szer / 2 + -(i - 1) * stepZ);
			glNormal3f(0, -1, 0);
			prx_glVertex3f(-_dl / 2 + (j - 1) * stepX, -_wys / 2, _szer / 2 + -i * stepZ);
		}
		prx_glEnd();
	}

	for (i = 1; i <= _sectorsZ; i++) {
		prx_glBegin(GL_TRIANGLE_STRIP);
		for (j = 1; j <= _sectorsX + 1; j++) {
			glNormal3f(0, 1, 0);
			prx_glVertex3f(-_dl / 2 + (j - 1) * stepX, _wys / 2, _szer/2 + -(i - 1) * stepZ);
			glNormal3f(0, 1, 0);
			prx_glVertex3f(-_dl / 2 + (j - 1) * stepX, _wys / 2, _szer/2 + -i * stepZ);
		}
		prx_glEnd();
	}
	prx_finishFigure();
}
