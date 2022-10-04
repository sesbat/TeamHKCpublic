#pragma once

#include <list>
#include "Graphics.h"
#include "MovingObj.h"
#include "ResourceMgr.h"
#include "Player.h"
#include "SoundMgr.h"
#include "Branche.h"

class Scene
{
protected:
    list<Graphics> env;  //배경만(나무따로) 
    SoundMgr sdMgr;
    Graphics back;
    MovingObj bee;
    MovingObj cloud;

    Vector2f ScreenSize = { 1920, 1080 };

    int sel = 0;
    static Player player1;
    static Player player2;
public:
    Player* GetPlayer1() { return &player1; }
    Player* GetPlayer2() { return &player2; }
    static String tempSkin;
    static String tempSkin2;
    static bool mode;
    
    Scene();
 
    virtual ~Scene();

    virtual void Draw(RenderWindow& e);
    virtual void Update(float dt);

};