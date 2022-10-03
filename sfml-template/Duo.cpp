#include"Duo.h"
#include "sceneMgr.h"

Duo::Duo()
{
	player1.SetOrigin(Origins::BC);
	tree.SetTex("graphics/tree.png");
	tree.SetOrigin(Origins::TC);
	tree.SetPos({ 400,0 });
	tree2.SetTex("graphics/tree.png");
	tree2.SetOrigin(Origins::TC);
	tree2.SetPos({ 1500 ,0 });
	tree.SetScale({0.65f, 1});
	tree2.SetScale({ 0.65f, 1 });


	font.loadFromFile("fonts/Mabinogi_Classic_TTF.ttf");

	choice.SetTex("graphics/Choice.png");
	choice.SetOrigin(Origins::MC);

	reStart.SetAll(font, 80, Color::Blue, "RE  START ?", { 1920 * 0.5f, 1080 * 0.4f });
	mainMenu.SetAll(font, 80, Color::Blue, "MAIN  MENU", { 1920 * 0.5f, 1080 * 0.6f });


	score_1P.SetAll(font, 70, Color::Black, "SCORE = " + to_string(scoreNum_1P), { (1920 * 0.5f) + 30, 0 });
	score_1P.SetOrigin(Origins::TL);
	score_2P.SetAll(font, 70, Color::Black, "SCORE = " + to_string(scoreNum_2P), { (1920 * 0.5f) - 100, 0 });
	score_2P.SetOrigin(Origins::TR);


	win.SetTex("graphics/Win.png");
	win.SetOrigin(Origins::TL);
	lose.SetTex("graphics/Lose.png");
	lose.SetOrigin(Origins::TL);
	middleLine.SetTex("graphics/MiddleLine.png");
	middleLine.SetOrigin(Origins::MC);
	middleLine.SetPos({1920 * 0.5f, 1080 * 0.5f});

	p1_Die.SetTex("graphics/Duo_Die.png");
	p1_Die.SetOrigin(Origins::MC);
	p1_Die.SetPos({ ((1920 * 0.5f) * 0.5f) + 1920 * 0.5f, 150 });
	p2_Die.SetTex("graphics/Duo_Die.png");
	p2_Die.SetOrigin(Origins::MC);
	p2_Die.SetPos({ (1920 * 0.5f) * 0.5f, 150 });


	draw1.SetTex("graphics/Draw.png");
	draw1.SetOrigin(Origins::TL);
	draw1.SetPos({ 0, 0 });
	draw2.SetTex("graphics/Draw.png");
	draw2.SetOrigin(Origins::TL);
	draw2.SetPos({ 1920 * 0.5f, 0 });


	Init();	
	timerBarSize.x = 400;
	timerBarSize.y = 80;
	timerBar1.setSize(timerBarSize);
	timerBar1.setFillColor(Color::Red);
	timerBar1.setPosition(
		1920 * 0.2f - timerBarSize.x * 0.2f,
		1080 - 100);

	timerBar2.setSize(timerBarSize);
	timerBar2.setFillColor(Color::Red);
	timerBar2.setPosition(
		1920 * 0.8f - timerBarSize.x * 0.8f,
		1080 - 100);
}

Duo::~Duo()
{
}

void Duo::Init()
{
	player1.SetOriginalPos({ 1300 ,900 }, { 1700 ,900 });
	player1.SetScale({0.8f, 0.8f});

	player2.SetOriginalPos({ 200,900 }, { 600,900 });
	player2.SetScale({ 0.8f, 0.8f });
}

void Duo::Draw(RenderWindow& e)
{
	Scene::Draw(e);
	tree.Draw(e);
	tree2.Draw(e);
	player1.Draw(e);
	player2.Draw(e);
	e.draw(timerBar1);
	e.draw(timerBar2);


	if (player1.GetAlive() && player2.GetAlive())
	{
		score_1P.Draw(e);
		score_2P.Draw(e);
	}

	if (!player1.GetAlive() && player2.GetAlive())
	{
		p1_Die.Draw(e);
		score_1P.Draw(e);
		score_2P.Draw(e);
	}

	else if (player1.GetAlive() && !player2.GetAlive())
	{
		p2_Die.Draw(e);
		score_1P.Draw(e);
		score_2P.Draw(e);
	}


	if (!player1.GetAlive() && !player2.GetAlive() && !resultScreen)
	{
		if (scoreNum_1P > scoreNum_2P)
		{
			win.SetPos({ 1920 * 0.5f, 0 });
			lose.SetPos({ 0, 0 });
			win.Draw(e);
			lose.Draw(e);
		}
		else if (scoreNum_1P < scoreNum_2P)
		{
			win.SetPos({ 0, 0 });
			lose.SetPos({ 1920 * 0.5f, 0 });
			win.Draw(e);
			lose.Draw(e);
		}
		else if (scoreNum_1P == scoreNum_2P)
		{
			draw1.Draw(e);
			draw2.Draw(e);
		}
	}

	if (resultScreen)
	{
		reStart.Draw(e);
		mainMenu.Draw(e);

		if (choicePlay == 0)
			choice.SetPos({ (1920 * 0.5f) + 5, (1080 * 0.4f) + 15});
		else
			choice.SetPos({ (1920 * 0.5f) + 5, (1080 * 0.6f) + 15});

		choice.Draw(e);
	}
	else
		middleLine.Draw(e);
}

void Duo::Update(float dt)
{
	timer1 -= dt;
	timer2 -= dt;

	if (updateInit == false) {
		Init();
		updateInit = true;
	}

	if (InputMgr::GetKeyDown(Keyboard::Escape)) {
		SceneMgr::GetInstance()->SetScene(SceneSelect::MainMenu);
		updateInit = false;
	}
	//여기에 실제게임플레이 입력,정보 브렌치 업데이트
	if (player1.GetAlive()) {
		if (InputMgr::GetKeyDown(Keyboard::Left)) {
			player1.SetAxePos(40, 40);
			player1.Chop(Sides::Left);
			sdMgr.SoundPlay(SoundChoice::ChopSound);
			scoreNum_1P += 1;
			score_1P.SetString("SCORE = " + to_string(scoreNum_1P));
		}
		if (InputMgr::GetKeyDown(Keyboard::Right))
		{
			player1.SetAxePos(40, 40);
			player1.Chop(Sides::Right);
			sdMgr.SoundPlay(SoundChoice::ChopSound);
			scoreNum_1P += 1;
			score_1P.SetString("SCORE = " + to_string(scoreNum_1P));
		}
		if (InputMgr::GetKeyUp(Keyboard::Left) || InputMgr::GetKeyUp(Keyboard::Right))
			player1.SetChop(false);
		if (InputMgr::GetKey(Keyboard::Left) || InputMgr::GetKey(Keyboard::Right))
			player1.SetAxePos(40, 40);
	}
	if (InputMgr::GetKeyDown(Keyboard::Q)) {
		if (!player1.GetAlive())
		{
			player1.Init();
			player1.SetAlive(true);
		}
		else
		{
			scoreResultNum_1P = scoreNum_1P;
			player1.Die();
			sdMgr.SoundPlay(SoundChoice::DeathSound);
			dt = 0;
		}
	}
	////////////////////////////////////////////////////////
	if (player2.GetAlive()) {
		if (InputMgr::GetKeyDown(Keyboard::A)) {
			player2.SetAxePos(40, 40);
			player2.Chop(Sides::Left);
			sdMgr.SoundPlay(SoundChoice::ChopSound);
			scoreNum_2P += 1;
			score_2P.SetString("SCORE = " + to_string(scoreNum_2P));
		}
		if (InputMgr::GetKeyDown(Keyboard::D))
		{
			player2.SetAxePos(40, 40);
			player2.Chop(Sides::Right);
			sdMgr.SoundPlay(SoundChoice::ChopSound);
			scoreNum_2P += 1;
			score_2P.SetString("SCORE = " + to_string(scoreNum_2P));
		}
		if (InputMgr::GetKeyUp(Keyboard::A) || InputMgr::GetKeyUp(Keyboard::D))
			player2.SetChop(false);

		if (InputMgr::GetKey(Keyboard::A) || InputMgr::GetKey(Keyboard::D))
			player2.SetAxePos(40, 40);
	}

	if (InputMgr::GetKeyDown(Keyboard::Space)) {
		if (!player2.GetAlive())
		{
			player2.Init();
			player2.SetAlive(true);
		}
		else
		{
			scoreResultNum_2P = scoreNum_2P;
			player2.Die();
			sdMgr.SoundPlay(SoundChoice::DeathSound);
			dt = 0;
		}
	}
	float normTime1 = timer1 / duration; // 정규화
	float normTime2 = timer2 / duration;
	float timerSizeX1 = timerBarSize.x * normTime1;
	float timerSizeX2 = timerBarSize.x * normTime2;

	timerBar1.setSize({ timerSizeX1, timerBarSize.y });
	timerBar2.setSize({ timerSizeX2,timerBarSize.y });
	timerBar1.setPosition
	(1920 * 0.2f - timerSizeX1 * 0.2f, 1080 - 100);
	timerBar2.setPosition
	(1920 * 0.8f - timerSizeX2 * 0.8f, 1080 - 100);


	if (!player1.GetAlive() && !player2.GetAlive())
	{
		if (InputMgr::GetKeyDown(Keyboard::Return) && resultScreen == false)
			resultScreen = true;

		else if (InputMgr::GetKeyDown(Keyboard::Return) && resultScreen == true)
		{
			if (choicePlay == 0)
			{
				player1.Init();
				player2.Init();
				// 다시시작
			}
			else
			{
				// 메뉴화면으로
			}
			player1.SetAlive(true);
			player2.SetAlive(true);
			resultScreen = false;
		}


		if (InputMgr::GetKeyDown(Keyboard::Up))
			choicePlay = 0;
		if (InputMgr::GetKeyDown(Keyboard::Down))
			choicePlay = 1;
	}
}
