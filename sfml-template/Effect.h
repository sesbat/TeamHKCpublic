#pragma once
#include "Graphics.h"

class Effect : public Graphics
{
protected:
	Vector2f velocity;
	float angluarVelocity; // ȸ��
	float dur; // Ÿ�̸�
	float timer;

	bool active;

public:
	static const Vector2f Gravity;

	Effect(string& tex, float dur);
	virtual ~Effect();

	void Shot(const Vector2f v, float av);
	bool GetActive() const;

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;
};

