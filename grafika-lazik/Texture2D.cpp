#include "stdafx.h"
#include "Texture2D.h"
#include "TextureLoader.h"


Texture2D::Texture2D(std::string fileName, bool repeat)
{
	this->texture = TextureLoader::getInstance().loadTexture2D(fileName, repeat);
}

void Texture2D::coord(GLfloat s, GLfloat t)
{
	glTexCoord2f(s,t);
}

void Texture2D::begin()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
}

void Texture2D::end()
{
	glDisable(GL_TEXTURE_2D);
}
