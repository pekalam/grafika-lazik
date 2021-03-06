#pragma once


#include "Axes.h"
#include "glm/glm.hpp"
#include "glm/ext.hpp"
#include "PhysicsEngine.h"
#include "ViewEngine_defs.h"

class ViewEngine
{
	friend class SceneObject;
private:
	static ViewEngine* __singleton;
	std::function<void()> _repaint;
	SceneObjectList _sceneObjects;
	SceneObjectList _newSceneObjectsQueue;
	int _lastWidth, _lastHeight;
	Vector3 _cameraPositionDelta;
	Vector3 _cameraRotation;
	glm::vec3 _initalCameraPosition;
	glm::vec3 _cameraLookDir;
	std::unique_ptr<Axes> _axes;
	unsigned short _polygonModeFace = GL_FRONT_AND_BACK;
	unsigned short _polygonModeMode = GL_FILL;

	PhysicsEngine _physicsEngine;

	void initLight();
	void registerObject(SceneObject& obj);
	void unregisterObject(SceneObject& obj);
	void rotClamp(GLfloat &v) { if (v > 360.0f) v = v - 360.0f; else if (v < -360.0f) v = v + 360.0f; }
	void rotClampv(Vector3 &p) { rotClamp(p.x); rotClamp(p.y); rotClamp(p.z); }
	ViewEngine();
public:
	static ViewEngine& instance()
	{
		if(!ViewEngine::__singleton)
			__singleton = new ViewEngine();
		return *__singleton;
	}
	static ViewEngine* _instance_ptr()
	{
		return __singleton;
	}
	/** Zwraca SceneObject na podstawie nazwy. Par. name w formie: [rodzic]:[name] */
	SceneObject& getByName(std::string name)
	{
		auto obj = std::find_if(_sceneObjects.begin(), _sceneObjects.end(), 
							[&](auto& ch){ return ch.get().name() == name; });
		if (obj == _sceneObjects.end())
			throw new std::exception("Nie znaleziono");
		return obj->get();
	}
	void removeObject(std::string name)
	{
		unregisterObject(getByName(name));
	}
	std::shared_ptr<SceneObjectList> getNonStaticSceneObjects();

	bool isDisplayingAxes() const
	{
		return _axes->isVisible();
	}

	void displayAxes(bool displayAxes)
	{
		if (displayAxes)
			_axes->show();
		else
			_axes->hide();
	}

	void showMesh(bool show)
	{
		if (show)
			_polygonModeMode = GL_LINE;
		else
			_polygonModeMode = GL_FILL;
	}

	bool isShowingMesh() const { return _polygonModeMode == GL_LINE; }

	Vector3 cameraPosition() const
	{
		return _cameraPositionDelta;
	}

	void cameraPosition(const Vector3& point)
	{
		_cameraPositionDelta = point;
	}

	Vector3 cameraRotation() const
	{
		return _cameraRotation;
	}

	void cameraRotation(const Vector3& point)
	{
		_cameraRotation = point;
	}

	void moveCameraX(GLfloat x)
	{
		_cameraPositionDelta.x = x;
	}
	void moveCameraY(GLfloat y) { _cameraPositionDelta.y = y; }
	void moveCameraZ(GLfloat z) { _cameraPositionDelta.z = z; }
																			
	void cameraRotationX(GLfloat x)
	{
		_cameraRotation.x = x;
	}
	void cameraRotationY(GLfloat y) { _cameraRotation.y = y; }
	void cameraRotationZ(GLfloat z) { _cameraRotation.z = z; }


	ViewEngine(const ViewEngine&) = delete;
	ViewEngine(ViewEngine&&) = delete;
	void operator=(ViewEngine &) = delete;


	void init(std::function<void()> onRepaint);
	void winSizeChanged(int w, int h);
	void render();
	void update(float dt);
	void frame();
};

