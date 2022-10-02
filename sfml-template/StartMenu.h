#pragma once
#include "Scene.h"

class StartMenu :public Scene
{
public:
	StartMenu() {};
	virtual ~StartMenu() {};

	virtual void Draw(RenderWindow& e);
	virtual void Update(float dt);
private:

};