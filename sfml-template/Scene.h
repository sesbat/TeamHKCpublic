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
    Player* player=nullptr;

    Vector2f ScreenSize = { 1920, 1080 };

    int sel = 0;
public:
   
    Scene(list<Graphics> tempenv, list<MovingObj>movingObj, int sel);
    Scene(list<Graphics> tempenv, list<MovingObj>movingObj,Player* player, int sel);
    ~Scene();

    void Draw(RenderWindow& e);
    void Update(float dt);
    void StartMeun(float dt);
    void MainMenu(float dt);
    void SkinMenu(float dt);
    void Solo(float dt);
    void Couple(float dt);
};