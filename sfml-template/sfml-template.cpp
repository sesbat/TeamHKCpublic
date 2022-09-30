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
	MovingObj bee("grpahics/bee.png");
	MovingObj cloud("graphics/cloud.png");
	Player p("graphics/player.png");
	//리스트, 벡터로 벌,구름 생성하면 플레이어이미지나옴 
	/*list<MovingObj> bee;
	list<MovingObj> cloud;

	for (int i = 0; i < 3; i++) {
		bee.push_back(MovingObj("graphics/bee.png"));
		cloud.push_back(MovingObj("graphics/cloud.png"));

	}
	for(auto& v:bee){
		movingObj.push_back(v);
		
	}
	for (auto& v : cloud) {
		movingObj.push_back(v);
	}

	*/

	list<Graphics> env;
	list<MovingObj> movingObj;

	movingObj.push_back(bee);
	movingObj.push_back(cloud);
	
	p.SetPos({ 1920 / 2 - 250,900 });

	env.push_back(back);
	
	tree.SetOrigin(Origins::TC);

	startText.SetOrigin(Origins::MC);
	startText.SetPos({ WIDTH / 2, HEIGHT - 100 });
	env.push_back(startText);

	Scene startMenu(env, movingObj, (int)SceneSelect::StartMenu);
	env.pop_back();
	Scene MainMeun(env, movingObj, (int)SceneSelect::MainMenu);
	env.push_back(tree);	
	Scene SkinMenu(env, movingObj, &p, (int)SceneSelect::SkinMenu);
	Scene SoloPlay(env, movingObj, &p, (int)SceneSelect::Solo);

	movingObj.clear();
	env.clear();
	


	SceneMgr::GetInstance()->AddScene(SceneSelect::StartMenu, &startMenu);
	SceneMgr::GetInstance()->AddScene(SceneSelect::MainMenu, &MainMeun);
	SceneMgr::GetInstance()->AddScene(SceneSelect::SkinMenu, &SkinMenu);
	SceneMgr::GetInstance()->AddScene(SceneSelect::Solo, &SoloPlay);

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

		if (InputMgr::GetKeyDown(Keyboard::Key::Num0))
		{
			window.close();
		}

		window.display();
	}

	return 0;
}

