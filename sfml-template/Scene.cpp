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

Scene::Scene(list<Graphics> tempenv, list<MovingObj> movingObj, vector<Player> player, int sel)
{
	this->sel = sel;
	env = tempenv;
	this->movingObj = movingObj;
	this->player = player;
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
	for (auto v : player)
		v.Draw(e);
}

void Scene::StartMeun()
{
	std::cout << "test" << std::endl;
	if (InputMgr::GetKeyDown(Keyboard::A)) {
		sel++;
		SceneMgr::GetInstance()->SetScene((SceneSelect)sel);
	}
}

void Scene::MainMenu()
{

	if (InputMgr::GetKeyDown(Keyboard::A)) {
		sel++;
		SceneMgr::GetInstance()->SetScene((SceneSelect)sel);
	}
}

void Scene::SkinMenu()
{
	cout << "skin" << endl;
	if (InputMgr::GetKeyDown(Keyboard::S)) {
		sel++;
		SceneMgr::GetInstance()->SetScene((SceneSelect)sel);
	}
}

void Scene::Solo()
{

	cout << player[0].GetPos().x << " " << player[0].GetPos().y << endl;

	if (InputMgr::GetKeyDown(Keyboard::Left)){
		player[0].Chop(Sides::Left);
		UpdateBranches()
	}
	if (InputMgr::GetKeyDown(Keyboard::Right))
		player[0].Chop(Sides::Right);


}

void Scene::Couple()
{

}

void Scene::Update(float dt)
{
	switch (sel) {
	case 0:
		StartMeun();
		break;
	case 1:
		MainMenu();
		break;

	case 2:
		SkinMenu();
		break;

	case 3:
		Solo();
		break;
	}
	//    sceneCollect[sel]->Draw(e);
	//case 4:
	//    sceneCollect[sel]->Draw(e);
	//    break;
	//} 
}