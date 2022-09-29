#include "MovingObj.h"

MovingObj::MovingObj(string str)
	:Graphics(str)
{

}

MovingObj::~MovingObj()
{
}

void MovingObj::Draw(RenderWindow& window)
{
	Graphics::Draw(window);
}

void MovingObj::Init()
{
}

void MovingObj::Update(float dt)
{
}

void MovingObj::Release()
{
}
