#include "Player.h"
#include "Effect.h"
Player::Player(string str)
	:Graphics(str)
{
	axe.SetTex("graphics/axe.png");
	rip.SetTex("graphics/rip.png");
	for (int i = 0; i < 100; i++)
	{
		auto log = new Effect(texLog, 5.f);
		unuseLogs.push_back(log);
	}

	Init();
}

void Player::SetFlipX(bool flip)
{
	Graphics::SetFlipX(flip);
	Vector2f scale = axe.GetScale();
	scale.x = flip ? -abs(scale.x) : abs(scale.x);
	axe.GetSprite().setScale(scale);
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
	pos.y = axe.GetPos().y;

	log->SetPos(pos);
	log->Shot(force, aForce);
}
Sides Player::GetSide()
{
	return pos;
}

void Player::Init()
{
	isAlive = true;
	SetOrigin(Origins::BC);
	if (pos == Sides::Left)
		SetFlipX(true);

	Vector2f size = GetSize();

	originalPos.clear();
	originalPos.push_back({ 800,900 });

	originalPos.push_back({ 1200,900 });

	sprite.setPosition(originalPos[0]);
}

void Player::Release()
{
	for (auto log : unuseLogs)
	{
		delete log;
	}
	unuseLogs.clear(); //순회하면서 클리어
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
	if (isChopping)
	{

		window.draw(axe.GetSprite());
	}
	for (auto& log : useLogs)
	{
		log->Draw(window);
	}
	window.draw(sprite);
}

void Player::SetPos(Vector2f pos)
{
	Graphics::SetPos(pos);

	Vector2f axePos2 = axePos;
	if (axe.GetSprite().getScale().x < 0)
	{
		axePos2.x *= -1;
	}
	axe.GetSprite().setPosition(pos + axePos2);
}

void Player::Die()
{
	isAlive = false;
	isChopping = false;

	sprite.setTexture(rip.GetTex());
	SetFlipX(false);
	SetOrigin(Origins::BC);
}

void Player::SetAlive(bool alive)
{
}
bool Player::GetAlive()
{
	return isAlive;
}

void Player::Chop(Sides side)
{
	isChopping = false;
	pos = side;
	SetFlipX(pos == Sides::Left);
	sprite.setPosition(originalPos[(int)pos]);
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
}
