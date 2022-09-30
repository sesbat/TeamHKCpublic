#include "MovingObj.h"

MovingObj::MovingObj(string str)
	:Graphics(str)
{

}

MovingObj::MovingObj(string str, Vector2f pos)
	:Graphics(str,pos)
{
}

MovingObj::~MovingObj()
{
}

void MovingObj::Set(Vector2i srange, Vector2i yrange, Vector2f start, Vector2f end)
{
	speedRange = srange;
	this->yrange = yrange;
	startPos = start;
	endPos = end;
	direction = (endPos.x > startPos.x) ? Vector2f(1, 0) : Vector2f(-1, 0);
}

void MovingObj::Draw(RenderWindow& window)
{
	Graphics::Draw(window);
}

void MovingObj::Init()
{
	speed = (rand() % (speedRange.y - speedRange.x)) + speedRange.x;

	startPos.y = (rand() % (yrange.y - yrange.x)) + yrange.x;
	endPos.y = startPos.y;

	SetPos(startPos);
}

void MovingObj::Update(float dt)
{
	Vector2f pos = GetPos();

	float distanceX = endPos.x - pos.x;

	if (abs(distanceX) < 10)
	{
		Init();
	}
	Translate(direction * speed * dt);
}


