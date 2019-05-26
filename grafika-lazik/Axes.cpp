#include "stdafx.h"
#include "Axes.h"


Axes::Axes(GLfloat dlOsi, GLfloat dlPodzialki, GLfloat krok) : SceneObject("osie"), _dlugoscPodzialki(dlPodzialki), _dlugoscOsi(dlOsi), _krok(krok)
{
}


void Axes::drawObject()
{
	int i;
	GLfloat lin;

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(_dlugoscOsi, 0.0f, 0.0f);
	glEnd();

	lin = 1.0f;
	for (i = 0; i < (int)_dlugoscOsi; i++, lin += 1.0f)
	{
		glBegin(GL_LINES);
		glVertex3f(lin, -_dlugoscPodzialki, 0.0f);
		glVertex3f(lin, _dlugoscPodzialki, 0.0f);
		glEnd();
	}

	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, _dlugoscOsi, 0.0f);
	glEnd();

	lin = 1.0f;
	for (i = 0; i < (int)_dlugoscOsi; i++, lin += 1.0f)
	{
		glBegin(GL_LINES);
		glVertex3f(-_dlugoscPodzialki, lin, 0.0f);
		glVertex3f(_dlugoscPodzialki, lin, 0.0f);
		glEnd();
	}

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -_dlugoscOsi);
	glEnd();

	lin = -1.0f;
	for (i = 0; i < (int)_dlugoscOsi; i++, lin -= 1.0f)
	{
		glBegin(GL_LINES);
		glVertex3f(-_dlugoscPodzialki, 0.0f, lin);
		glVertex3f(_dlugoscPodzialki, 0.0f, lin);
		glEnd();
	}

	glColor3f(0.0f, 0.0f, 0.0f);
}




