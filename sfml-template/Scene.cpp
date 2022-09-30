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
}

void Scene::StartMeun()
{
	std::cout << "test" << std::endl;
	if (InputMgr::GetKeyDown(Keyboard::A)) {
		sel=3;
		SceneMgr::GetInstance()->SetScene((SceneSelect)sel);
	}
}

void Scene::MainMenu()
{
	std::cout << "this is menu" << std::endl;

}

void Scene::SkinMenu()
{
}

void Scene::Solo()
{

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

		//case 2:
		//    sceneCollect[sel]->Draw(e);
		//    break;

	case 3:
		Solo();

		break;
	}
	//case 4:
	//    sceneCollect[sel]->Draw(e);
	//    break;
	//} 
}