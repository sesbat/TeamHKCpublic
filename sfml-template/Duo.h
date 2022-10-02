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

	bool updateInit = false;
	float duration = 10;
	float timer1 = duration;
	float timer2 = duration;
	Vector2f timerBarSize;
	RectangleShape timerBar1;
	RectangleShape timerBar2;


};