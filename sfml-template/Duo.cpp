#include"Duo.h"
#include "sceneMgr.h"

std::random_device Duo::rd;
std::mt19937 Duo::gen(Duo::rd());

Duo::Duo()
{
	for (int i = 0; i < 100; i++) {
		auto log = new Effect("graphics/log.png", 5);
		unuseLogs.push_back(log);
	}

	player1.SetOrigin(Origins::BC);
	tree.SetTex("graphics/tree.png");
	tree.SetOrigin(Origins::TC);
	tree.SetPos({ 400,0 });
	tree2.SetTex("graphics/tree.png");
	tree2.SetOrigin(Origins::TC);
	tree2.SetPos({ 1500 ,0 });
	tree.SetScale({ 0.65f, 1 });
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

	scoreResult_1P.SetAll(font, 120, Color::White, "SCORE : " + to_string(scoreResultNum_1P), { 1920 * 0.75f, 1080 * 0.2f });
	scoreResult_1P.SetOrigin(Origins::MC);
	scoreResult_2P.SetAll(font, 120, Color::White, "SCORE : " + to_string(scoreResultNum_1P), { 1920 * 0.25f, 1080 * 0.2f });
	scoreResult_2P.SetOrigin(Origins::MC);


	win.SetTex("graphics/Win.png");
	win.SetOrigin(Origins::TL);
	lose.SetTex("graphics/Lose.png");
	lose.SetOrigin(Origins::TL);
	middleLine.SetTex("graphics/MiddleLine.png");
	middleLine.SetOrigin(Origins::MC);
	middleLine.SetPos({ 1920 * 0.5f, 1080 * 0.5f });

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

	Pause.SetTex("graphics/Pause.png");
	Pause.SetOrigin(Origins::MC);
	Pause.SetPos({ 1920 * 0.5f, 1080 * 0.5f });

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

	for (int i = 0; i < 6; ++i)
	{
		branches1.push_back(new Branche("graphics/branch.png", &tree));
		int temp = RandomRange(0, 2);
		branches1[i]->SetSide((Sides)temp);
		branches1[i]->SetScale({ 0.8,1 });
	}
	for (int i = 0; i < 6; ++i)
	{
		branches2.push_back(new Branche("graphics/branch.png", &tree2));
		int temp = RandomRange(0, 2);
		branches2[i]->SetSide((Sides)temp);
		branches2[i]->SetScale({ 0.8,1 });

	}

	float x = branches1[0]->GetPos().x;
	float y = 800;
	float offset = branches1[0]->GetSize().y;
	offset += 100;

	for (int i = 0; i < branches1.size(); ++i)
	{
		branchPosArr1.push_back(Vector2f(x, y));
		y -= offset;
	}
	x = branches2[0]->GetPos().x;
	y = 800;
	offset = branches2[0]->GetSize().y;
	offset += 100;
	for (int i = 0; i < branches2.size(); ++i)
	{
		branchPosArr2.push_back(Vector2f(x, y));
		y -= offset;
	}

	UpdateBranches(branches1, currentBranch, branchPosArr1);
	UpdateBranches(branches2, currentBranch2, branchPosArr2);
	branches1[currentBranch]->SetSide(Sides::None);
	branches2[currentBranch2]->SetSide(Sides::None);
}

void Duo::UpdateBranches(vector<Branche*>& branches, int& current, vector<Vector2f>& posArr)
{
	current = (current + 1) % branches.size();

	for (int i = 0; i < branches.size(); ++i)
	{
		int index = (current + i) % branches.size();
		branches[index]->SetPos(posArr[i]);
		if (i == branches.size() - 1)
		{
			branches[index]->SetSide((Sides)RandomRange(0, 2));
		}
	}

}

int Duo::RandomRange(int min, int maxExclude)
{
	return (gen() % (maxExclude - min)) + min;
}

Duo::~Duo()
{
	for (auto& v : unuseLogs) {
		delete v;
	}
	unuseLogs.clear();
	for (auto& v : useLogs) {
		delete v;
	}
	useLogs.clear();

	for (auto& v : branches1) {
		delete v;
	}
	branches1.clear();
	for (auto& v : branches2) {
		delete v;
	}
	branches2.clear();
}

void Duo::Init()
{
	player1.SetOriginalPos({ 1300 ,900 }, { 1700 ,900 });
	player1.SetScale({ 0.8f, 0.8f });

	player2.SetOriginalPos({ 200,900 }, { 600,900 });
	player2.SetScale({ 0.8f, 0.8f });
}

void Duo::Draw(RenderWindow& e)
{
	Scene::Draw(e);
	for (auto& v : branches1) {
		v->Draw(e);
	}
	for (auto& v : branches2) {
		v->Draw(e);
	}
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
		scoreResult_1P.SetString("SCORE : " + to_string(scoreResultNum_1P));
		scoreResult_2P.SetString("SCORE : " + to_string(scoreResultNum_2P));

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

		scoreResult_1P.Draw(e);
		scoreResult_2P.Draw(e);
	}

	if (resultScreen)
	{
		reStart.Draw(e);
		mainMenu.Draw(e);

		if (choicePlay == 0)
			choice.SetPos({ (1920 * 0.5f) + 5, (1080 * 0.4f) + 15 });
		else
			choice.SetPos({ (1920 * 0.5f) + 5, (1080 * 0.6f) + 15 });

		choice.Draw(e);
	}
	else
	{
		middleLine.Draw(e);
		if (isPause)
			Pause.Draw(e);
	}

	for (auto v : useLogs)
	{
		v->Draw(e);
	}

}

void Duo::Update(float dt)
{
	if (set == false) {

		for (int i = 0; i < 5; i++) {
			UpdateBranches(branches1, currentBranch, branchPosArr1);
			UpdateBranches(branches2, currentBranch2, branchPosArr2);
		}
		set = true;
		branches1[currentBranch]->SetSide(Sides::None);
		branches2[currentBranch2]->SetSide(Sides::None);
	}
	if (setBGM)
	{
		sdMgr.SoundPlay(SoundChoice::PlaySound);
		setBGM = false;
	}

	if (updateInit == false) {
		Init();
		updateInit = true;
	}

	if (!(!player1.GetAlive() && !player2.GetAlive()))
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

	if (InputMgr::GetKeyDown(Keyboard::Escape)) {
		setBGM = true;
		sdMgr.StopPlay();
		scoreNum_1P = 0;
		scoreNum_2P = 0;
		score_1P.SetString("SCORE = " + to_string(scoreNum_1P));
		score_2P.SetString("SCORE = " + to_string(scoreNum_2P));
		player1.SetAlive(true);
		player2.SetAlive(true);
		resultScreen = false;
		player1.Init();
		player2.Init();
		timer1 = duration;
		timer2 = duration;

		SceneMgr::GetInstance()->SetScene(SceneSelect::MainMenu);
		updateInit = false;
	}
	//여기에 실제게임플레이 입력,정보 브렌치 업데이트
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

		timer1 -= dt;
		timer2 -= dt;

		if (player1.GetAlive()) {
			if (InputMgr::GetKeyDown(Keyboard::Left)) {
				player1.SetAxePos(40, 40);
				player1.Chop(Sides::Left);
				sdMgr.SoundPlay(SoundChoice::ChopSound);
				scoreNum_1P += 1;
				score_1P.SetString("SCORE = " + to_string(scoreNum_1P));
				ShowLogEffect(0);
				UpdateBranches(branches2, currentBranch2, branchPosArr2);

			}
			if (InputMgr::GetKeyDown(Keyboard::Right))
			{
				player1.SetAxePos(40, 40);
				player1.Chop(Sides::Right);
				sdMgr.SoundPlay(SoundChoice::ChopSound);
				scoreNum_1P += 1;
				score_1P.SetString("SCORE = " + to_string(scoreNum_1P));
				ShowLogEffect(0);
				UpdateBranches(branches2, currentBranch2, branchPosArr2);
			}
			if (InputMgr::GetKeyUp(Keyboard::Left) || InputMgr::GetKeyUp(Keyboard::Right))
				player1.SetChop(false);
			if (InputMgr::GetKey(Keyboard::Left) || InputMgr::GetKey(Keyboard::Right))
				player1.SetAxePos(40, 40);
		}
		//if (InputMgr::GetKeyDown(Keyboard::Q)) {
		//	if (!player1.GetAlive())
		//	{
		//		player1.Init();
		//		player1.SetAlive(true);
		//	}
		//	else
		//	{
		//		scoreResultNum_1P = scoreNum_1P;
		//		player1.Die();
		//		sdMgr.SoundPlay(SoundChoice::DeathSound);
		//		dt = 0;
		//	}
		//}
		////////////////////////////////////////////////////////
		if (player2.GetAlive()) {
			if (InputMgr::GetKeyDown(Keyboard::A)) {
				player2.SetAxePos(40, 40);
				player2.Chop(Sides::Left);
				sdMgr.SoundPlay(SoundChoice::ChopSound);
				scoreNum_2P += 1;
				score_2P.SetString("SCORE = " + to_string(scoreNum_2P));
				ShowLogEffect(1);
				UpdateBranches(branches1, currentBranch, branchPosArr1);

			}
			if (InputMgr::GetKeyDown(Keyboard::D))
			{
				player2.SetAxePos(40, 40);
				player2.Chop(Sides::Right);
				sdMgr.SoundPlay(SoundChoice::ChopSound);
				scoreNum_2P += 1;
				score_2P.SetString("SCORE = " + to_string(scoreNum_2P));
				ShowLogEffect(1);
				UpdateBranches(branches1, currentBranch, branchPosArr1);

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


		//if (InputMgr::GetKeyDown(Keyboard::Space)) {
			//	if (!player2.GetAlive())
			//	{
			//		player2.Init();
			//		player2.SetAlive(true);
			//	}
			//	else
			//	{
			//		scoreResultNum_2P = scoreNum_2P;
			//		player2.Die();
			//		sdMgr.SoundPlay(SoundChoice::DeathSound);
			//		dt = 0;
			//	}
			//}
		if (branches2[currentBranch2]->GetSide() == player1.GetSide())
		{
			if (player1.GetAlive())
			{
				player1.SetAlive(false);
				scoreResultNum_1P = scoreNum_1P;
				scoreResult_1P.SetString("SCORE = " + to_string(scoreResultNum_1P));
				sdMgr.SoundPlay(SoundChoice::DeathSound);
				player1.Die();
			}
		}
		if (branches1[currentBranch]->GetSide() == player2.GetSide())
		{
			if (player2.GetAlive())
			{
				player2.SetAlive(false);
				scoreResultNum_2P = scoreNum_2P;
				scoreResult_2P.SetString("SCORE = " + to_string(scoreResultNum_2P));
				sdMgr.SoundPlay(SoundChoice::DeathSound);
				player2.Die();
			}
		}
		if (timer1 < 0.f && timer2 < 0.f)

		{
			timer1 = 0.f;
			timer2 = 0.f;
			dt = 0.f;

			if (player1.GetAlive())

			{
				player1.SetAlive(false);
				scoreResultNum_1P = scoreNum_1P;
				scoreResult_1P.SetString("SCORE = " + to_string(scoreResultNum_1P));
				sdMgr.SoundPlay(SoundChoice::TimeOutSound);
				player1.Die();
			}
			if (player2.GetAlive())
			{
				player2.SetAlive(false);
				scoreResultNum_2P = scoreNum_2P;
				scoreResult_2P.SetString("SCORE = " + to_string(scoreResultNum_2P));
				sdMgr.SoundPlay(SoundChoice::TimeOutSound);
				player2.Die();
			}
			sdMgr.Stop();
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

	if (!player1.GetAlive() && !player2.GetAlive())
	{
		if (InputMgr::GetKeyDown(Keyboard::Return) && resultScreen == false)
		{
			setBGM = true;
			scoreNum_1P = 0;
			scoreNum_2P = 0;
			score_1P.SetString("SCORE = " + to_string(scoreNum_1P));
			score_2P.SetString("SCORE = " + to_string(scoreNum_2P));
			resultScreen = true;
			branches1[currentBranch]->SetSide(Sides::None);
			branches2[currentBranch2]->SetSide(Sides::None);
		}

		else if (InputMgr::GetKeyDown(Keyboard::Return) && resultScreen == true)
		{
			setBGM = true;
			player1.SetAlive(true);
			player2.SetAlive(true);
			resultScreen = false;

			//player1.Init();
			//player2.Init();
			player1.SetTex(tempSkin);
			player2.SetTex(tempSkin2);
			timer1 = duration;
			timer2 = duration;
			branches1[currentBranch]->SetSide(Sides::None);
			branches2[currentBranch2]->SetSide(Sides::None);

			if (choicePlay == 0)
				SceneMgr::GetInstance()->SetScene(SceneSelect::Couple);
			else
				SceneMgr::GetInstance()->SetScene(SceneSelect::MainMenu);
		}


		if (InputMgr::GetKeyDown(Keyboard::Up))
			choicePlay = 0;
		if (InputMgr::GetKeyDown(Keyboard::Down))
			choicePlay = 1;
	}
}

void Duo::ShowLogEffect(bool who) {
	if (unuseLogs.empty())
		return;
	auto log = unuseLogs.front();
	unuseLogs.pop_front();
	useLogs.push_back(log);
	Vector2f pos;
	Vector2f force;
	float aForce;
	if (!who) {
		force.x = player1.GetSide() == Sides::Left ? 1500 : -1500;
		force.y = -1500;
		aForce = player1.GetSide() == Sides::Left ? 360 * 5 : -360 * 5;

		pos = player1.GetPos();
		if (player1.GetSide() == Sides::Left) {
			pos.x = player1.GetPos().x + 200;
		}
		else
			pos.x = player1.GetPos().x - 200;
	}
	else {
		force.x = player2.GetSide() == Sides::Left ? 1500 : -1500;
		force.y = -1500;
		aForce = player2.GetSide() == Sides::Left ? 360 * 5 : -360 * 5;

		pos = player2.GetPos();
		if (player2.GetSide() == Sides::Left) {
			pos.x = player2.GetPos().x + 200;
		}
		else
			pos.x = player2.GetPos().x - 200;
	}
	pos.y = 800;

	log->SetPos(pos);
	log->Shot(force, aForce);
}
