#include "Scene.h"
#include "InputMgr.h"
#include "sceneMgr.h"
#include "Letter.h"
#include <iostream>

std::random_device Scene::rd;
std::mt19937 Scene::gen(Scene::rd());
String Scene::tempSkin = "graphics/player.png";
String Scene::tempSkin2 = "graphics/player.png";
bool Scene::mode = 0;
Player Scene::player1;
Player Scene::player2;
Scene::Scene()
{
	back.SetTex("graphics/background.png");
	env.push_back(back);

	movingObj.push_back(new MovingObj("graphics/bee.png"));
	//for (int i = 0; i < 3; i++) {
	//	movingObj.push_back(new MovingObj("graphics/cloud.png"));
	//	movingObj[i]->Set({ 200,400 }, { 100, 400 }, { 1920,RandomRange(0,400) }, { -10,0 });
	//	movingObj[i]->SetPos({1920,RandomRange(0,400)});
	//}
}

int Scene::RandomRange(int min, int maxExclude)
{
	return (gen() % (maxExclude - min)) + min;
}


Scene::~Scene()
{
	for (auto& v : movingObj) {
		delete v;
	}
	movingObj.clear();
}

void Scene::Draw(RenderWindow& e)
{

	for (auto& v : env)
		v.Draw(e);
	for (auto& v : movingObj) {
		v->Draw(e);
	}
}

void Scene::Update(float dt)
{
	/*for (auto& v : movingObj) {
		Vector2f pos = v->GetPos();

		float distanceX = endPos.x - pos.x;

		v->Translate(direction * speed * dt);
	}*/
}
//void Scene::StartMeun(float dt)
//{
//	std::cout << "Start" << std::endl;
//	if (InputMgr::GetKeyDown(Keyboard::Return)) {
//		sel++;
//		SceneMgr::GetInstance()->SetScene((SceneSelect)sel);
//	}
//}
//
//void Scene::MainMenu(float dt)
//{
//	cout << "main" << endl;
//	if (InputMgr::GetKeyDown(Keyboard::Return)) {
//		sel++;
//		SceneMgr::GetInstance()->SetScene((SceneSelect)sel);
//	}
//}
//
//void Scene::SkinMenu(float dt)
//{
//	cout << "skin" << endl;
//	if (InputMgr::GetKeyDown(Keyboard::Right)) {
//		player->SetSkin(1);
//	}
//	else if (InputMgr::GetKeyDown(Keyboard::Left)) {
//		player->SetSkin(-1);
//	}
//	if (InputMgr::GetKeyDown(Keyboard::Return)) {
//		sel++;
//		SceneMgr::GetInstance()->SetScene((SceneSelect)sel);
//	}
//}
//
//void Scene::Solo(float dt)
//{
//	// Pause
//	if (InputMgr::GetKeyDown(Keyboard::D))
//		player->SetPause();
//
//	if (player->GetPause() == true)
//	{
//		
//	}
//
//	else if (player->GetPause() == false)
//	{
//		if (player->GetAlive())
//		{
//			if (InputMgr::GetKeyDown(Keyboard::Left))
//			{
//				player->Chop(Sides::Left);
//				sdMgr.SoundPlay(SoundChoice::ChopSound);
//			}
//			if (InputMgr::GetKeyDown(Keyboard::Right))
//			{
//				player->Chop(Sides::Right);
//				sdMgr.SoundPlay(SoundChoice::ChopSound);
//			}
//		}
//	}
//
//
//	if (InputMgr::GetKeyDown(Keyboard::Space)){
//		if (!player->GetAlive()) 
//		{
//			player->Init();
//			player->SetAlive(true);
//		}
//		else
//		{
//			player->Die();
//			sdMgr.SoundPlay(SoundChoice::DeathSound);
//			dt = 0;
//		}
//	}
//	if (!(InputMgr::GetKey(Keyboard::Left)||InputMgr::GetKey(Keyboard::Right))) 
//	{
//		player->SetChop(false);
//	}
//
//	if (!player->GetAlive())
//	{
//		if (InputMgr::GetKeyDown(Keyboard::Left) && player->GetChoice() > 1)
//			player->SubChoice();
//		if (InputMgr::GetKeyDown(Keyboard::Right) && player->GetChoice() < 2)
//			player->AddChoice();
//
//		if (InputMgr::GetKeyDown(Keyboard::Return))
//		{
//			if (player->GetChoice() == 1)
//			{
//				player->Init();
//				SceneMgr::GetInstance()->SetScene((SceneSelect)sel);
//			}
//			if (player->GetChoice() == 2)
//			{
//				sel = 1;
//				player->Init();
//				player->SetAlive(true);
//				player->SetSide(Sides::Left);
//				SceneMgr::GetInstance()->SetScene((SceneSelect)sel);
//			}
//		}
//	}
//}
//
//void Scene::Couple(float dt)
//{
//
//}

