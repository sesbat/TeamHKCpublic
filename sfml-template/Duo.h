#pragma once

#include "Scene.h"
#include "Letter.h"
#include "SoundMgr.h"

class Duo :public Scene {
public:
	Duo();
	virtual ~Duo();
	virtual void Draw(RenderWindow& e);
	virtual void Update(float dt);
	void ShowLogEffect(bool who);

	void Init();

	int RandomRange(int min, int maxExclude);
	void UpdateBranches(vector<Branche*>& branches, int& current, vector<Vector2f>& posArr);

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

	Graphics Pause;
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

	list<Effect*> useLogs;
	list<Effect*> unuseLogs;

	list<Effect*> useLogs1;
	list<Effect*> unuseLogs2;

	SoundMgr sdMgr;

	int scoreNum_1P = 0;
	int scoreNum_2P = 0;

	int scoreResultNum_1P;
	int scoreResultNum_2P;

	int choicePlay = 0;

	bool resultScreen = false;
	bool isPause = false;


	static std::random_device rd;
	static std::mt19937 gen;

	vector<Branche*> branches1;
	vector<Vector2f> branchPosArr1;

	vector<Branche*> branches2;
	vector<Vector2f> branchPosArr2;

	int currentBranch = -1;
	int currentBranch2 = -1;

	bool setBGM = true;

};