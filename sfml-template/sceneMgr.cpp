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
	if (!(sel == SceneSelect::Solo && sel == SceneSelect::Couple)&&played==false) {
		sound.SoundPlay(SoundChoice::TitleSound);
		played = true;
	}
	if(sel == SceneSelect::Solo && sel == SceneSelect::Couple){
		played = false;
	}
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