#include "stdafx.h"
#include "SceneObject.h"
#include "ViewEngine.h"
#include <sstream>

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

SceneObject::~SceneObject()
{
	ViewEngine::instance().unregisterObject(*this);
}

SceneObject& SceneObject::join(SceneObject* obj)
{
	auto ptr = std::unique_ptr<SceneObject>(obj);
	SceneObject& scObj = join(ptr);
	obj = nullptr;
	return scObj;
}

SceneObject& SceneObject::join(std::unique_ptr<SceneObject>& obj)
{
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
	float currentColor[4];
	glGetFloatv(GL_CURRENT_COLOR, currentColor);
	glPushMatrix();
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
	glColor3f(currentColor[0], currentColor[1], currentColor[2]);
}
