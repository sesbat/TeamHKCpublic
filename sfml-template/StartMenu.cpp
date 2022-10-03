#include "StartMenu.h"
#include <iostream>
#include "InputMgr.h"
#include "sceneMgr.h"

using namespace std; 
StartMenu::StartMenu()
{
	startGraphic.SetTex("graphics/Start.png");
	startGraphic.SetOrigin(Origins::MC);
	startGraphic.SetPos({ 1920 * 0.5f, 1080 * 0.5f });
}

void StartMenu::Draw(RenderWindow& e)
{
	Scene::Draw(e);
	//여기다가 엔터투 스타트이미지 넣으면됨
	cout << "startmenu draw" << endl;
	startGraphic.Draw(e);
}

void StartMenu::Update(float dt)
{
	if (setBGM)
	{
		sdMgr.SoundPlay(SoundChoice::TitleSound);
		setBGM = false;
	}

	if (InputMgr::GetKeyDown(Keyboard::Return)) {
		sdMgr.StopPlay();
		SceneMgr::GetInstance()->SetScene(SceneSelect::MainMenu);
	}
	cout << "startmenu " << endl;

}
