#include "stdafx.h"
#include "Light.h"

void Light::drawObject()
{
	/*glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex3f(_position.x - 0.5f, _position.y - 0.5, _position.z + 0.5);
	glVertex3f(_position.x - 0.5f, _position.y - 0.5, _position.z - 0.5);
	glVertex3f(_position.x - 0.5f, _position.y + 0.5, _position.z - 0.5);
	glVertex3f(_position.x - 0.5f, _position.y + 0.5, _position.z + 0.5);
	glColor3f(0, 1, 0);
	glVertex3f(_position.x + 0.5f, _position.y - 0.5, _position.z + 0.5);
	glVertex3f(_position.x + 0.5f, _position.y - 0.5, _position.z - 0.5);
	glVertex3f(_position.x + 0.5f, _position.y + 0.5, _position.z - 0.5);
	glVertex3f(_position.x + 0.5f, _position.y + 0.5, _position.z + 0.5);
	glColor3f(0, 0, 1);
	glVertex3f(_position.x - 0.5f, _position.y - 0.5, _position.z + 0.5);
	glVertex3f(_position.x + 0.5f, _position.y - 0.5, _position.z + 0.5);
	glVertex3f(_position.x + 0.5f, _position.y + 0.5, _position.z + 0.5);
	glVertex3f(_position.x - 0.5f, _position.y + 0.5, _position.z + 0.5);
	glColor3f(1, 0, 0);
	glVertex3f(_position.x - 0.5f, _position.y - 0.5, _position.z - 0.5);
	glVertex3f(_position.x + 0.5f, _position.y - 0.5, _position.z - 0.5);
	glVertex3f(_position.x + 0.5f, _position.y + 0.5, _position.z - 0.5);
	glVertex3f(_position.x - 0.5f, _position.y + 0.5, _position.z - 0.5);
	glColor3f(0, 0, 1);
	glVertex3f(_position.x - 0.5f, _position.y - 0.5, _position.z + 0.5);
	glVertex3f(_position.x + 0.5f, _position.y - 0.5, _position.z + 0.5);
	glVertex3f(_position.x + 0.5f, _position.y - 0.5, _position.z - 0.5);
	glVertex3f(_position.x - 0.5f, _position.y - 0.5, _position.z - 0.5);
	glColor3f(0, 1, 1);
	glVertex3f(_position.x - 0.5f, _position.y + 0.5, _position.z + 0.5);
	glVertex3f(_position.x + 0.5f, _position.y + 0.5, _position.z + 0.5);
	glVertex3f(_position.x + 0.5f, _position.y + 0.5, _position.z - 0.5);
	glVertex3f(_position.x - 0.5f, _position.y + 0.5, _position.z - 0.5);
	glEnd();*/

}

Light::Light(Vector3 position, Vector3 rotation): SceneObject("light", position, rotation)
{
	/*// Light values and coordinates
	GLfloat qaAmbientLight[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat qaDiffuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat qaSpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat emitLight[] = { 0.9, 0.9, 0.9, 0.01 };
	GLfloat qaBlack[] = { 0.0, 0.0, 0.0, 1.0 }; //Black Color
	GLfloat qaGreen[] = { 0.0, 1.0, 0.0, 1.0 }; //Green Color
	GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 }; //White Color
	GLfloat qaRed[] = { 1.0, 0.0, 0.0, 1.0 }; //White Color

	// Enable lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Set lighting intensity and color
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	// Set the light position
	glLightfv(GL_LIGHT0, GL_POSITION, new GLfloat[3]{_position.x, _position.y, _position.z});

	glEnable(GL_COLOR_MATERIAL);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaGreen);

	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaGreen);

	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);

	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20);*/
}
