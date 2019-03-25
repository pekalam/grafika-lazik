#pragma once

#include <vector>
#include <functional>
#include <algorithm>
#include "Axes.h"


class ViewEngine
{
	friend class SceneObject;
private:
	static ViewEngine* __singleton;
	std::vector<std::reference_wrapper<SceneObject>> _sceneObjects;
	int _lastWidth, _lastHeight;
	Vector3 _cameraPosition;
	Vector3 _cameraRotation;
	std::unique_ptr<Axes> _axes;
	unsigned short _polygonModeFace = GL_FRONT_AND_BACK;
	unsigned short _polygonModeMode = GL_LINE;
	void registerObject(SceneObject& obj) { _sceneObjects.push_back(obj); }
	void unregisterObject(SceneObject &obj) { std::remove_if(_sceneObjects.begin(), _sceneObjects.end(), [&](std::reference_wrapper<SceneObject>& ch) { return ch.get().name() == obj.name(); }); }
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
	SceneObject& getByName(std::string name)
	{
		return std::find_if(_sceneObjects.begin(), _sceneObjects.end(), 
							[&](auto& ch){ return ch.get().name() == name; })->get();
	}

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
		return _cameraPosition;
	}

	void cameraPosition(const Vector3& point)
	{
		_cameraPosition = point;
	}

	Vector3 cameraRotation() const
	{
		return _cameraRotation;
	}

	void cameraRotation(const Vector3& point)
	{
		_cameraRotation = point;
	}

	void cameraPositionX(GLfloat x) { _cameraPosition.x = x; }
	void cameraPositionY(GLfloat y) { _cameraPosition.y = y; }
	void cameraPositionZ(GLfloat z) { _cameraPosition.z = z; }
																			
	void cameraRotationX(GLfloat x) { _cameraRotation.x = x; }
	void cameraRotationY(GLfloat y) { _cameraRotation.y = y; }
	void cameraRotationZ(GLfloat z) { _cameraRotation.z = z; }

	
	ViewEngine(const ViewEngine&) = delete;
	ViewEngine(ViewEngine&&) = delete;
	void operator=(ViewEngine &) = delete;


	template<typename T>
	void init(T onInitialized) { init(); onInitialized(); }
	void init();
	void winSizeChanged(int w, int h);
	void render();
};
