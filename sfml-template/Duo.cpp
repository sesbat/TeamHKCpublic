#include"Duo.h"
#include "sceneMgr.h"

Duo::Duo()
{
	player1.SetOrigin(Origins::BC);
	tree.SetTex("graphics/tree.png");
	tree.SetOrigin(Origins::TC);
	tree.SetPos({ 400,0 });
	tree2.SetTex("graphics/tree.png");
	tree2.SetOrigin(Origins::TC);
	tree2.SetPos({ 1500 ,0 });
	Init();	
}

Duo::~Duo()
{
}

void Duo::Init()
{
	player2.SetOriginalPos({ 100,900 }, { 600,900 });
	player1.SetOriginalPos({ 1200 ,900 }, { 1800 ,900 });

}

void Duo::Draw(RenderWindow& e)
{
	Scene::Draw(e);
	tree.Draw(e);
	tree2.Draw(e);
	player1.Draw(e);
	player2.Draw(e);
}

void Duo::Update(float dt)
{
	if (updateInit == false) {
		Init();
		updateInit = true;
	}

	if (InputMgr::GetKeyDown(Keyboard::Escape)) {
		SceneMgr::GetInstance()->SetScene(SceneSelect::MainMenu);
		updateInit = false;
	}
	//여기에 실제게임플레이 입력,정보 브렌치 업데이트
	if (player1.GetAlive()) {
		if (InputMgr::GetKeyDown(Keyboard::Left)) {
			player1.Chop(Sides::Left);
			sdMgr.SoundPlay(SoundChoice::ChopSound);
		}
		if (InputMgr::GetKeyDown(Keyboard::Right))
		{
			player1.Chop(Sides::Right);
			sdMgr.SoundPlay(SoundChoice::ChopSound);
		}
	}
	if (InputMgr::GetKeyDown(Keyboard::Space)) {
		if (!player1.GetAlive())
		{
			player1.Init();
			player1.SetAlive(true);
		}
		else
		{
			player1.Die();
			sdMgr.SoundPlay(SoundChoice::DeathSound);
			dt = 0;
		}
	}
	////////////////////////////////////////////////////////
	if (player2.GetAlive()) {
		if (InputMgr::GetKeyDown(Keyboard::A)) {
			player2.Chop(Sides::Left);
			sdMgr.SoundPlay(SoundChoice::ChopSound);
		}
		if (InputMgr::GetKeyDown(Keyboard::D))
		{
			player2.Chop(Sides::Right);
			sdMgr.SoundPlay(SoundChoice::ChopSound);
		}
	}
	if (InputMgr::GetKeyDown(Keyboard::Space)) {
		if (!player2.GetAlive())
		{
			player2.Init();
			player2.SetAlive(true);
		}
		else
		{
			player2.Die();
			sdMgr.SoundPlay(SoundChoice::DeathSound);
			dt = 0;
		}
	}
}
