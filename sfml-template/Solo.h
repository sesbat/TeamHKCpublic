#pragma once

#include"Scene.h"
#include "SkinMenu.h"
#include "Letter.h"

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

	Graphics dieText;
	Graphics choice;
	Letter reStart;
	Letter mainMenu;
	Letter score;
	Letter scoreResult;
	Font font;
	int scoreNum = 0;
	int scoreResultNum;
	int choicePlay = 0;
};