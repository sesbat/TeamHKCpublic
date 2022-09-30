#pragma once
#include <list>
#include <map>
#include "Singleton.h"
#include"MovingObj.h"
#include"Graphics.h"
#include "Player.h"
#include "Scene.h"
#include "SoundMgr.h"

enum class SceneSelect
{
    StartMenu,
    MainMenu,
    SkinMenu,
    Solo,
    Couple,
};

using namespace std;
class SceneMgr : public Singleton<SceneMgr>
{
private:
    SceneSelect sel;
    map<SceneSelect, Scene*> sceneCollect;
    SoundMgr sound;
    bool played=false;
public:
    SceneMgr();
    virtual ~SceneMgr();
    void SetScene(SceneSelect);
    void SetOrigins();
    void SetPosition(Vector2f pos);
    void Draw(RenderWindow& e);
    void Update(float dt);
    void Init();
    void Release();
    void SetSel(SceneSelect sel) { this->sel = sel; }
    void AddScene(SceneSelect sceneName, Scene* temp);
    SceneSelect GetSel() { return sel; }
};