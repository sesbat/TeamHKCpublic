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



	/***************************** Letter Change *****************************/
	Font font;
	font.loadFromFile("fonts/Mabinogi_Classic_TTF.ttf");
	Text deathText, restartText, menuText, pte, ptrh;

	deathText.setFont(font);
	deathText.setCharacterSize(100);
	deathText.setFillColor(Color::White);
	deathText.setString("You  Die  !");
	Letter::SetOrigin(deathText, Origins::MC);
	deathText.setPosition(WIDTH * 0.5f, HEIGHT * 0.4f);

	restartText.setFont(font);
	restartText.setCharacterSize(80);
	restartText.setFillColor(Color::Blue);
	restartText.setString("RE  START ?");
	Letter::SetOrigin(restartText, Origins::MC);
	restartText.setPosition(WIDTH * 0.3f, HEIGHT * 0.55f);

	menuText.setFont(font);
	menuText.setCharacterSize(80);
	menuText.setFillColor(Color::Blue);
	menuText.setString("MAIN  MENU");
	Letter::SetOrigin(menuText, Origins::MC);
	menuText.setPosition(WIDTH * 0.7f, HEIGHT * 0.55f);

	pte.setFont(font);
	pte.setCharacterSize(45);
	pte.setFillColor(Color::White);
	pte.setString("(PRESS  TO  ENTER  KEY)");
	Letter::SetOrigin(pte, Origins::MC);
	pte.setPosition(WIDTH * 0.3f, HEIGHT * 0.6f);

	ptrh.setFont(font);
	ptrh.setCharacterSize(45);
	ptrh.setFillColor(Color::White);
	ptrh.setString("(PRESS  TO  RSHIFT  KEY)");
	Letter::SetOrigin(ptrh, Origins::MC);
	ptrh.setPosition(WIDTH * 0.7f, HEIGHT * 0.6f);
	/*************************************************************************/


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


		if (!p.GetAlive() && (int)SceneMgr::GetInstance()->GetSel() == 3)
		{
			window.draw(deathText);
			window.draw(restartText);
			window.draw(menuText);
			window.draw(pte);
			window.draw(ptrh);
		}

		window.display();
	}

	return 0;
}

