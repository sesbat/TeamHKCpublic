#include "Scene.h"
#include "InputMgr.h"
#include "sceneMgr.h"
#include "Letter.h"
#include <iostream>

String Scene::tempSkin = "graphics/player.png";
String Scene::tempSkin2 = "graphics/player.png";
bool Scene::mode = 0;
Player Scene::player1;
Player Scene::player2;
Scene::Scene()
{
	back.SetTex("graphics/background.png");
	env.push_back(back);
}

Scene::~Scene()
{
}

void Scene::Draw(RenderWindow& e)
{

	for (auto& v : env)
		v.Draw(e);
}

void Scene::Update(float dt) {}