#pragma once
#include "Graphics.h"
#include "Effect.h"
#include <list>
#include "InputMgr.h"

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
    vector<string> skin;

    Graphics axe;
    Graphics rip;

    bool isAxe = false;
    bool isAlive = true;
    bool isChopping;

    vector<Vector2f> originalPos;
    Vector2f Center;
    Vector2f axePos;

    int skinsel=0;
public:
    Player(string tex);
    virtual ~Player();
    virtual void SetFlipX(bool flip)override;
    virtual void Init()override;
    virtual void Release()override;
    virtual void Update(float dt)override;
    virtual void Draw(RenderWindow& window)override;
    virtual void SetPos(Vector2f pos)override;

    void ShowLog();
    Sides GetSide();
    void Die();
    void SetAlive(bool alive);
    void Chop(Sides side);
    bool GetAlive();
    bool GetChop();
    void SetSide(Sides pos);
    void SetChop(bool chop);
    void SetSkin(int temp);
 
};