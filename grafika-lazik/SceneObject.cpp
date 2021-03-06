#include "stdafx.h"
#include "SceneObject.h"
#include "ViewEngine.h"
#include <sstream>
#include "BoundingBox.h"

Vector3 SceneObject::currentColor{ 0,0,0 };

std::string SceneObject::getBaseName() const
{
	std::string token;
	std::istringstream tokenStream(_name);
	while (std::getline(tokenStream, token, ':')) {};
	return token;
}

void SceneObject::_create()
{
	ViewEngine::instance().registerObject(*this);
}

void SceneObject::glBegin(GLenum mode)
{
	if (textures2D.size() && textures2D[currentTexture] != nullptr)
		textures2D[currentTexture]->begin();
	::glBegin(mode);
}

void SceneObject::glEnd()
{
	::glEnd();
	if (textures2D.size() && textures2D[currentTexture] != nullptr)
		textures2D[currentTexture]->end();
}

SceneObject::~SceneObject()
{
	ViewEngine::instance().unregisterObject(*this);
}

SceneObject& SceneObject::join(SceneObject* obj)
{
	auto ptr = std::unique_ptr<SceneObject>(obj);
	SceneObject& scObj = join(ptr);
	return scObj;
}

SceneObject& SceneObject::join(std::unique_ptr<SceneObject>& obj)
{
	for(auto& child : _children)
	{
		if (child.get() == obj.get())
			throw new std::exception("Already child of object");
	}

	obj->name(_name + ":" + obj->name());
	obj->_isChild = true;
	_children.push_back(std::move(obj));
	SceneObject* ptr = _children.back().get();
	return *ptr;
}

std::unique_ptr<SceneObject> SceneObject::disjoin(const std::string name)
{
	auto r = std::find_if(_children.begin(), _children.end(),
							[&](std::unique_ptr<SceneObject>& ch)
							{
								return ch->getBaseName() == name;
							});
	if (r != _children.end() && r->get()->getBaseName() == name)
	{
		auto ch = r->release();
		_children.erase(r);
		ch->_isChild = false;
		ch->_name = ch->getBaseName();
		return std::unique_ptr<SceneObject>(ch);
	}
	else
		throw new std::exception("child not found");
}

SceneObject* SceneObject::child(const std::string name)
{
	auto r = std::find_if(_children.begin(), _children.end(),
							[&](std::unique_ptr<SceneObject>& ch)
							{
								return ch->getBaseName() == name;
							});
	if (r != _children.end() && r->get()->getBaseName() == name)
		return r->get();
	else
		throw new std::exception(std::string("brak " + name).c_str());
}

void SceneObject::render()
{
	if (_hide)
		return;
	glPushMatrix();
	glRotatef(_coordRotation.x, 1.0f, 0.0f, 0.0f);
	glRotatef(_coordRotation.y, 0.0f, 1.0f, 0.0f);
	glRotatef(_coordRotation.z, 0.0f, 0.0f, 1.0f);
	glTranslatef(_position.x, _position.y, _position.z);
	glRotatef(_rotation.x, 1.0f, 0.0f, 0.0f);
	glRotatef(_rotation.y, 0.0f, 1.0f, 0.0f);
	glRotatef(_rotation.z, 0.0f, 0.0f, 1.0f);
	for (auto& child : _children)
		child->render();
	glColor3f(_color.x, _color.y, _color.z);
	drawObject();
	glLoadIdentity();
	glPopMatrix();
}

void SceneObject::setBoundingBox(int lengthx, int heighty, int widthz)
{
	auto boundingBox = new BoundingBox();
	boundingBox->setSizes(lengthx, heighty, widthz);
	_boundingBox = boundingBox;
	join(boundingBox);
}