#pragma once

#include<SFML/Graphics.hpp>
#include<string>

using namespace sf;
using namespace std;

class Graphics
{
protected:
	Sprite sprite;
	Texture tex;
	Vector2f pos;
public:

    Graphics(string str);
    Graphics(string str, Vector2f pos);
    virtual ~Graphics();

    void SetOrigin();
    Vector2f GetPos();
    void Translate(Vector2f delta);

    virtual void Init();
    virtual void Release();
    virtual void Update(float dt);
    virtual void Draw(RenderWindow& window);
    virtual void SetPos(Vector2f pos);
    virtual void SetFlipX(bool flip);
    void Translate(Vector2f delta);
};
