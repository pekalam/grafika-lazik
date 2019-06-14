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
			glNormal3f(0, 0, 1);
			float x = -_dl / 2 + (i - 1) * stepX;
			float y = -_wys / 2 + (j - 1) * stepY;

			float tx = (x + _dl/2) / _dl;
			float ty = (y + _wys / 2) / _wys;
			TEXTURE2D(tx, ty);
			glVertex3f(x, y, _szer/2);
			glNormal3f(0, 0, 1);

			x = -_dl / 2 + i * stepX;
			y = -_wys / 2 + (j - 1) * stepY;
			tx = (x + _dl / 2) / _dl;
			ty = (y + _wys / 2) / _wys;
			TEXTURE2D(tx, ty);
			glVertex3f(x, y, _szer / 2);
		}
		glEnd();
	}

	for (i = 1; i <= _sectorsX; i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (j = 1; j <= _sectorsY + 1; j++) {
			glNormal3f(0, 0, -1);
			float x = -_dl / 2 + (i - 1) * stepX;
			float y = -_wys / 2 + (j - 1) * stepY;
			float tx = (x + _dl / 2) / _dl;
			float ty = (y + _wys / 2) / _wys;
			TEXTURE2D(tx, ty);
			glVertex3f(x, y, -_szer/2);
			glNormal3f(0, 0, -1);

			x = -_dl / 2 + i * stepX;
			y = -_wys / 2 + (j - 1) * stepY;
			tx = (x + _dl / 2) / _dl;
			ty = (y + _wys / 2) / _wys;
			TEXTURE2D(tx, ty);
			glVertex3f(x, y, -_szer/2);
		}
		glEnd();
	}

	for (i = 1; i <= _sectorsZ; i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (j = 1; j <= _sectorsY + 1; j++) {
			glNormal3f(-1, 0, 0);
			float z = _szer / 2 + -(i - 1) * stepZ;
			float y = -_wys / 2 + (j - 1) * stepY;
			float tz = (z + _szer / 2) / _szer;
			float ty = (y + _wys / 2) / _wys;

			TEXTURE2D(tz, ty);
			glVertex3f(-_dl/2, y,z);
			glNormal3f(-1, 0, 0);

			z = _szer / 2 + -i * stepZ;
			y = -_wys / 2 + (j - 1) * stepY;
			tz = (z + _szer / 2) / _szer;
			ty = (y + _wys / 2) / _wys;
			TEXTURE2D(tz, ty);
			glVertex3f(-_dl/2, y, z);
		}
		glEnd();
	}

	for (i = 1; i <= _sectorsZ; i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (j = 1; j <= _sectorsY + 1; j++) {
			glNormal3f(1, 0, 0);
			float z = _szer / 2 + -(i - 1) * stepZ;
			float y = -_wys / 2 + (j - 1) * stepY;
			float tz = (z + _szer / 2) / _szer;
			float ty = (y + _wys / 2) / _wys;

			TEXTURE2D(tz, ty);
			glVertex3f(_dl/2, y, z);
			glNormal3f(1, 0, 0);

			z = _szer / 2 + -i * stepZ;
			y = -_wys / 2 + (j - 1) * stepY;
			tz = (z + _szer / 2) / _szer;
			ty = (y + _wys / 2) / _wys;
			TEXTURE2D(tz, ty);
			glVertex3f(_dl / 2, y, z);
		}
		glEnd();
	}

	for (i = 1; i <= _sectorsZ; i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (j = 1; j <= _sectorsX + 1; j++) {
			glNormal3f(0, -1, 0);
			float z = _szer / 2 + -(i - 1) * stepZ;
			float x = -_dl / 2 + (j - 1) * stepX;
			float tz = (z + _szer / 2) / _szer;
			float tx = (x + _dl / 2) / _dl;

			TEXTURE2D(tx, tz);
			glVertex3f(x, -_wys/2, z);
			glNormal3f(0, -1, 0);

			z = _szer / 2 + -i * stepZ;
			x = -_dl / 2 + (j - 1) * stepX;
			tz = (z + _szer / 2) / _szer;
			tx = (x + _dl / 2) / _dl;
			TEXTURE2D(tx, tz);
			glVertex3f(x, -_wys / 2, z);
		}
		glEnd();
	}

	for (i = 1; i <= _sectorsZ; i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (j = 1; j <= _sectorsX + 1; j++) {
			glNormal3f(0, 1, 0);
			float z = _szer / 2 + -(i - 1) * stepZ;
			float x = -_dl / 2 + (j - 1) * stepX;
			float tz = (z + _szer / 2) / _szer;
			float tx = (x + _dl / 2) / _dl;
			TEXTURE2D(tx, tz);
			glVertex3f(-_dl / 2 + (j - 1) * stepX, _wys / 2, _szer/2 + -(i - 1) * stepZ);
			glNormal3f(0, 1, 0);
			z = _szer / 2 + -i * stepZ;
			x = -_dl / 2 + (j - 1) * stepX;
			tz = (z + _szer / 2) / _szer;
			tx = (x + _dl / 2) / _dl;
			TEXTURE2D(tx, tz);

			glVertex3f(-_dl / 2 + (j - 1) * stepX, _wys / 2, _szer/2 + -i * stepZ);
		}
		glEnd();
	}
}

void SzescianG::glBegin(GLenum mode)
{
	if (texture2D != nullptr)
		texture2D->begin();
	::glBegin(mode);
}

void SzescianG::glEnd()
{
	if (texture2D != nullptr)
		texture2D->end();
	::glEnd();
}
