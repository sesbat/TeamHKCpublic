#include "Player.h"

Player::Player(string str)
	:Graphics(str)
{
}

void Player::SetFlipX(bool flip)
{
	Graphics::SetFlipX(flip);

	Vector2f scale; //겟 스케일
	scale.x = flip ? -abs(scale.x) : abs(scale.x);
	//셋 스케일
}

void Player::Init()
{
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
	//내용추가
}
