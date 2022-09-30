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
    return sprite.getPosition();
}

void Graphics::SetPos(Vector2f pos)
{
    sprite.setPosition(pos);
}

void Graphics::SetFlipX(bool flip)
{
    Vector2f scale = sprite.getScale();
    scale.x = flip ? -abs(scale.x) : abs(scale.x);
    sprite.setScale(scale);
}

void Graphics::Translate(Vector2f delta)
{
    Vector2f pos = sprite.getPosition() + delta;
    sprite.setPosition(pos);
}

Vector2f Graphics::GetSize() const
{
    FloatRect rect = sprite.getLocalBounds();
    return Vector2f(rect.width, rect.height);
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