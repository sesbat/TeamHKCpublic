#pragma once
#include "Scene.h"

class MainMenu :public Scene
{
public:
	MainMenu() {};
	virtual ~MainMenu() {};

	virtual void Draw(RenderWindow& e);
	virtual void Update(float dt);
private:

};