#include "Scene.h"
#include "InputMgr.h"
#include "sceneMgr.h"
#include "Letter.h"
#include <iostream>

Scene::Scene()
{
	Graphics back("graphics/background.png");
	MovingObj bee("grpahics/bee.png");
	MovingObj cloud("graphics/cloud.png");

	env.push_back(back);
	movingObj.push_back(bee);
	movingObj.push_back(cloud);
}

Scene::~Scene()
{
}

void Scene::Draw(RenderWindow& e)
{
	for (auto v : env)
		v.Draw(e);
	for (auto v : movingObj){
		v.Draw(e);
	}
}

void Scene::StartMeun(float dt)
{
	std::cout << "Start" << std::endl;
	if (InputMgr::GetKeyDown(Keyboard::Return)) {
		sel++;
		SceneMgr::GetInstance()->SetScene((SceneSelect)sel);
	}
}

void Scene::MainMenu(float dt)
{
	cout << "main" << endl;
	if (InputMgr::GetKeyDown(Keyboard::Return)) {
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
	// Pause
	if (InputMgr::GetKeyDown(Keyboard::D))
		player->SetPause();

	if (player->GetPause() == true)
	{
		
	}

	else if (player->GetPause() == false)
	{
		if (player->GetAlive())
		{
			if (InputMgr::GetKeyDown(Keyboard::Left))
			{
				player->Chop(Sides::Left);
				sdMgr.SoundPlay(SoundChoice::ChopSound);
			}
			if (InputMgr::GetKeyDown(Keyboard::Right))
			{
				player->Chop(Sides::Right);
				sdMgr.SoundPlay(SoundChoice::ChopSound);
			}
		}
	}


	if (InputMgr::GetKeyDown(Keyboard::Space)){
		if (!player->GetAlive()) 
		{
			player->Init();
			player->SetAlive(true);
		}
		else
		{
			player->Die();
			sdMgr.SoundPlay(SoundChoice::DeathSound);
			dt = 0;
		}
	}
	if (!(InputMgr::GetKey(Keyboard::Left)||InputMgr::GetKey(Keyboard::Right))) 
	{
		player->SetChop(false);
	}

	if (!player->GetAlive())
	{
		if (InputMgr::GetKeyDown(Keyboard::Left) && player->GetChoice() > 1)
			player->SubChoice();
		if (InputMgr::GetKeyDown(Keyboard::Right) && player->GetChoice() < 2)
			player->AddChoice();

		if (InputMgr::GetKeyDown(Keyboard::Return))
		{
			if (player->GetChoice() == 1)
			{
				player->Init();
				SceneMgr::GetInstance()->SetScene((SceneSelect)sel);
			}
			if (player->GetChoice() == 2)
			{
				sel = 1;
				player->Init();
				player->SetAlive(true);
				player->SetSide(Sides::Left);
				SceneMgr::GetInstance()->SetScene((SceneSelect)sel);
			}
		}
	}
}

void Scene::Couple(float dt)
{

}

void Scene::Update(float dt)
{
	sel = (int)SceneMgr::GetInstance()->GetSel();
	switch (sel) {
	case 0:
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