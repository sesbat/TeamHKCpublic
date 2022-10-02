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


	font.loadFromFile("fonts/Mabinogi_Classic_TTF.ttf");
	dieText_1P.SetTex("graphics/Die.png");
	dieText_1P.SetOrigin(Origins::MC);
	dieText_1P.SetPos({ 1920 * 0.5f, 1080 * 0.2f });

	choice.SetTex("graphics/Choice.png");
	choice.SetOrigin(Origins::MC);

	reStart.SetAll(font, 80, Color::Blue, "RE  START ?", { 1920 * 0.2f, 1080 * 0.565f });
	mainMenu.SetAll(font, 80, Color::Blue, "MAIN  MENU", { 1920 * 0.8f, 1080 * 0.565f });


	score_1P.SetAll(font, 40, Color::Black, "SCORE = " + to_string(scoreNum_1P), { 0, 0 });
	score_1P.SetOrigin(Origins::TL);
	score_2P.SetAll(font, 40, Color::Black, "SCORE = " + to_string(scoreNum_2P), { 1920 * 0.5f, 0 });
	score_2P.SetOrigin(Origins::TL);


	scoreResult_1P.SetAll(font, 40, Color::Yellow, "SCORE : " + to_string(scoreNum_1P), { 1920 * 0.5f, 1080 * 0.5f });
	scoreResult_2P.SetAll(font, 40, Color::Yellow, "SCORE : " + to_string(scoreNum_2P), { 1920 * 0.5f, 1080 * 0.5f });

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
	player1.SetOriginalPos({ 1200 ,900 }, { 1800 ,900 });
	player2.SetOriginalPos({ 100,900 }, { 600,900 });

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
			player1.Chop(Sides::Left);
			sdMgr.SoundPlay(SoundChoice::ChopSound);
		}
		if (InputMgr::GetKeyDown(Keyboard::Right))
		{
			player1.Chop(Sides::Right);
			sdMgr.SoundPlay(SoundChoice::ChopSound);
		}
	}
	if (InputMgr::GetKeyDown(Keyboard::Space)) {
		if (!player1.GetAlive())
		{
			player1.Init();
			player1.SetAlive(true);
		}
		else
		{
			player1.Die();
			sdMgr.SoundPlay(SoundChoice::DeathSound);
			dt = 0;
		}
	}
	////////////////////////////////////////////////////////
	if (player2.GetAlive()) {
		if (InputMgr::GetKeyDown(Keyboard::A)) {
			player2.Chop(Sides::Left);
			sdMgr.SoundPlay(SoundChoice::ChopSound);
		}
		if (InputMgr::GetKeyDown(Keyboard::D))
		{
			player2.Chop(Sides::Right);
			sdMgr.SoundPlay(SoundChoice::ChopSound);
		}
	}
	if (InputMgr::GetKeyDown(Keyboard::Space)) {
		if (!player2.GetAlive())
		{
			player2.Init();
			player2.SetAlive(true);
		}
		else
		{
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

}
