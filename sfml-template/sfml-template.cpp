#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include "Graphics.h"
#include "MovingObj.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "InputMgr.h"
#include "SoundMgr.h"
#include <list>
#include "Letter.h"
#include "Duo.h"
#include "Solo.h"
#include "StartMenu.h"
#include "MainMenu.h"
#include "SkinMenu.h"
using namespace sf;
using namespace std;
#define WIDTH 1920
#define HEIGHT 1080
int main()
{
	//파일 불러오기

	VideoMode vm(WIDTH, HEIGHT);
	SoundMgr sdMgr;
	RenderWindow window(vm, "Timber!!", Style::Default);

	SkinMenu Skin;
	Solo soloPlay;
	Duo duo;
	StartMenu start;
	MainMenu Menu;

	SceneMgr::GetInstance()->AddScene(SceneSelect::StartMenu, &start);
	SceneMgr::GetInstance()->AddScene(SceneSelect::MainMenu, &Menu);
	SceneMgr::GetInstance()->AddScene(SceneSelect::SkinMenu, &Skin);
	SceneMgr::GetInstance()->AddScene(SceneSelect::Solo, &soloPlay);
	SceneMgr::GetInstance()->AddScene(SceneSelect::Couple, &duo);

	InputMgr::Set();
	Clock clock;
	bool isPause = false;
	while (window.isOpen())
	{
		InputMgr::ClearInput();
		Time dt = clock.restart();
		Event ev;
		while (window.pollEvent(ev))
		{
			InputMgr::UpdateInput(ev);
		}
		SceneMgr::GetInstance()->Draw(window);
		SceneMgr::GetInstance()->Update(dt.asSeconds());
		
		if (InputMgr::GetKeyDown(Keyboard::Key::Num0))
		{
			window.close();
		}

		window.display();
	}

	return 0;
}