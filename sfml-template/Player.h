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

	Graphics player;
	Graphics axe;
	Graphics rip;
	
	bool isAxe=false;
	bool isAlive=true;
	bool isChopping;
	
	vector<Vector2f> originalPos;
	Vector2f Center;
	Vector2f axePos;
public:
	Player();

	virtual void SetFlipX(bool flip)override;
	virtual void Init()override;
	virtual void Release()override;
	virtual void Update(float dt)override;
	virtual void Draw(RenderWindow& window)override;
	virtual void SetPos(Vector2f pos)override;

	Sides GetSide();
	void Die();
	void SetAlive(bool alive);
	void Chop(Sides side);
	bool GetAlive();
};