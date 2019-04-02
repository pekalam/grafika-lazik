#include "stdafx.h"
#include "ViewEngine.h"
#include <gl/gl.h>
#include <gl\glu.h>
#include "SceneObject.h"

ViewEngine* ViewEngine::__singleton = nullptr;

ViewEngine::ViewEngine() : 
	_lastWidth(0),
	_lastHeight(0),
	_cameraPosition{ 5.0f,-10.0f,-50.0f }
{
	
}

void ViewEngine::init(std::function<void()> onRepaint)
{
	_repaint = onRepaint;
	_axes = std::make_unique<Axes>();
	// Light values and coordinates
	//GLfloat  ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
	//GLfloat  diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	//GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};
	//GLfloat	 lightPos[] = { 0.0f, 150.0f, 150.0f, 1.0f };
	//GLfloat  specref[] =  { 1.0f, 1.0f, 1.0f, 1.0f };
	


	glEnable(GL_DEPTH_TEST);	// Hidden surface removal
	glFrontFace(GL_CCW);		// Counter clock-wise polygons face out
	//glEnable(GL_CULL_FACE);		// Do not calculate inside of jet

	// Enable lighting
	//glEnable(GL_LIGHTING);

	// Setup and enable light 0
	//glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
	//glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
	//glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
	//glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
	//glEnable(GL_LIGHT0);

	// Enable color tracking
	//glEnable(GL_COLOR_MATERIAL);

	// Set Material properties to follow glColor values
	//glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	// All materials hereafter have full specular reflectivity
	// with a high shine
	//glMaterialfv(GL_FRONT, GL_SPECULAR,specref);
	//glMateriali(GL_FRONT,GL_SHININESS,128);


	// White background
	glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
	// Black brush
	glColor3f(0.0, 0.0, 0.0);
}

void ViewEngine::registerObject(SceneObject& obj)
{
	_newSceneObjectsQueue.push_back(obj);
}

void ViewEngine::unregisterObject(SceneObject& obj)
{
	auto it = std::find_if(_sceneObjects.begin(), _sceneObjects.end(), [&](std::reference_wrapper<SceneObject>& ch)
	{
		return ch.get().name() == obj.name();
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
			return ch.get().name() == obj.name();
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

	gluPerspective(60.0f, fAspect, 1.0, 400);

	

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void ViewEngine::render()
{
	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Save the matrix state and do the rotations
	glPushMatrix();
	glTranslatef(_cameraPosition.x, _cameraPosition.y, _cameraPosition.z);
	rotClampv(_cameraRotation);
	glRotatef(_cameraRotation.x, 1.0f, 0.0f, 0.0f);
	glRotatef(_cameraRotation.y, 0.0f, 1.0f, 0.0f);


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

	glPopMatrix();

	// Flush drawing commands
	glFlush();

	if (_newSceneObjectsQueue.size() > 0)
		_repaint();
}
