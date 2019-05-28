#include "stdafx.h"
#include "KulaG.h"


Vector3 KulaG::fKula2(GLfloat sec, GLfloat sta, GLfloat r)
{
	Vector3 p;
	p.x = r * cos(sec) * sin(sta);
	p.y = r * cos(sta);
	p.z = sin(sec)*sin(sta)*r;
	return p;
}

void KulaG::drawObject()
{
	prx_beginFigure();
	GLfloat sectorStep = 2 * GL_PI / _sectors;
	GLfloat stackStep = GL_PI / _stacks;

	int i, j; GLfloat sec = 0.0f; GLfloat sta = 0.0f;

	for (j = 0; j < _stacks; j++, sta += stackStep) {

		for (i = 0; i < _sectors; i++, sec += sectorStep)
		{
			GLfloat a11 = sec;
			GLfloat a12 = sta;
			GLfloat a21 = sec + sectorStep;
			GLfloat a22 = sta + stackStep;
			Vector3 p1 = fKula2(a11, a12, _R);
			Vector3 p2 = fKula2(a21, a12, _R);
			Vector3 p3 = fKula2(a11, a22, _R);
			Vector3 p4 = fKula2(a21, a22, _R);
			prx_glBegin(GL_TRIANGLE_STRIP);
				glNormal3f(p1.x / _R, p1.y / _R, p1.y / _R);
				prx_glVertex3f(p1.x, p1.y, p1.z);

				glNormal3f(p2.x / _R, p2.y / _R, p2.z / _R);
				prx_glVertex3f(p2.x, p2.y, p2.z);

				glNormal3f(p3.x / _R, p3.y / _R, p3.z / _R);
				prx_glVertex3f(p3.x, p3.y, p3.z);

				glNormal3f(p4.x / _R, p4.y / _R, p4.z / _R);
				prx_glVertex3f(p4.x, p4.y, p4.z);
			prx_glEnd();
		}

	}
	prx_finishFigure();
}


