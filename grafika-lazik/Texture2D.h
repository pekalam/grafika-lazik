#pragma once
#include <gl/gl.h>
#include <string>

class Texture2D
{
private:
	GLuint texture;
	int coordCalled = 0;
public:
	Texture2D(std::string fileName);
	void coord(GLfloat s, GLfloat t);
	void begin();
	void end();
};

