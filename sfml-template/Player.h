#pragma once
#include "Graphics.h"

enum class Sides
{
	Left,
	Right,
	None,
};

class Player :public Graphics
{
private:
	Sides pos;

public:
	Player(string str);

	virtual void Init()override;
	virtual void Release()override;
	virtual void Update(float dt)override;
	virtual void Draw(RenderWindow& window)override;
};