#include "Solo.h"
#include "sceneMgr.h"

Solo::Solo()
{
	GetPlayer1()->SetTex(tempSkin);
	GetPlayer1()->SetPos({ 1920 / 2 - 250,900 });
	tree.SetTex("graphics/tree.png");
	tree.SetOrigin(Origins::TC);
	tree.SetPos({ 1920 / 2,0 });
	Init();
}

Solo::~Solo()
{
}

void Solo::Draw(RenderWindow& e)
{
	Scene::Draw(e);
	player1.Draw(e);
	tree.Draw(e);
}

void Solo::Update(float dt)
{
	if(updateInit==false){
		player1.SetOriginalPos({ 1920 / 2 - 250,900 }, { 1920 / 2 + 250,900 });
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
}

void Solo::Init()
{
	GetPlayer1()->SetOriginalPos({ 1920 / 2 - 250,900 }, { 1920 / 2 + 250,900 });

}
