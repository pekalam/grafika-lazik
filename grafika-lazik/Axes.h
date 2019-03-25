#pragma once
#include "SceneObject.h"

class Axes : public SceneObject
{
private:
	GLfloat _dlugoscPodzialki;
public:
	GLfloat dlugoscPodzialki() const
	{
		return _dlugoscPodzialki;
	}

	void dlugoscPodzialki(GLfloat lfloat)
	{
		_dlugoscPodzialki = lfloat;
	}

	GLfloat dlugoscOsi() const
	{
		return _dlugoscOsi;
	}

	void dlugoscOsi(GLfloat lfloat)
	{
		_dlugoscOsi = lfloat;
	}

	GLfloat krok() const
	{
		return _krok;
	}

	void krok(GLfloat lfloat)
	{
		_krok = lfloat;
	}

private:
	GLfloat _dlugoscOsi;
	GLfloat _krok;
protected:
	void drawObject() override;
public:
	Axes(GLfloat dlOsi = 100.0f, GLfloat dlPodzialki = 0.50f, GLfloat krok = 1.0f);
};

