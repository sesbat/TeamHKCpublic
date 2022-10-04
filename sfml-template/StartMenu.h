#pragma once
#include "Scene.h"
#include "Graphics.h"

class StartMenu :public Scene
{
public:
	StartMenu();
	virtual ~StartMenu() {};

	virtual void Draw(RenderWindow& e);
	virtual void Update(float dt);
private:
	Graphics startGraphic;
	bool setBGM = true;
};