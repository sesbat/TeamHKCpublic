#include "Solo.h"
#include "sceneMgr.h"

Solo::Solo()
{
	for (int i = 0; i < 100; i++) {
		auto log = new Effect("graphics/log.png", 5);
		unuseLogs.push_back(log);
	}

	GetPlayer1()->SetTex(tempSkin);
	GetPlayer1()->SetPos({ 1920 / 2 - 250,900 });
	tree.SetTex("graphics/tree.png");
	tree.SetOrigin(Origins::TC);
	tree.SetPos({ 1920 / 2,0 });


	font.loadFromFile("fonts/Mabinogi_Classic_TTF.ttf");
	dieText.SetTex("graphics/Die.png");
	dieText.SetOrigin(Origins::MC);
	dieText.SetPos({1920 * 0.5f, 1080 * 0.2f});

	choice.SetTex("graphics/Choice.png");
	choice.SetOrigin(Origins::MC);

	reStart.SetAll(font, 80, Color::Blue, "RE  START ?", { 1920 * 0.2f, 1080 * 0.565f });
	mainMenu.SetAll(font, 80, Color::Blue, "MAIN  MENU", { 1920 * 0.8f, 1080 * 0.565f });

	score.SetAll(font, 100, Color::Black, "SCORE = " + to_string(scoreNum), { 0, 0 });
	score.SetOrigin(Origins::TL);

	scoreResult.SetAll(font, 100, Color::Yellow, "SCORE : " + to_string(scoreNum), { 1920 * 0.5f, 1080 * 0.5f });

	Init();
	timerBarSize.x = 400;
	timerBarSize.y = 80;
	timerBar.setSize(timerBarSize);
	timerBar.setFillColor(Color::Red);
	timerBar.setPosition(
		1920 * 0.5f - timerBarSize.x * 0.5f,
		1080 - 100);
}

Solo::~Solo()
{
	for (auto v : unuseLogs) {
		delete v;
	}
	unuseLogs.clear();
	for (auto v : useLogs) {
		delete v;
	}
	useLogs.clear();
}

void Solo::Draw(RenderWindow& e)
{
	Scene::Draw(e);

	tree.Draw(e);
	player1.Draw(e);
	
	if (choicePlay == 0)
		choice.SetPos({ 1920 * 0.202f, 1080 * 0.575f });
	else if (choicePlay == 1)
		choice.SetPos({ 1920 * 0.802f, 1080 * 0.575f });

	if (player1.GetAlive())
	{
		score.SetString("SCORE = " + to_string(scoreNum));
		score.Draw(e);
	}

	else if (!player1.GetAlive())
	{
		scoreResult.SetString("SCORE : " + to_string(scoreResultNum));
		scoreResult.Draw(e);
		dieText.Draw(e);
		reStart.Draw(e);
		choice.Draw(e);
		mainMenu.Draw(e);
	}
	e.draw(timerBar);
	for (auto v : useLogs) 
	{
		v->Draw(e);
	}
}

void Solo::Update(float dt)
{
	Scene::Update(dt);
	timer -= dt;

	auto it = useLogs.begin();
	while (it != useLogs.end()) {
		(*it)->Update(dt);
		if (!(*it)->GetActive()) {
			unuseLogs.push_back(*it);
			it = useLogs.erase(it);
		}
		else {
			++it;
		}
	}
	
	if(updateInit==false){
		player1.SetOriginalPos({ 1920 / 2 - 250,900 }, { 1920 / 2 + 250,900 });
		updateInit = true;
	}

	if (InputMgr::GetKeyDown(Keyboard::Escape)) {
		SceneMgr::GetInstance()->SetScene(SceneSelect::MainMenu);
		updateInit = false;
	}
	//여기에 실제게임플레이 입력,정보 브렌치 업데이트
	
	if (player1.GetAlive()) {
		if (InputMgr::GetKeyDown(Keyboard::Left)) 
		{
			scoreNum += 1;
			player1.Chop(Sides::Left);
			sdMgr.SoundPlay(SoundChoice::ChopSound);
			ShowLogEffect();
		}
		if (InputMgr::GetKeyDown(Keyboard::Right))
		{
			scoreNum += 1;
			player1.Chop(Sides::Right);
			sdMgr.SoundPlay(SoundChoice::ChopSound);
			ShowLogEffect();

		}
		if (InputMgr::GetKeyUp(Keyboard::Left) || InputMgr::GetKeyUp(Keyboard::Right))
			player1.SetChop(false);
	}
<<<<<<< HEAD

	// ReStart / MainMenu choice
	if (!player1.GetAlive())
	{
		if (InputMgr::GetKeyDown(Keyboard::Left))
			choicePlay = 0;
		if (InputMgr::GetKeyDown(Keyboard::Right))
			choicePlay = 1;

		if (InputMgr::GetKeyDown(Keyboard::Return))
		{
			if (choicePlay == 0)
			{
				player1.Init();
				player1.SetAlive(true);
			}
			else if (choicePlay == 1)
			{
				SceneMgr::GetInstance()->SetScene(SceneSelect::MainMenu);
			}
		}
	}

	// 조건 : 피격시 or 타임아웃시 로 변경 / ReStart, MainMenu choice 버튼 옮기기
	if (timer < 0.f) 
	{
		if (!player1.GetAlive())
		{
			player1.Init();
			player1.SetAlive(true);
		}
		else
		{
			player1.Die();
			scoreResultNum = scoreNum;
			scoreNum = 0;
			sdMgr.SoundPlay(SoundChoice::DeathSound);
			dt = 0;
		}
	}
	float normTime = timer / duration; // 정규화
	float timerSizeX = timerBarSize.x * normTime;
	timerBar.setSize({ timerSizeX, timerBarSize.y });
	timerBar.setPosition
	(1920 * 0.5f - timerSizeX * 0.5f, 1080 - 100);

}

void Solo::ShowLogEffect() {
	if (unuseLogs.empty())
		return;
	auto log = unuseLogs.front();
	unuseLogs.pop_front();
	useLogs.push_back(log);

	Vector2f force;
	force.x = player1.GetSide() == Sides::Left ? 1500 : -1500;
	force.y = -1500;
	float aForce = player1.GetSide() == Sides::Left ? 360 * 5 : -360 * 5;

	Vector2f pos = player1.GetPos();
	if (player1.GetSide() == Sides::Left) {
		pos.x = player1.GetPos().x + 200;
	}else
		pos.x = player1.GetPos().x - 200;

	pos.y = 800;

	log->SetPos(pos);
	log->Shot(force, aForce);
}

void Solo::Init()
{
	GetPlayer1()->SetOriginalPos({ 1920 / 2 - 250,900 }, { 1920 / 2 + 250,900 });

}
