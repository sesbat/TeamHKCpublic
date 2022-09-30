#include "Scene.h"
#include "InputMgr.h"
#include "sceneMgr.h"
#include <iostream>

Scene::Scene(list<Graphics> tempenv, list<MovingObj>movingObj, int sel)
{
	this->sel = sel;
	env = tempenv;
	this->movingObj = movingObj;
}

Scene::Scene(list<Graphics> tempenv, list<MovingObj> movingObj, Player* player, int sel)
	:player(player)
{
	this->sel = sel;
	env = tempenv;
	this->movingObj = movingObj;
}

Scene::~Scene()
{
}

void Scene::Draw(RenderWindow& e)
{
	for (auto v : env)
		v.Draw(e);
	for (auto v : movingObj)
		v.Draw(e);

	if (player != nullptr)
		player->Draw(e);
}

void Scene::StartMeun(float dt)
{
	std::cout << "test" << std::endl;
	if (InputMgr::GetKeyDown(Keyboard::A)) {
		sel++;
		SceneMgr::GetInstance()->SetScene((SceneSelect)sel);
	}
}

void Scene::MainMenu(float dt)
{

	if (InputMgr::GetKeyDown(Keyboard::A)) {
		sel++;
		SceneMgr::GetInstance()->SetScene((SceneSelect)sel);
	}
}

void Scene::SkinMenu(float dt)
{
	cout << "skin" << endl;

	if (InputMgr::GetKeyDown(Keyboard::Right)) {
		player->SetSkin(1);
	}
	else if (InputMgr::GetKeyDown(Keyboard::Left)) {
		player->SetSkin(-1);
	}
	if (InputMgr::GetKeyDown(Keyboard::Return)) {
		sel++;
		SceneMgr::GetInstance()->SetScene((SceneSelect)sel);
	}
}

void Scene::Solo(float dt)
{

	cout << player->GetPos().x << " " << player->GetPos().y << endl;

	if (InputMgr::GetKeyDown(Keyboard::Left)) {
		player->Chop(Sides::Left);
	}
	if (InputMgr::GetKeyDown(Keyboard::Right))
		player->Chop(Sides::Right);


}

void Scene::Couple(float dt)
{

}

void Scene::Update(float dt)
{
	switch (sel) {
	case 0:
		StartMeun(dt);
		break;
	case 1:
		MainMenu(dt);
		break;

	case 2:
		SkinMenu(dt);
		break;

	case 3:
		Solo(dt);
		break;
	}
	//    sceneCollect[sel]->Draw(e);
	//case 4:
	//    sceneCollect[sel]->Draw(e);
	//    break;
	//} 
}