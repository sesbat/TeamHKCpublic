#pragma once

#include "Scene.h"

class Duo :public Scene {
public:
	Duo();
	virtual ~Duo();
	virtual void Draw(RenderWindow& e);
	virtual void Update(float dt);

	void Init();
private:
	Graphics tree;
	Graphics tree2;
	Player player;
	Player Player2;

};