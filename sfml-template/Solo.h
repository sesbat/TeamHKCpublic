#pragma once

#include"Scene.h"
#include "SkinMenu.h"
#include "Branche.h"
#include "Effect.h"

class Solo :public Scene {
public:
	Solo();
	virtual ~Solo();
	virtual void Draw(RenderWindow& e);
	virtual void Update(float dt);
	void Init();
	void ShowLogEffect();
private:
	Graphics tree;
	
	SkinMenu skin;

	bool updateInit=false;
	float duration = 10;
	float timer = duration;
	Vector2f timerBarSize;
	RectangleShape timerBar;
	list<Effect*> useLogs;
	list<Effect*> unuseLogs;
	Texture texLog;
};