#pragma once

#include<SFML/Graphics.hpp>
#include<string>

using namespace sf;
using namespace std;

enum class Origins
{
    TL,
    TC,
    TR,

    ML,
    MC,
    MR,

    BL,
    BC,
    BR
};

class Graphics
{
protected:
	Sprite sprite;
	Texture tex;
	Vector2f pos;

public:
    Graphics() {};
    Graphics(string str);
    Graphics(string str, Vector2f pos);
    virtual ~Graphics();

    void SetOrigin(Origins origin);
    void SetOrigin(Sprite& obj, Origins origin);

    Vector2f GetPos();

    virtual void Init();
    virtual void Release();
    virtual void Update(float dt);
    virtual void Draw(RenderWindow& window);
    virtual void SetPos(Vector2f pos);
    virtual void SetFlipX(bool flip);
    void Translate(Vector2f delta);
    void SetTex(string str);
    Texture GetTex() { return tex; }
    Vector2f GetScale() { return sprite.getScale(); };
    Sprite GetSprite() { return sprite; }
    Vector2f GetSize() const;
};
