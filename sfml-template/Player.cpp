#include "Player.h"
#include "Effect.h"
#include "Graphics.h"

Player::Player() {
	originalPos.clear();
	originalPos.push_back({ 1920 / 2 - 250,900 });

	originalPos.push_back({ 1920 / 2 + 250,900 });
	axeTex.loadFromFile("graphics/axe.png");
	axe.setTexture(axeTex);
	ripTex.loadFromFile("graphics/rip.png");

	axe.setOrigin(axe.getLocalBounds().width, axe.getLocalBounds().height);

	Init();
}

Player::Player(string str)
	:Graphics(str)
{
	originalPos.clear();
	originalPos.push_back({ 1920 / 2 - 250,900 });

	originalPos.push_back({ 1920 / 2 + 250,900 });
	axeTex.loadFromFile("graphics/axe.png");
	axe.setTexture(axeTex);
	ripTex.loadFromFile("graphics/rip.png");

	axe.setOrigin(axe.getLocalBounds().width, axe.getLocalBounds().height);

	for (int i = 0; i < 100; i++)
	{
		auto log = new Effect("graphics/log.png", 5.f);
		unuseLogs.push_back(log);
	}

	Init();
}

Player::~Player()
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

void Player::ShowLog()
{
	if (unuseLogs.empty())
		return;

	auto log = unuseLogs.front();
	unuseLogs.pop_front();
	useLogs.push_back(log);

	Vector2f force;
	force.x = pos == Sides::Left ? 1500 : -1500;
	force.y = -1500;
	float aForce = pos == Sides::Left ? 360 * 5 : -360 * 5;

	Vector2f pos = Center;
	pos.y = axe.getPosition().y;

	log->SetPos(pos);
	log->Shot(force, aForce);
}
Sides Player::GetSide()
{
	return pos;
}
void Player::SetOriginalPos(Vector2f Left, Vector2f Right)
{
	originalPos.clear();
	originalPos.push_back(Left);

	originalPos.push_back(Right);
}
void Player::Init()
{
	this->SetTex(skin);
	isAlive = true;
	sprite.setPosition(GetPos().x, 900.f);
	SetOrigin(Origins::BC);
	if (pos == Sides::Left)
		SetFlipX(true);

	Vector2f size = GetSize();

	originalPos.clear();
	originalPos.push_back({ 1920 / 2 - 250,900 });

	originalPos.push_back({ 1920 / 2 + 250,900 });

	sprite.setPosition(this->GetPos());
}

void Player::Release()
{
	for (auto log : unuseLogs)
	{
		delete log;
	}
	unuseLogs.clear(); //��ȸ�ϸ鼭 Ŭ����
	for (auto log : useLogs)
	{
		delete log;
	}
	useLogs.clear();
}

void Player::Update(float dt)
{
	Graphics::Update(dt);
	auto it = useLogs.begin();
	while (it != useLogs.end())
	{
		(*it)->Update(dt);
		if (!(*it)->GetActive())
		{
			unuseLogs.push_back(*it);
			it = useLogs.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void Player::Draw(RenderWindow& window)
{
	for (auto& log : useLogs)
	{
		log->Draw(window);
	}
	window.draw(sprite);
	if (isChopping)
	{
		window.draw(axe);
	}
}

void Player::SetPos(Vector2f pos)
{
	Graphics::SetPos(pos);

	Vector2f axePos2 = axePos;
	if (axe.getScale().x < 0)
	{
		axePos2.x *= -1;
	}
	axe.setPosition(pos + axePos2);
}

void Player::Die()
{
	isAlive = false;
	isChopping = false;

	sprite.setTexture(ripTex);
	if (sprite.getPosition().y >= 900.f)
		sprite.setPosition(GetPos().x, GetPos().y + 50.f);

	SetFlipX(false);
	SetOrigin(Origins::BC);
}

void Player::SetAlive(bool alive)
{
	isAlive = alive;
}

bool Player::GetAlive()
{
	return isAlive;
}

void Player::SetFlipX(bool flip)
{
	Graphics::SetFlipX(flip);
	Vector2f scale = axe.getScale();
	scale.x = flip ? -abs(scale.x) : abs(scale.x);
	axe.setScale(scale);
}

void Player::Chop(Sides side)
{
	isChopping = true;
	pos = side;
	sprite.setPosition(originalPos[(int)pos]);
	if (GetSide() == Sides::Left)
		axe.setPosition(sprite.getPosition().x + 50, sprite.getPosition().y - 50);
	else
		axe.setPosition(sprite.getPosition().x - 50 , sprite.getPosition().y - 50);

	SetFlipX(pos == Sides::Left);
}

void Player::SetChop(bool chop)
{
	isChopping = chop;
}

bool Player::GetChop()
{
	return isChopping;
}

void Player::SetSide(Sides pos)
{
	this->pos = pos;
	sprite.setPosition(originalPos[(int)pos]);
	SetFlipX(pos == Sides::Left);

}

int Player::GetChoice()
{
	return choice;
}

void Player::AddChoice()
{
	choice += 1;
}

void Player::SubChoice()
{
	choice -= 1;
}

void Player::SetPause()
{
	isPause = !isPause;
}

bool Player::GetPause()
{
	return isPause;
}
