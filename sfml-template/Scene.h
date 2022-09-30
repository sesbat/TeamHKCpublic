#pragma once

#include <list>
#include "Graphics.h"
#include "MovingObj.h"
#include "ResourceMgr.h"

class Scene 
{
private:
	//list<Player> player;
	list<Graphics*> env;
	list<MovingObj*>movingThing;
public:
	Scene();
	~Scene();

	void Draw(RenderWindow& e);
};

