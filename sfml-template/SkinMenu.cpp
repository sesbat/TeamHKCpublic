#include "SkinMenu.h"
#include"InputMgr.h"
#include "sceneMgr.h"

SkinMenu::SkinMenu() {
	tree.SetTex("graphics/tree.png");
	tree.SetOrigin(Origins::TC);
	tree.SetPos({ 1920 / 2,0 });

	skinList.push_back("graphics/player.png");
	skinList.push_back("graphics/player-.png");
	skinList.push_back("graphics/player_green.png");
	player1.SetOrigin(Origins::BC);
	player2.SetOrigin(Origins::BC);
	player1.SetPos({ 1300,900 });
	player2.SetPos({ 710,900 });

	skinSelect.SetTex("graphics/SkinSelect.png");
	skinSelect.SetOrigin(Origins::MC);
	skinSelect.SetPos({1920 * 0.5f, 1080 * 0.1f});
}
void SkinMenu::Draw(RenderWindow& e)
{
	Scene::Draw(e);
	GetPlayer1()->Draw(e);
	if (mode)
		player2.Draw(e);

	tree.Draw(e);

	skinSelect.Draw(e);
}

void SkinMenu::Update(float dt)
{
	if (setBGM)
	{
		sdMgr.SoundPlay(SoundChoice::TitleSound);
		setBGM = false;
	}

	if (InputMgr::GetKeyDown(Keyboard::Escape))
	{
		sdMgr.StopPlay();
		SceneMgr::GetInstance()->SetScene(SceneSelect::MainMenu);
	}

	if (!mode) {
		if (InputMgr::GetKeyDown(Keyboard::Return))
		{
			sdMgr.StopPlay();
			SceneMgr::GetInstance()->SetScene(SceneSelect::Solo);
		}
		if (InputMgr::GetKeyDown(Keyboard::Right)) {
			if (skin == skinList.size() - 1)
				skin = -1;
			skin++;
			tempSkin = skinList[skin];
		}if (InputMgr::GetKeyDown(Keyboard::Left)) {
			if (skin == 0)
				skin = skinList.size();
			skin--;
			tempSkin = skinList[skin];
		}
		GetPlayer1()->SetTex(tempSkin);
		player1.SetSkin(tempSkin);
	}
	else if (mode) {
		if (InputMgr::GetKeyDown(Keyboard::Return))
		{
			sdMgr.StopPlay();
			SceneMgr::GetInstance()->SetScene(SceneSelect::Couple);
		}
		if (InputMgr::GetKeyDown(Keyboard::Right)) {
			if (skin == skinList.size() - 1)
				skin = -1;
			skin++;
			tempSkin = skinList[skin];
		}if (InputMgr::GetKeyDown(Keyboard::Left)) {
			if (skin == 0)
				skin = skinList.size();
			skin--;
			tempSkin = skinList[skin];
		}
		player1.SetTex(tempSkin);
		player1.SetSkin(tempSkin);

		
		if (InputMgr::GetKeyDown(Keyboard::A)) {
			if (skin2 == skinList.size() - 1)
				skin2 = -1;
			skin2++;
			tempSkin2 = skinList[skin2];
		}if (InputMgr::GetKeyDown(Keyboard::D)) {
			if (skin2 == 0)
				skin2 = skinList.size();
			skin2--;
			tempSkin2 = skinList[skin2];
		}
		player2.SetTex(tempSkin2);
		player2.SetSkin(tempSkin2);

	}
}


