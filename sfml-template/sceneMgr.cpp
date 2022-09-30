#include "SceneMgr.h"

SceneMgr::SceneMgr()
{
}

void SceneMgr::SetScene(SceneSelect temp)
{
	sel = temp;
}

SceneMgr::~SceneMgr()
{
}

void SceneMgr::SetOrigins()
{
}

void SceneMgr::SetPosition(Vector2f pos)
{
}

void SceneMgr::Draw(RenderWindow& e)
{
	sceneCollect[sel]->Draw(e);

}
void SceneMgr::Update(float dt)
{

	sceneCollect[sel]->Update(dt);
}

void SceneMgr::Init()
{
}

void SceneMgr::Release()
{
}

void SceneMgr::AddScene(SceneSelect sceneName, Scene* temp)
{
	sceneCollect.insert({ sceneName, temp });
}