#pragma once
#include "SceneObject.h"
#include "Texture2D.h"

#define TEXTURE2D(s,t) if(texture2D != nullptr) texture2D->coord(s,t);
#define TEX2D_UPPER_LEFT TEXTURE2D(0,1)
#define TEX2D_LOWER_LEFT TEXTURE2D(0,0)
#define TEX2D_UPPER_RIGHT TEXTURE2D(1,1)
#define TEX2D_LOWER_RIGHT TEXTURE2D(1,0)

class SzescianG : public SceneObject
{
private:
	int _sectorsX, _sectorsY, _sectorsZ;
	GLfloat _dl, _wys, _szer;
	std::unique_ptr<Texture2D> texture2D;
protected:
	void drawObject() override;
	inline void glBegin(GLenum mode);
	inline void glEnd();
public:
	SzescianG(GLfloat dl, GLfloat wys, GLfloat szer,
		Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }, 
		int sectorsX = 1, int sectorsY = 1, int sectorsZ = 1, Vector3 color ={0,0,0}) : SceneObject(position, rotation, color), _sectorsX(sectorsX), _sectorsY(sectorsY) , _sectorsZ(sectorsZ), _wys(wys), _dl(dl), _szer(szer) {};
	SzescianG(std::string name, GLfloat dl, GLfloat wys, GLfloat szer,
		Vector3 position = { 0,0,0 }, Vector3 rotation = { 0,0,0 }, 
		int sectorsX = 1, int sectorsY = 1, int sectorsZ = 1, Vector3 color = { 0,0,0 }) : SceneObject(name, position, rotation, {}, color), _sectorsX(sectorsX), _sectorsY(sectorsY), _sectorsZ(sectorsZ), _wys(wys), _dl(dl), _szer(szer) {};
	void setTexture2D(Texture2D* texture2D) { this->texture2D = std::unique_ptr<Texture2D>(texture2D); }
};

