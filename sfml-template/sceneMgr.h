#pragma once
#include <list>
#include <map>
#include "Singleton.h"
#include"MovingObj.h"
#include"Graphics.h"
#include "Player.h"
#include "Scene.h"
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
	map<SceneSelect, Scene*> currentScene;
public:
	virtual ~SceneMgr();
	SceneMgr();
	void SetScene(SceneSelect,Scene* temp);
	void SetOrigins();
	void SetPosition(Vector2f pos ); 
	virtual void Draw(RenderWindow&e);
	void Update(float dt);
	void Init();
	void Release();
	void SetSel(SceneSelect sel) { this->sel = sel; }
	SceneSelect GetSel() { return sel; }

	void SetGraphic(Graphics* temp);

};

