#pragma once

#include <list>
#include "Graphics.h"
#include "MovingObj.h"
#include "ResourceMgr.h"

class Scene
{
private:
    //list<Player> player;
    list<Graphics> env;
    list<MovingObj>movingObj;
    int sel = 0;
public:
    Scene(list<Graphics> tempenv, list<MovingObj>movingObj, int sel);
    ~Scene();

    void Draw(RenderWindow& e);
    void Update(float dt);
};