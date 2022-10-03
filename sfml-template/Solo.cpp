#include "Solo.h"
#include "sceneMgr.h"
#include <iostream>

std::random_device Solo::rd;
std::mt19937 Solo::gen(Solo::rd());

Solo::Solo()
{
	bee.SetTex("graphics/bee.png");

	for (int i = 0; i < 3; i++)
		cloud.push_back(new MovingObj("graphics/cloud.png"));




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

	Pause.SetTex("graphics/Pause.png");
	Pause.SetOrigin(Origins::MC);
	Pause.SetPos({1920 * 0.5f, 1080 * 0.5f});

	Init();
	timerBarSize.x = 400;
	timerBarSize.y = 80;
	timerBar.setSize(timerBarSize);
	timerBar.setFillColor(Color::Red);
	timerBar.setPosition(
		1920 * 0.5f - timerBarSize.x * 0.5f,
		1080 - 100);

	for (int i =0; i < 6; ++i)
	{
		branches.push_back(new Branche("graphics/branch.png",&tree));
		int temp = 0;
		branches[i]->SetSide((Sides)temp);
	}

	float x = branches[0]->GetPos().x;
	float y = 800;
	float offset = branches[0]->GetSize().y;
	offset += 100;
	for (int i = 0; i < branches.size(); ++i)
	{
		branchPosArr.push_back( Vector2f(x, y));
		y -= offset;
	}
	UpdateBranches(branches, currentBranch, branchPosArr);

}

void Solo::UpdateBranches(vector<Branche*>& branches, int& current, vector<Vector2f>& posArr)
{
	current = (current + 1) % branches.size();

	for (int i = 0; i < branches.size(); ++i)
	{
		int index = (current + i) % branches.size();
		branches[index]->SetPos(posArr[i]);
		if (i == branches.size() - 1)
		{
			branches[index]->SetSide((Sides)RandomRange(0,2));
		}
	}

}

int Solo::RandomRange(int min, int maxExclude)
{
	return (gen() % (maxExclude - min)) + min;
}


Solo::~Solo()
{
	for (auto &v : unuseLogs) {
		delete v;
	}
	unuseLogs.clear();
	for (auto &v : useLogs) {
		delete v;
	}
	useLogs.clear();

	for (auto &v : branches) {
		delete v;
	}
	branches.clear();

}

void Solo::Draw(RenderWindow& e)
{
	bee.Draw(e);
	for (auto& v : cloud) {
		v->Draw(e);

	}

	Scene::Draw(e);
	for (auto& v : branches) {
		v->Draw(e);

	}
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

	if (isPause)
		Pause.Draw(e);
}

void Solo::Update(float dt)
{	
	if (setBGM)
	{
		sdMgr.SoundPlay(SoundChoice::PlaySound);
		setBGM = false;
	}


	if(updateInit==false){
		player1.SetOriginalPos({ 1920 / 2 - 250,900 }, { 1920 / 2 + 250,900 });
		updateInit = true;
	}

	if (InputMgr::GetKeyDown(Keyboard::Escape)) {
		setBGM = true;
		sdMgr.StopPlay();
		scoreResult.SetString("SCORE = " + to_string(scoreResultNum));
		scoreNum = 0;
		timer = duration;
		player1.Init();
		SceneMgr::GetInstance()->SetScene(SceneSelect::MainMenu);
		updateInit = false;
	}
	//여기에 실제게임플레이 입력,정보 브렌치 업데이트
	
	if (player1.GetAlive())
	{
		if (InputMgr::GetKeyDown(Keyboard::P))
		{
			if (!isPause)
			{
				isPause = true;
				// 시간 멈춤
			}
			else if (isPause)
			{
				isPause = false;
				// 시간 다시
			}
		}
	}

	if (isPause == false)
	{
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

		Scene::Update(dt);
		timer -= dt;

		if (player1.GetAlive()) {
			if (InputMgr::GetKeyDown(Keyboard::Left))
			{
				scoreNum += 1;
				player1.SetAxePos(40, 40);
				player1.Chop(Sides::Left);
				sdMgr.SoundPlay(SoundChoice::ChopSound);
				ShowLogEffect();
				UpdateBranches(branches, currentBranch, branchPosArr);
			}
			if (InputMgr::GetKeyDown(Keyboard::Right))
			{
				scoreNum += 1;
				player1.SetAxePos(40, 40);
				player1.Chop(Sides::Right);
				sdMgr.SoundPlay(SoundChoice::ChopSound);
				ShowLogEffect();
				UpdateBranches(branches, currentBranch, branchPosArr);
			}
			if (InputMgr::GetKeyUp(Keyboard::Left) || InputMgr::GetKeyUp(Keyboard::Right))
				player1.SetChop(false);
			if (InputMgr::GetKey(Keyboard::Left) || InputMgr::GetKey(Keyboard::Right))
				player1.SetAxePos(40, 40);
		}

		/********************************** 임시로 해둔거 *********************************/
		if (InputMgr::GetKeyDown(Keyboard::Space) && player1.GetAlive())
		{
			if (player1.GetAlive())
			{
				player1.SetAlive(false);
				player1.Die();
				sdMgr.SoundPlay(SoundChoice::DeathSound);
				scoreResultNum = scoreNum;
				scoreResult.SetString("SCORE = " + to_string(scoreResultNum));
				scoreNum = 0;
			}
			else if (!player1.GetAlive())
				player1.SetAlive(true);
		}
		if (timer < 0.f)
		{
			timer = 0.f;
			dt = 0.f;
			if (player1.GetAlive())
			{
				sdMgr.StopPlay();
				player1.SetAlive(false);
				player1.Die();
				scoreResultNum = scoreNum;
				scoreResult.SetString("SCORE = " + to_string(scoreResultNum));
				scoreNum = 0;
				sdMgr.SoundPlay(SoundChoice::TimeOutSound);
			}
			
		}


		timer -= dt;
		float normTime = timer / duration; // 정규화
		float timerSizeX = timerBarSize.x * normTime;
		timerBar.setSize({ timerSizeX, timerBarSize.y });
		timerBar.setPosition
		(1920 * 0.5f - timerSizeX * 0.5f, 1080 - 100);
	}

	if (!player1.GetAlive())
	{
		// ReStart / MainMenu choice
		if (InputMgr::GetKeyDown(Keyboard::Left))
			choicePlay = 0;
		if (InputMgr::GetKeyDown(Keyboard::Right))
			choicePlay = 1;

		if (InputMgr::GetKeyDown(Keyboard::Return))
		{
			setBGM = true;
			sdMgr.StopPlay();
			player1.SetAlive(true);
			if (choicePlay == 0)
			{
				SceneMgr::GetInstance()->SetScene(SceneSelect::Solo);
				timer = duration;
				player1.Init();
				// 다시시작
			}
			else
				SceneMgr::GetInstance()->SetScene(SceneSelect::MainMenu);
		}
	}
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
