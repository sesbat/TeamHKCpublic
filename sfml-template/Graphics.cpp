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
<<<<<<< HEAD
    return sprite.getPosition();
=======
	return sprite.getPosition();
>>>>>>> 27785db9f4d79b68cc756e9b5b639cf7f915c25b
}

void Graphics::SetPos(Vector2f pos)
{
<<<<<<< HEAD
    sprite.setPosition(pos);
}

void Graphics::SetFlipX(bool flip)
{
    Vector2f scale = sprite.getScale();
    scale.x = flip ? -abs(scale.x) : abs(scale.x);
    sprite.setScale(scale);
=======
	sprite.setPosition(pos);
>>>>>>> 27785db9f4d79b68cc756e9b5b639cf7f915c25b
}

void Graphics::Translate(Vector2f delta)
{
<<<<<<< HEAD
    Vector2f pos = sprite.getPosition() + delta;
    sprite.setPosition(pos);
=======
	Vector2f pos = sprite.getPosition() + delta;
	sprite.setPosition(pos);
>>>>>>> 27785db9f4d79b68cc756e9b5b639cf7f915c25b
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