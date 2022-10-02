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

	Solo soloPlay;
	Duo duo;
	StartMenu start;
	MainMenu Menu;
	SkinMenu Skin;

	SceneMgr::GetInstance()->AddScene(SceneSelect::StartMenu, &start);
	SceneMgr::GetInstance()->AddScene(SceneSelect::MainMenu, &Menu);
	SceneMgr::GetInstance()->AddScene(SceneSelect::SkinMenu, &Skin);
	SceneMgr::GetInstance()->AddScene(SceneSelect::Solo, &soloPlay);
	SceneMgr::GetInstance()->AddScene(SceneSelect::Couple, &duo);


	/************************ skin ****************************/
	Graphics skinSelect("graphics/SkinSelect.png", { WIDTH * 0.5f, 100 });
	skinSelect.SetOrigin(Origins::MC);
	/*************************************************************/


	int scoreNum = 0;
	float duration = 12.0f;
	float timer = duration;
	/***************************** Letter (Die) ***********************************/
	Graphics deathText("graphics/Die.png", { WIDTH * 0.5f, HEIGHT * 0.25f });
	deathText.SetOrigin(Origins::MC);
	Graphics choiceStart("graphics/Choice.png");
	choiceStart.SetOrigin(Origins::MC);

	string mabiFont = "fonts/Mabinogi_Classic_TTF.ttf";
	Font font;
	font.loadFromFile(mabiFont);
	Letter restartText, menuText, score, scoreResult, timerText;
	restartText.SetAll(font, 80, Color::Blue, "RE  START ?", { WIDTH * 0.2f, HEIGHT * 0.565f });
	menuText.SetAll(font, 80, Color::Blue, "MAIN  MENU", { WIDTH * 0.8f, HEIGHT * 0.565f });

	score.SetAll(font, 100, Color::Black, "SCORE = " + to_string(scoreNum), { 0, 0 });
	score.SetOrigin(Origins::TL);
	/*************************************************************************/

	Vector2f timerBarSize = { 1200, 50 };
	RectangleShape timerBar;
	timerBar.setSize(timerBarSize);
	timerBar.setFillColor(Color::Red);
	timerBar.setPosition(WIDTH * 0.5f - timerBarSize.x * 0.5f, HEIGHT - 80);

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

		// Skin Mode - SkinSelect image
		if ((int)SceneMgr::GetInstance()->GetSel() == 2)
			skinSelect.Draw(window);


		// Solo Mode - Show ScoreText, Score++
		if ((int)SceneMgr::GetInstance()->GetSel() == 3)
		{
			if (InputMgr::GetKeyDown(Keyboard::Return)) // Enter
			{
				if (timer > 0.f)
				{
					isPause = !isPause;
					p.SetPause();
				}
			}

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
				if (p.GetChoice() == 1)
					choiceStart.SetPos({ WIDTH * 0.202f, HEIGHT * 0.575f });
				else if (p.GetChoice() == 2)
					choiceStart.SetPos({ WIDTH * 0.802f, HEIGHT * 0.575f });

				scoreResult.SetAll(font, 100, Color::White, "SCORE : " + to_string(scoreNum),
					{ WIDTH * 0.5f, HEIGHT * 0.4f });
				scoreResult.Draw(window);

				deathText.Draw(window);
				score.SetString("SCORE = " + to_string(scoreNum));
				choiceStart.Draw(window);
				restartText.Draw(window);
				menuText.Draw(window);
			}
		}

		window.display();
	}

	return 0;
}