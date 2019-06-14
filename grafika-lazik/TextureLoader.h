#pragma once
#include <vector>
#include "Texture2D.h"
#include <map>
#include <gl/gl.h>


class TextureLoader
{
public:
	static TextureLoader& getInstance() { return _textureLoader; }
	GLuint loadTexture2D(std::string file);
private:
	TextureLoader();
	~TextureLoader();
	TextureLoader(const TextureLoader& cp) = delete;
	TextureLoader& operator=(const TextureLoader& cp) = delete;
	static TextureLoader _textureLoader;
	unsigned char* loadBitmapFile(const char *filename, BITMAPINFOHEADER *bitmapInfoHeader);
};

