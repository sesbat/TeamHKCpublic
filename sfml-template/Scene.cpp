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
<<<<<<< HEAD

=======
	if (InputMgr::GetKeyDown(Keyboard::Key::Space))
	{
		if (player[0].GetAlive())
		{
			player[0].Die();
			sdMgr.SoundPlay(SoundChoice::DeathSound);
		}
		else
		{
			player[0].Init();
		}
		return;
	}
	if (!player[0].GetAlive())
		return;

	if (!player[0].GetChop()) //!isChopping
	{
		if (InputMgr::GetKey(Keyboard::Key::Left))
		{
			player[0].Chop(Sides::Left);
			player[0].SetChop(true);
			sdMgr.SoundPlay(SoundChoice::ChopSound);

		}
		if (InputMgr::GetKey(Keyboard::Key::Right))
		{
			player[0].Chop(Sides::Right);
			player[0].SetChop(true);
			sdMgr.SoundPlay(SoundChoice::ChopSound);
		}
	}
	else {

		if (player[0].GetSide() == Sides::Left && InputMgr::GetKeyUp(Keyboard::Key::Left))
		{
			player[0].SetChop(false);
		}
		if (player[0].GetSide() == Sides::Right && InputMgr::GetKeyUp(Keyboard::Key::Right))
		{
			player[0].SetChop(false);
		}
	}
>>>>>>> origin/Develop
}

void Scene::Couple()
{
}

void Scene::Update(float dt)
{
<<<<<<< HEAD

	switch (sel) {
	case 0:
		StartMeun();
		break;
	case 1:
		MainMenu();
		break;
=======
   
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
    //    sceneCollect[sel]->Draw(e);
>>>>>>> origin/Develop

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