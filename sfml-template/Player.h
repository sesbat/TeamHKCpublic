#pragma once

#include "Effect.h"
#include <list>
#include "InputMgr.h"
#include "SoundMgr.h"

class Graphics;

using namespace sf;
enum class Sides
{
    Left,
    Right,
    None,
};

class Player :public Graphics
{
private:
    Sides pos;

    list<Effect*> unuseLogs;
    list<Effect*> useLogs;
    string texLog;
   
    Texture axeTex;
    Sprite axe;  
    Texture ripTex;

    bool isAxe = false;
    bool isAlive = true;
    bool isChopping;

    vector<Vector2f> originalPos;
    Vector2f Center;
    Vector2f axePos;

    int skinsel=0;
    int choice = 1;
    bool isPause = false;

    string skin= "graphics/player.png";

public:
    Player();
    Player(string tex);
    virtual ~Player();
    virtual void SetFlipX(bool flip)override;
    virtual void Init()override;
    virtual void Release()override;
    virtual void Update(float dt)override;
    virtual void Draw(RenderWindow& window)override;
    virtual void SetPos(Vector2f pos)override;

    Sprite* GetAxe() { return &axe; }
    
    void SetOriginalPos(Vector2f Left, Vector2f Right);

    void SetSkin(string str) { skin = str; }

    void ShowLog();
    Sides GetSide();
    void Die();
    void SetAlive(bool alive);
    void Chop(Sides side);
    bool GetAlive();
    bool GetChop();
    void SetSide(Sides pos);
    void SetChop(bool chop);
  
    int GetChoice();
    void AddChoice();
    void SubChoice();
    void SetPause();
    bool GetPause();
    void SetAxePos(float x, float y);
};