#pragma once

#include<SFML/Graphics.hpp>
#include<string>

using namespace sf;
using namespace std;

class Graphics
{
private:
	Sprite sprite;
	Texture tex;
	Vector2f pos;
public:

	Graphics(string str);
	Graphics(string str,Vector2f pos);
	virtual ~Graphics();

	void SetOrigin();
	Vector2f GetPos();

	virtual void Draw(RenderWindow& window);
	virtual void Init();
	virtual void Update(float dt);
	virtual void Release();
};

