#include"Duo.h"

Duo::Duo()
{
	player.SetTex("graphics/player.png");
	player.SetOrigin(Origins::BC);
	tree.SetTex("graphics/tree.png");
	tree.SetOrigin(Origins::TC);
	tree.SetPos({ 1920 / 4,0 });
	tree2.SetTex("graphics/tree.png");
	tree2.SetOrigin(Origins::TC);
	tree2.SetPos({ 1920,0 });
	Init();
	Player2.SetTex("graphics/player.png");
	Player2.SetOrigin(Origins::BC);
}

Duo::~Duo()
{
}

void Duo::Init()
{
	player.SetOriginalPos({ 1920 / 2 - 250,900 }, { 1920 / 2 + 250,900 });

}

void Duo::Draw(RenderWindow& e)
{
}

void Duo::Update(float dt)
{
}
