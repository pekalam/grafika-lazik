#include "stdafx.h"
#include "ViewEngine.h"
#include <gl/gl.h>
#include <gl\glu.h>
#include "SceneObject.h"
#include "glm/gtx/rotate_vector.hpp"


ViewEngine* ViewEngine::__singleton = nullptr;

ViewEngine::ViewEngine() : 
	_lastWidth(0),
	_lastHeight(0),
	_cameraPositionDelta{ 0,0,0 },
	_initalCameraPosition{ 0.0f,6.0f,35.0f },
	_cameraLookDir{0,0,0}
{
	
}

void ViewEngine::init(std::function<void()> onRepaint)
{
	_repaint = onRepaint;
	_axes = std::make_unique<Axes>();

	glEnable(GL_DEPTH_TEST);	// Hidden surface removal
	glFrontFace(GL_CCW);		// Counter clock-wise polygons face out
	//glEnable(GL_CULL_FACE);		// Do not calculate inside of jet

	
	//gluLookAt()

	// White background
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	// Black brush
	glColor3f(0.0, 0.0, 0.0);
}

void ViewEngine::initLight()
{
	GLfloat qaAmbientLight[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat qaDiffuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat qaSpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat emitLight[] = { 0.9, 0.9, 0.9, 0.01 };
	GLfloat qaBlack[] = { 0.0, 0.0, 0.0, 1.0 }; //Black Color
	GLfloat qaGreen[] = { 0.0, 1.0, 0.0, 1.0 }; //Green Color
	GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 }; //White Color
	GLfloat qaRed[] = { 1.0, 0.0, 0.0, 1.0 }; //White Color

	// Enable lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Set lighting intensity and color
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	// Set the light position

	glLightfv(GL_LIGHT0, GL_POSITION, new GLfloat[4]
		{
			100,
			20,
			-_initalCameraPosition.z - 100,
			1
		});

	glEnable(GL_COLOR_MATERIAL);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaGreen);

	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaGreen);

	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);

	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20);
}

void ViewEngine::registerObject(SceneObject& obj)
{
	_newSceneObjectsQueue.push_back(obj);
}

void ViewEngine::unregisterObject(SceneObject& obj)
{
	auto it = std::find_if(_sceneObjects.begin(), _sceneObjects.end(), [&](std::reference_wrapper<SceneObject>& ch)
	{
		return &ch.get() == &obj;
	});
	if (it != _sceneObjects.end())
	{
		_sceneObjects.erase(it);
	}
	else if (it == _sceneObjects.end())
	{
		it = std::find_if(_newSceneObjectsQueue.begin(), _newSceneObjectsQueue.end(),
			[&](std::reference_wrapper<SceneObject>& ch)
		{
			return &ch.get() == &obj;
		});
		if (it != _newSceneObjectsQueue.end())
			_newSceneObjectsQueue.erase(it);
	}
}

void ViewEngine::winSizeChanged(int w, int h)
{
	GLfloat fAspect;
	// Prevent a divide by zero
	if (h == 0)
		h = 1;

	_lastWidth = w;
	_lastHeight = h;

	fAspect = (GLfloat)w / (GLfloat)h;
	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);

	// Reset coordinate system
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(60.0f, fAspect, 1.0, 800);

	gluLookAt(_initalCameraPosition.x, _initalCameraPosition.y, _initalCameraPosition.z, 
		_cameraLookDir.x, _cameraLookDir.y, _cameraLookDir.z,
		0, 1, 0);

	initLight();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void ViewEngine::render()
{
	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	_initalCameraPosition.x += _cameraPositionDelta.x;
	_initalCameraPosition.y += _cameraPositionDelta.y;
	_initalCameraPosition.z += _cameraPositionDelta.z;
	_cameraLookDir.x += _cameraPositionDelta.x;
	_cameraLookDir.y += _cameraPositionDelta.y;
	_cameraLookDir.z += _cameraPositionDelta.z;
	

	gluLookAt(_initalCameraPosition.x, _initalCameraPosition.y, _initalCameraPosition.z,
		_cameraLookDir.x, _cameraLookDir.y, _cameraLookDir.z,
		0, 1, 0);

	_cameraPositionDelta.zero();
	
	
	rotClampv(_cameraRotation);
	glRotatef(_cameraRotation.x, 1.0f, 0.0f, 0.0f);
	glRotatef(_cameraRotation.y, 0.0f, 1.0f, 0.0f);

	glLightfv(GL_LIGHT0, GL_POSITION, new GLfloat[4]
		{
			100,
			20,
			-_initalCameraPosition.z - 100,
			1
		});


	glPolygonMode(_polygonModeFace, _polygonModeMode);

	while(!_newSceneObjectsQueue.empty())
	{
		_sceneObjects.push_back(_newSceneObjectsQueue.back());
		_newSceneObjectsQueue.pop_back();
	}

	for(auto obj : _sceneObjects)
	{
		if(!obj.get().isChild())
			obj.get().render();
	}

	// Flush drawing commands
	glFlush();

	if (_newSceneObjectsQueue.size() > 0)
		_repaint();
}
