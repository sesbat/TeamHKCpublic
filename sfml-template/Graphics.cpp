#include "Graphics.h"

Graphics::Graphics(string str)
{
    this->tex.loadFromFile(str);
    SetTex(str);
}

Graphics::Graphics(string str, Vector2f pos)
    :Graphics(str)
{
    this->pos = pos;
    sprite.setPosition(this->pos);
}

Graphics::~Graphics()
{
}

void Graphics::SetOrigin(Origins origin)
{
    Vector2f originPos;
    originPos.x = sprite.getLocalBounds().width * ((int)origin % 3) * 0.5f;
    originPos.y = sprite.getLocalBounds().height * ((int)origin / 3) * 0.5f;
    sprite.setOrigin(originPos);
}

void Graphics::SetOrigin(Sprite& obj, Origins origin)
{
    FloatRect rect = obj.getLocalBounds();
    Vector2f originPos;
    originPos.x = rect.width * ((int)origin % 3) * 0.5f;
    originPos.y = rect.height * ((int)origin / 3) * 0.5f;
    obj.setOrigin(originPos);
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

void Graphics::SetTex(string str)
{
    this->tex.loadFromFile(str);
    sprite.setTexture(tex);
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