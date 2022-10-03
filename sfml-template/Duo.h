#pragma once

#include "Scene.h"
#include "Letter.h"

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


	Graphics choice;
	Letter reStart;
	Letter mainMenu;

	Graphics win;
	Graphics lose;
	Graphics middleLine;
	Graphics p1_Die;
	Graphics p2_Die;

	Graphics draw1;
	Graphics draw2;

	Letter score_1P;
	Letter score_2P;
	Letter scoreResult_1P;
	Letter scoreResult_2P;

	Font font;

	int scoreNum_1P = 0;
	int scoreNum_2P = 0;

	int scoreResultNum_1P;
	int scoreResultNum_2P;

	int choicePlay = 0;

	bool resultScreen = false;
};