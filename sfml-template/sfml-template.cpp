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

using namespace sf;
using namespace std;
#define WIDTH 1920
#define HEIGHT 1080
int main()
{
	//파일 불러오기

	VideoMode vm(WIDTH, HEIGHT);

	RenderWindow window(vm, "Timber!!", Style::Default);

	Graphics tree("graphics/tree.png", { WIDTH / 2, 0 });
	Graphics back("graphics/background.png");
	Graphics startText("graphics/Start.png");
	MovingObj bee("graphics/bee.png");
	MovingObj cloud("graphics/cloud.png");

	list<Graphics> env;
	list<MovingObj> movingObj;
	movingObj.push_back(bee);
	movingObj.push_back(cloud);

	Player p("graphics/player.png");
	p.SetPos({ 800,800 });
	env.push_back(back);                                                                                                                                                                                

	startText.SetPos({ WIDTH / 2, HEIGHT - 100 });
	startText.SetOrigin(Origins::MC);
	env.push_back(startText);
	tree.SetOrigin(Origins::TC);

	Scene startMenu(env, movingObj, (int)SceneSelect::StartMenu);
	env.pop_back();
	Scene SkinMenu(env, movingObj, &p, (int)SceneSelect::SkinMenu);
	env.push_back(tree);
	Scene SoloPlay(env, movingObj, &p, (int)SceneSelect::Solo);

	movingObj.clear();
	env.clear();
	env.push_back(back);

	Scene MainMeun(env, movingObj, (int)SceneSelect::MainMenu);

	SceneMgr::GetInstance()->AddScene(SceneSelect::StartMenu, &startMenu);
	SceneMgr::GetInstance()->AddScene(SceneSelect::MainMenu, &MainMeun);
	SceneMgr::GetInstance()->AddScene(SceneSelect::SkinMenu, &SkinMenu);
	SceneMgr::GetInstance()->AddScene(SceneSelect::Solo, &SoloPlay);


	SceneMgr::GetInstance()->SetScene(SceneSelect::StartMenu);

	InputMgr::Set();
	Clock clock;
	while (window.isOpen()) {
		InputMgr::ClearInput();
		Time dt = clock.restart();
		Event ev;
		while (window.pollEvent(ev))
		{
			InputMgr::UpdateInput(ev);
		}
		SceneMgr::GetInstance()->Draw(window);
		SceneMgr::GetInstance()->Update(dt.asSeconds());

		if (InputMgr::GetKeyDown(Keyboard::Key::Escape))
		{
			window.close();
		}

		window.display();
	}

	return 0;
}

