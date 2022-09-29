#pragma once
#include "Graphics.h"
class MovingObj : public Graphics
{
private:

public:
	MovingObj(string str);
	virtual ~MovingObj();

	virtual void Draw(RenderWindow& window)override;
	virtual void Init()override;
	virtual void Update(float dt)override;
	virtual void Release()override;
};

