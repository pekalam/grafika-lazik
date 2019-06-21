#include "stdafx.h"
#include "TextureLoader.h"
#include <cstdio>
#include <gl/gl.h>
#include "IL/il.h"

TextureLoader TextureLoader::_textureLoader;



TextureLoader::TextureLoader()
{
	ilInit();
}


TextureLoader::~TextureLoader()
{

}

unsigned char* LoadImage(std::string file, BITMAPINFOHEADER &img)
{
	ILboolean success;
	ILuint image;

	ilGenImages(1, &image);
	ilBindImage(image);
	success = ilLoadImage((wchar_t const*)file.c_str());

	img.biWidth = ilGetInteger(IL_IMAGE_WIDTH);
	img.biHeight = ilGetInteger(IL_IMAGE_HEIGHT);

	if (success)
	{
		success = ilConvertImage(IL_RGB, IL_UNSIGNED_BYTE);

		if (!success)
		{
			return nullptr;
		}
	}
	else
		return nullptr;

	return ilGetData();
}

GLuint TextureLoader::loadTexture2D(std::string file, bool repeat)
{
	BITMAPINFOHEADER bitmapinfoheader;
	//unsigned char* bitmap = loadBitmapFile(file.c_str(), &bitmapinfoheader);
	unsigned char* bitmap = LoadImage(file, bitmapinfoheader);
	if(!bitmap)
	{
		throw std::exception("");
	}
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);       // aktywuje obiekt tekstury

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	auto param = repeat ? GL_REPEAT : GL_CLAMP;
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, param);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, param);

	// tworzy obraz tekstury
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bitmapinfoheader.biWidth,
		bitmapinfoheader.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, bitmap);



	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	return texture;
}

unsigned char* TextureLoader::loadBitmapFile(const char* filename, BITMAPINFOHEADER* bitmapInfoHeader)
{
	FILE *filePtr;							// wskaünik pozycji pliku
	BITMAPFILEHEADER	bitmapFileHeader;		// nag≥Ûwek pliku
	unsigned char		*bitmapImage;			// dane obrazu
	int					imageIdx = 0;		// licznik pikseli
	unsigned char		tempRGB;				// zmienna zamiany sk≥adowych

	// otwiera plik w trybie "read binary"
	fopen_s(&filePtr, filename, "rb");
	if (filePtr == NULL)
		return NULL;

	// wczytuje nag≥Ûwek pliku
	fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, filePtr);

	// sprawdza, czy jest to plik formatu BMP
	if (bitmapFileHeader.bfType != 0x4D42)
	{
		fclose(filePtr);
		return NULL;
	}

	// wczytuje nag≥Ûwek obrazu
	fread(bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, filePtr);

	// ustawia wskaünik pozycji pliku na poczπtku danych obrazu
	fseek(filePtr, bitmapFileHeader.bfOffBits, SEEK_SET);

	// przydziela pamiÍÊ buforowi obrazu
	bitmapImage = (unsigned char*)malloc(bitmapInfoHeader->biSizeImage);

	// sprawdza, czy uda≥o siÍ przydzieliÊ pamiÍÊ
	if (!bitmapImage)
	{
		free(bitmapImage);
		fclose(filePtr);
		return NULL;
	}

	// wczytuje dane obrazu
	fread(bitmapImage, 1, bitmapInfoHeader->biSizeImage, filePtr);

	// sprawdza, czy dane zosta≥y wczytane
	if (bitmapImage == NULL)
	{
		fclose(filePtr);
		return NULL;
	}

	// zamienia miejscami sk≥adowe R i B 
	for (imageIdx = 0; imageIdx < bitmapInfoHeader->biSizeImage; imageIdx += 3)
	{
		tempRGB = bitmapImage[imageIdx];
		bitmapImage[imageIdx] = bitmapImage[imageIdx + 2];
		bitmapImage[imageIdx + 2] = tempRGB;
	}

	// zamyka plik i zwraca wskaünik bufora zawierajπcego wczytany obraz
	fclose(filePtr);
	return bitmapImage;
}
