#pragma once
class TextureLoader
{
public:
	static int fd();
private:
	TextureLoader();
	~TextureLoader();
	
	unsigned char *loadBitmapFile(char *filename, BITMAPINFOHEADER *bitmapInfoHeader);
};

