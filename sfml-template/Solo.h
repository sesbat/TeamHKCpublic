#pragma once

#include"Scene.h"
#include "SkinMenu.h"
<<<<<<< HEAD
#include "Letter.h"
=======
#include "Branche.h"
#include "Effect.h"
>>>>>>> df52abd6f0111e3bc44d23c837396613f2062a44

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
<<<<<<< HEAD

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
=======
	float duration = 10;
	float timer = duration;
	Vector2f timerBarSize;
	RectangleShape timerBar;
	list<Effect*> useLogs;
	list<Effect*> unuseLogs;
	Texture texLog;
>>>>>>> df52abd6f0111e3bc44d23c837396613f2062a44
};