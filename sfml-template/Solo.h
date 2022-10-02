#pragma once

#include"Scene.h"
#include "SkinMenu.h"

class Solo :public Scene {
public:
	Solo();
	virtual ~Solo();
	virtual void Draw(RenderWindow& e);
	virtual void Update(float dt);
	void Init();
private:
	Graphics tree;
	
	SkinMenu skin;

	bool updateInit=false;
};