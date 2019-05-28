#pragma once
#include <gl/gl.h>
#include <cmath>


#define GL_PI 3.1415926535897f

class Vector3
{
public:
	static Vector3 INF;
	GLfloat x, y, z;
	Vector3(GLfloat x = 0, GLfloat y = 0, GLfloat z = 0) : x(x), y(y), z(z) {};

	Vector3 operator+(const Vector3& p) const
	{
		return Vector3{ x + p.x, y + p.y, z + p.z };
	}

	Vector3& operator+=(const Vector3& p)
	{
		x += p.x; y += p.y; z += p.z;
		return *this;
	}

	GLfloat distance(Vector3 p) const {
		return sqrt(
			pow(x - p.x, 2) + pow(y - p.y, 2) + pow(z - p.z, 2)
		);
	}

	Vector3 mid(Vector3 p) const
	{
		Vector3 mid{ (x + p.x) / 2, (y + p.y) / 2, (z + p.z) / 2 };
		return mid;
	}

	void zero()
	{
		x = y = z = 0;
	}
};


