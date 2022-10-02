#pragma once
#include "Scene.h"

class MainMenu :public Scene
{
public:
	MainMenu() {
		tree.SetTex("graphics/tree.png");
		tree.SetOrigin(Origins::TC);
		tree.SetPos({ 1920 / 2,0 });
	};
	virtual ~MainMenu() {};

	virtual void Draw(RenderWindow& e);
	virtual void Update(float dt);
private:
	Graphics tree;

};