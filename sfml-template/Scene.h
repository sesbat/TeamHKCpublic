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

/*
         씬mgr(그대로?)
            
        씬(벌,구름,배경)              필요한것:벌 구름 배경 
            |
            |
        -------------------
        |   |   |    |    |                     필요한것: 플레이어 나무 
      솔로 듀오 스킨 메뉴 시작 (각각 나무 플레이어 멤버 ) 생성자에서 플레이어,나무객체 만듬 
       
       업데이트 씬 객체 씬mgr sceneCollect에 넣기
       드로우 씬 객체 씬mgr sceneCollect에 넣기
*/

class Scene
{
protected:
    list<Graphics> env;  //배경만(나무따로) 
    vector<MovingObj*> movingObj;//벌,구름
    SoundMgr sdMgr;
    Graphics back;

    Vector2f ScreenSize = { 1920, 1080 };

    int sel = 0;
    static Player player1;
    static Player player2;
    static std::random_device rd;
    static std::mt19937 gen;
public:
    int RandomRange(int min, int maxExclude);

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