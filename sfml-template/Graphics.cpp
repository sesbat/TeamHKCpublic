#include "Graphics.h"

Graphics::Graphics(string str)
{
	this->tex.loadFromFile(str);
	sprite.setTexture(tex);
	
}

Graphics::Graphics(string str, Vector2f pos)
	:Graphics(str)
{
	this->pos = pos;
	sprite.setPosition(pos);
}

Graphics::~Graphics()
{
}

void Graphics::SetOrigin()
{
}

Vector2f Graphics::GetPos()
{
	return Vector2f();
}

void Graphics::Draw(RenderWindow& window)
{
	window.draw(sprite);
}

void Graphics::Init()
{
}

void Graphics::Update(float dt)
{
}

void Graphics::Release()
{
}
