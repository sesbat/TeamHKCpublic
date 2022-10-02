#pragma once
#include <SFML/Graphics.hpp>
#include "Graphics.h"

class Letter
{
private:
	Text text;

public:
	static void SetOrigin(Text& text, Origins origin);
	void SetOrigin(Origins origin);
	void SetFont(Font& font);
	void SetSize(int size);
	void SetColor(Color color);
	void SetString(string string);
	void SetPos(Vector2f pos);
	void SetAll(Font& font, int size, Color color, string string, Vector2f pos);
	void Draw(RenderWindow& window);
};

