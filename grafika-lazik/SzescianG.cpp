#include "stdafx.h"
#include "SzescianG.h"


void SzescianG::drawObject()
{
	int i, j;

	glColor3f(0.0, 0.0, 0.0);
	for (i = 1; i <= (int)(_dl / _divStep); i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (j = 1; j <= (int)(_wys / _divStep) + 1; j++) {
			glVertex3f(-_dl/2 + (i - 1) * _divStep, -_wys / 2 + (j - 1) * _divStep, _szer/2);
			glVertex3f(-_dl/2 + i * _divStep, -_wys / 2 + (j - 1) * _divStep, _szer / 2);
		}
		glEnd();
	}

	for (i = 1; i <= (int)(_dl / _divStep); i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (j = 1; j <= (int)(_wys / _divStep) + 1; j++) {
			glVertex3f(-_dl / 2 + (i - 1) * _divStep, -_wys/2 + (j - 1) * _divStep, -_szer/2);
			glVertex3f(-_dl / 2 + i * _divStep, -_wys/2 + (j - 1) * _divStep, -_szer/2);
		}
		glEnd();
	}

	for (i = 1; i <= (int)(_szer / _divStep); i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (j = 1; j <= (int)(_wys / _divStep) + 1; j++) {
			glVertex3f(-_dl/2, -_wys/2 + (j - 1) * _divStep, _szer/2 + -(i - 1) * _divStep);
			glVertex3f(-_dl/2, -_wys/2 + (j - 1) * _divStep, _szer/2 + -i * _divStep);
		}
		glEnd();
	}

	for (i = 1; i <= (int)(_szer / _divStep); i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (j = 1; j <= (int)(_wys / _divStep) + 1; j++) {
			glVertex3f(_dl/2, -_wys / 2 + (j - 1) * _divStep, _szer/2 + -(i - 1) * _divStep);
			glVertex3f(_dl/2, -_wys / 2 + (j - 1) * _divStep, _szer/2 + -i * _divStep);
		}
		glEnd();
	}

	for (i = 1; i <= (int)(_szer / _divStep); i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (j = 1; j <= (int)(_dl / _divStep) + 1; j++) {
			glVertex3f(-_dl / 2 + (j - 1) * _divStep, -_wys/2, _szer / 2 + -(i - 1) * _divStep);
			glVertex3f(-_dl / 2 + (j - 1) * _divStep, -_wys / 2, _szer / 2 + -i * _divStep);
		}
		glEnd();
	}

	for (i = 1; i <= (int)(_szer / _divStep); i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (j = 1; j <= (int)(_dl / _divStep) + 1; j++) {
			glVertex3f(-_dl / 2 + (j - 1) * _divStep, _wys / 2, _szer/2 + -(i - 1) * _divStep);
			glVertex3f(-_dl / 2 + (j - 1) * _divStep, _wys / 2, _szer/2 + -i * _divStep);
		}
		glEnd();
	}
}
