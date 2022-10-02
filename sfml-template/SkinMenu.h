#pragma once
#include <string>
#include "Scene.h"

class SkinMenu : public Scene
{
public:
	SkinMenu();
	virtual ~SkinMenu() {};

	virtual void Draw(RenderWindow& e);
	virtual void Update(float dt);

private:
	vector<string> skinList;
	Graphics tree;
	
	int skin=0;
	int skin2 = 0;
};

