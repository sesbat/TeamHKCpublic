#pragma once
#include "Graphics.h"
class MovingObj : public Graphics
{
private:

	float speed;
	Vector2f direction;

	Vector2i yrange;
	Vector2i speedRange;
	Vector2f startPos;
	Vector2f endPos;
public:
	MovingObj(string str);
	MovingObj(string str, Vector2f pos = Vector2f());
	virtual ~MovingObj();

	void Set(Vector2i srange, Vector2i yrange, Vector2f start, Vector2f end);

	virtual void Draw(RenderWindow& window)override;
	virtual void Init()override;
	virtual void Update(float dt)override;

};

