#include "Solo.h"

Solo::Solo()
{
	player.SetTex("graphics/player.png");
	tree.SetTex("graphics/tree.png");
	tree.SetOrigin(Origins::TC);
	tree.SetPos({ 1920 / 2,0 });
	Init();
}

Solo::~Solo()
{
}

void Solo::Draw(RenderWindow& e)
{
	Scene::Draw(e);
	player.Draw(e);
	tree.Draw(e);
}

void Solo::Update(float dt)
{
	//여기에 실제게임플레이 입력,정보 브렌치 업데이트
}

void Solo::Init()
{
	player.SetOriginalPos({ 1920 / 2 - 250,900 }, { 1920 / 2 + 250,900 });
	
}
