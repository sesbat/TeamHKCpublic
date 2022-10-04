#pragma once
#include "Scene.h"
#include "Letter.h"
#include "SoundMgr.h"

class MainMenu :public Scene
{
public:
	MainMenu();
	virtual ~MainMenu() {};

	virtual void Draw(RenderWindow& e);
	virtual void Update(float dt);

private:
	Graphics tree;

	Graphics choice;
	Graphics playMode;
	Letter onePlayer;
	Letter twoPlayer;
	Font font;

	SoundMgr sdMgr;
	bool setBGM = true;
};