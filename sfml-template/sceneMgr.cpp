#include "SceneMgr.h"

SceneMgr::SceneMgr()
{
}

void SceneMgr::SetScene(SceneSelect, Scene* temp)
{
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
	if (currentScene.find(sel) != currentScene.end()) {
		return false;
	}
	switch (sel) {
		
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

void SceneMgr::SetGraphic(Graphics* temp)
{
	env.push_back(temp);
}
