#include "MainMenu.h"
#include <iostream>
#include"sceneMgr.h"

using namespace std;

MainMenu::MainMenu()
{
	tree.SetTex("graphics/tree.png");
	tree.SetOrigin(Origins::TC);
	tree.SetPos({ 1920 / 2,0 });


	/*********************************** Graphic ************************************/
	font.loadFromFile("fonts/Mabinogi_Classic_TTF.ttf");
	onePlayer.SetAll(font, 100, Color::Black, "1 P", { 1920 * 0.2f, 1080 * 0.5f });
	twoPlayer.SetAll(font, 100, Color::Black, "2 P", { 1920 * 0.8f, 1080 * 0.5f });

	playMode.SetTex("graphics/PlayMode.png");
	playMode.SetOrigin(Origins::MC);
	playMode.SetPos({ 1920 * 0.5f, 1080 * 0.2f });

	choice.SetTex("graphics/Choice.png");
	choice.SetOrigin(Origins::MC);
	/**********************************************************************************/
}

void MainMenu::Draw(RenderWindow& e)
{
	Scene::Draw(e);
	tree.Draw(e);
	cout << "main draw" << endl;
	


	/*********************************** Graphic ************************************/
	onePlayer.Draw(e);
	twoPlayer.Draw(e);
	playMode.Draw(e);
	
	if (mode == 0)
		choice.SetPos({ 1920 * 0.2f, 1080 * 0.51f });
	else
		choice.SetPos({ 1920 * 0.8f, 1080 * 0.51f });

	choice.Draw(e);
	/**********************************************************************************/
}

void MainMenu::Update(float dt)
{
	if (setBGM)
	{
		sdMgr.SoundPlay(SoundChoice::TitleSound);
		setBGM = false;
	}

	//위에 draw함수에 화살표왼쪽=1p 오른쪽 =2p 텍스트 넣어줘
	if (InputMgr::GetKeyDown(Keyboard::Return))
	{
		sdMgr.StopPlay();
		setBGM = true;
		SceneMgr::GetInstance()->SetScene(SceneSelect::SkinMenu);
	}

	if (InputMgr::GetKeyDown(Keyboard::Left)) 
		mode = 0;
	if (InputMgr::GetKeyDown(Keyboard::Right)) 
		mode = 1;

	cout << "main" << endl;
}