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
    switch (sel) {
    case SceneSelect::Couple:
        sceneCollect[sel]->Draw(e);
        break;
    case SceneSelect::MainMenu:
        sceneCollect[sel]->Draw(e);
        break;
    case SceneSelect::SkinMenu:
        sceneCollect[sel]->Draw(e);
        break;

    case SceneSelect::Solo:
        sceneCollect[sel]->Draw(e);

        break;
    case SceneSelect::StartMenu:
        sceneCollect[sel]->Draw(e);
        break;
    }

}
void SceneMgr::Update(float dt)
{

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