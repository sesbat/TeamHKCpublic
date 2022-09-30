#pragma once

#include<SFML/Graphics.hpp>
#include<string>

using namespace sf;
using namespace std;

class Graphics
{
protected:
<<<<<<< HEAD
    Sprite sprite;
    Texture tex;
    Vector2f pos;
=======
	Sprite sprite;
	Texture tex;
	Vector2f pos;
>>>>>>> 27785db9f4d79b68cc756e9b5b639cf7f915c25b
public:

    Graphics(string str);
    Graphics(string str, Vector2f pos);
    virtual ~Graphics();

    void SetOrigin();
    Vector2f GetPos();
    void Translate(Vector2f delta);

<<<<<<< HEAD
    virtual void Init();
    virtual void Release();
    virtual void Update(float dt);
    virtual void Draw(RenderWindow& window);
    virtual void SetPos(Vector2f pos);
    virtual void SetFlipX(bool flip);
=======
	virtual void Init();
	virtual void Release();
	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);
	virtual void SetPos(Vector2f pos);
	void Translate(Vector2f delta);
>>>>>>> 27785db9f4d79b68cc756e9b5b639cf7f915c25b
};
