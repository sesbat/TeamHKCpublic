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
private:
    list<Graphics> env;  //배경만(나무따로) 
    list<MovingObj> movingObj;//벌,구름
    SoundMgr sdMgr;

    Vector2f ScreenSize = { 1920, 1080 };

    int sel = 0;

public:
    Scene();
 
    virtual ~Scene();

    virtual void Draw(RenderWindow& e);
    virtual void Update(float dt);

};