#include "Player.h"

Player::Player()
{
	axe.SetTex("graphics/axe.png");
	this->player.SetTex("graphics/player.pne");
	rip.SetTex("graphics/rip.png");
}

void Player::SetFlipX(bool flip)
{
	Graphics::SetFlipX(flip);
	Vector2f scale = axe.GetScale();
	scale.x = flip ? -abs(scale.x) : abs(scale.x);
	axe.GetSprite().setScale(scale);
}
Sides Player::GetSide()
{
	return pos;
}

void Player::Init()
{
	isAlive = true;
	SetOrigin(sprite, Origins::BC);
	if (pos == Sides::Left)
		SetFlipX(true);

	Vector2f size = GetSize();

	originalPos[(int)Sides::Left].x = Center.x - size.x * 2;
	originalPos[(int)Sides::Left].y = Center.y;

	originalPos[(int)Sides::Right].x = Center.x + size.x * 2;
	originalPos[(int)Sides::Right].y = Center.y;
	SetPos(originalPos[(int)pos]);
}

void Player::Release()
{

}

void Player::Update(float dt)
{
}

void Player::Draw(RenderWindow& window)
{
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
	SetOrigin(sprite, Origins::BC);
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
	pos = side;
	SetFlipX(pos == Sides::Left);
	SetPos(originalPos[(int)pos]);
}
