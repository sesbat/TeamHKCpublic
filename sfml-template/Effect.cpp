#include "Effect.h"

const Vector2f Effect::Gravity = Vector2f(0.f, 8000.f);

Effect::Effect(string tex, float dur)
	: Graphics(tex), dur(dur)
{
	SetOrigin(Origins::MC);
}

Effect::~Effect()
{
}

void Effect::Shot(const Vector2f v, float av)
{
	active = true;
	timer = 0.f;
	velocity = v;
	angluarVelocity = av;
}

bool Effect::GetActive() const
{
	return active;
}

void Effect::Init()
{
	Graphics::Init();
	SetOrigin(Origins::MC);
}

void Effect::Release()
{
	Graphics::Release();
}

void Effect::Update(float dt)
{
	Graphics::Update(dt);

	timer += dt;
	if (timer > dur)
	{
		active = false;
	}

	float angle = sprite.getRotation();
	angle += angluarVelocity * dt;
	sprite.setRotation(angle);

	velocity += Gravity * dt;
	Vector2f delta = velocity * dt;
	Translate(delta);
}

void Effect::Draw(RenderWindow& window)
{
	Graphics::Draw(window);

}
