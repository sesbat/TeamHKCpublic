#pragma once

#include <list>
#include "Graphics.h"
#include "MovingObj.h"
#include "ResourceMgr.h"
#include "Player.h"
#include "SoundMgr.h"
#include "Branche.h"

enum class MOVEOBJ {
    CLOUD,
    BEE,
};

class Scene
{
private:
    list<Graphics> env;
    list<MovingObj> movingObj;
    SoundMgr sdMgr;
    vector<Player> player;
    vector<Branche*> branches();
    int sel = 0;
public:
    Scene(list<Graphics> tempenv, list<MovingObj>movingObj, int sel);
    Scene(list<Graphics> tempenv, list<MovingObj>movingObj,vector<Player>player, int sel);
    ~Scene();

    void Draw(RenderWindow& e);
    void Update(float dt);
    void StartMeun();
    void MainMenu();
    void SkinMenu();
    void Solo();
    void Couple();
};