#pragma once
#include "Scene.h"

class SkinMenu : public Scene
{
public:
	SkinMenu() {};
	virtual ~SkinMenu() {};

	virtual void Draw(RenderWindow& e);
	virtual void Update(float dt);
};

