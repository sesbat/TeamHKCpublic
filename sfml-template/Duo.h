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

	Graphics choice;
	Letter reStart;
	Letter mainMenu;

	Graphics dieText_1P;
	Graphics dieText_2P;
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
};