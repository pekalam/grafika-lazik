#include "stdafx.h"
#include "ViewEngine.h"
#include <gl/gl.h>
#include <gl\glu.h>
#include "SceneObject.h"


ViewEngine* ViewEngine::__singleton = nullptr;

ViewEngine::ViewEngine() : 
	_lastWidth(0),
	_lastHeight(0),
	_cameraPositionDelta{ 0,0,0 },
	_initalCameraPosition{ 0.0f,7.0f,53.0f },
	_cameraLookDir{0,0,0},
	_physicsEngine(*this)
{
	
}

void ViewEngine::init(std::function<void()> onRepaint)
{
	_repaint = onRepaint;
	_axes = std::make_unique<Axes>();

	glEnable(GL_DEPTH_TEST);	// Hidden surface removal
	glFrontFace(GL_CCW);		// Counter clock-wise polygons face out
	//glEnable(GL_CULL_FACE);		// Do not calculate inside of jet

	initLight();
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

	GLfloat qaGreen[] = { 0.0, 1.0, 0.0, 1.0 }; //Green Color
	GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 }; //White Color
	GLfloat qaRed[] = { 1.0, 0.0, 0.0, 1.0 }; //White Color

	// Enable lighting
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Set lighting intensity and color
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	glEnable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaGreen);

	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaGreen);

	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);

	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 7.0f);

	/*glLightfv(GL_LIGHT0, GL_POSITION, new GLfloat[4]
		{
			100,
			20,
			-_initalCameraPosition.z - 100,
			1
		});*/
	glLightfv(GL_LIGHT0, GL_POSITION, new GLfloat[4]
		{
			0,
			10,
			150,
			1
		});
}

void ViewEngine::registerObject(SceneObject& obj)
{
	_newSceneObjectsQueue.push_back(obj);
}

void ViewEngine::unregisterObject(SceneObject& obj)
{
	auto it = std::find_if(_sceneObjects.begin(), _sceneObjects.end(), [&](SceneObjectList_item& ch)
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
			[&](SceneObjectList_item& ch)
		{
			return &ch.get() == &obj;
		});
		if (it != _newSceneObjectsQueue.end())
			_newSceneObjectsQueue.erase(it);
	}
}

std::shared_ptr<SceneObjectList> ViewEngine::getNonStaticSceneObjects()
{
	auto nonStatic = std::make_shared<SceneObjectList>();

	for (auto object : _sceneObjects)
	{
		if (object.get().hasPhysics())
		{
			nonStatic->push_back(object);
		}
	}

	if (nonStatic->size() == 0)
		return nullptr;
	return nonStatic;
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

	gluPerspective(60.0f, fAspect, 1.0, 900);

	gluLookAt(_initalCameraPosition.x, _initalCameraPosition.y, _initalCameraPosition.z, 
		_cameraLookDir.x, _cameraLookDir.y, _cameraLookDir.z,
		0, 1, 0);

	

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

	/*glLightfv(GL_LIGHT0, GL_POSITION, new GLfloat[4]
		{
			0,
			0,
			_initalCameraPosition.z,
			1
		});*/


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

	glLightfv(GL_LIGHT0, GL_POSITION, new GLfloat[4]
		{
			0,
			100,
			150,
			1
		});
	// Flush drawing commands
	glFlush();

	if (_newSceneObjectsQueue.size() > 0)
		_repaint();
}

void ViewEngine::update(float dt)
{
	_physicsEngine.update(dt);
}

void ViewEngine::frame()
{
}
