#pragma once

#include"Scene.h"
#include "SkinMenu.h"
#include "Letter.h"
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

	void UpdateBranches(vector<Branche*>& branches, int& current, vector<Vector2f>& posArr);


private:
	Graphics tree;
	SkinMenu skin;
	bool updateInit=false;

	Graphics Pause;
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
	float duration = 10;
	float timer = duration;
	bool isPause = false;
	Vector2f timerBarSize;
	RectangleShape timerBar;
	list<Effect*> useLogs;
	list<Effect*> unuseLogs;
	Texture texLog;

	

	vector<Branche*> branches;
	vector<Vector2f> branchPosArr;

	int currentBranch = -1;


	bool setBGM = true;

};