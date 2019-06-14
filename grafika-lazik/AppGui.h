#pragma once
#include "AntTweakBar.h"
#include "BoundingBox.h"
#include "PhysicsEngine.h"

class AppGui
{
private:
	static AppGui* _instance;
	AppGui();
	~AppGui();
	TwBar* _mainBar;
public: 
	static AppGui& instance() { TwWindowSize(200, 600); return *_instance; }
	TwBar& mainBar() { return *_mainBar; }
	void initMainBar()
	{
		_mainBar = TwNewBar("MainBar");
	}
	void addVarMainBar(std::string name, ETwType type, void* var, std::string conf)
	{
		TwAddVarRW(_mainBar, name.c_str(), type, var, conf.c_str());
		
	}
	void addButtonMainBar(std::string title, TwButtonCallback callback, void *clientData, std::string config)
	{
		TwAddButton(_mainBar, title.c_str(), callback, clientData, config.c_str());

	
	}
	void f(float* v)
	{
		TwAddVarRW(_mainBar, "predkosc", TW_TYPE_FLOAT, v, "");
	}
	void d()
	{
		TwAddVarRW(_mainBar, "Pokaz siatke kolizji", TW_TYPE_BOOLCPP, &BoundingBox::draw, "");
	}

	void g()
	{
		TwAddVarRW(_mainBar, "grawitacja", TW_TYPE_FLOAT, &PhysicsConfig::Default.g.y, "");
	}
};

