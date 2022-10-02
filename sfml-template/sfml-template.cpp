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
	SoundMgr sdMgr;
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


	int scoreNum = 0;
	float duration = 12.0f;
	float timer = duration;
	/***************************** Letter ***********************************/
	string mabiFont = "fonts/Mabinogi_Classic_TTF.ttf";
	Font font;
	font.loadFromFile(mabiFont);
	Letter deathText, restartText, menuText, pte, ptrh, score, scoreResult, timerText;
	deathText.SetAll(font, 200, Color::White, "YOU  DIE  !", { WIDTH * 0.5f, HEIGHT * 0.25f });
	restartText.SetAll(font, 80, Color::Blue, "RE  START ?", { WIDTH * 0.3f, HEIGHT * 0.55f });
	menuText.SetAll(font, 80, Color::Blue, "MAIN  MENU", { WIDTH * 0.7f, HEIGHT * 0.55f });
	pte.SetAll(font, 45, Color::White, "( PRESS  TO  ENTER )", { WIDTH * 0.3f, HEIGHT * 0.6f });
	ptrh.SetAll(font, 45, Color::White, "( PRESS  TO  RSHIFT )", { WIDTH * 0.7f, HEIGHT * 0.6f });


	score.SetAll(font, 100, Color::Black, "SCORE = " + to_string(scoreNum), {0, 0});
	score.SetOrigin(Origins::TL);
	/*************************************************************************/


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
		

<<<<<<< HEAD
		

		if (!p.GetAlive() && (int)SceneMgr::GetInstance()->GetSel() == 3)
=======
		// Solo Mode - Show ScoreText, Score++
		if ((int)SceneMgr::GetInstance()->GetSel() == 3)
>>>>>>> origin/Develop
		{
			/******************** Timer(Not Completed) ********************/
			float deltaTime = isPause ? 0.f : dt.asSeconds();
			timer -= deltaTime;
			float nomalTime = timer / duration;
			if (InputMgr::GetKeyDown(Keyboard::Space))
				!isPause;

			timerText.SetAll(font, 100, Color::Black, to_string((int)timer), { WIDTH * 0.5f, HEIGHT - 100 });
			timerText.SetOrigin(Origins::MC);
			/***************************************************************/

			score.Draw(window);
			timerText.Draw(window);

			// 살아있을때 엔터눌러도 초기화됨 (고쳐야함)
			if (InputMgr::GetKeyDown(Keyboard::RShift) || InputMgr::GetKeyDown(Keyboard::Return))
			{
				scoreNum = 0;
				score.SetString("SCORE = " + to_string(scoreNum));
			}

			if (p.GetAlive())
			{
				if (InputMgr::GetKeyDown(Keyboard::Left) || InputMgr::GetKeyDown(Keyboard::Right))
				{
					scoreNum += 1;
					score.SetString("SCORE = " + to_string(scoreNum));
				}
			}
			if (!p.GetAlive())
			{
				scoreResult.SetAll(font, 100, Color::Yellow, "SCORE : " + to_string(scoreNum),
					{ WIDTH * 0.5f, HEIGHT * 0.4f});
				scoreResult.Draw(window);

				score.SetString("SCORE = " + to_string(scoreNum));
				deathText.Draw(window);
				restartText.Draw(window);
				menuText.Draw(window);
				pte.Draw(window);
				ptrh.Draw(window);
			}
		}

		window.display();
	}

	return 0;
}

