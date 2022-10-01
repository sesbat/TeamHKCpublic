#pragma once
#include <SFML/Graphics.hpp>
#include "Graphics.h"

enum class MessageChoice
{
	DeathText, 
	RestartText, 
	MenuText, 
	PressToEnTer, 
	PressToRShift,
	Count,
};

class Letter
{
private:
	Font font;
	Text text;
	Vector2f pos;
	Vector2f ScreenSize = { 1920, 1080 };
	string fontname = "fonts/Mabinogi_Classic_TTF.ttf";

public:
	Letter();
	~Letter();
	static void SetOrigin(Text& obj, Origins origin);
	void SetFont(string font);
	void SetString(string string);
	void SetFontSize(int size);
	void SetFontColor(Color color);
	void SetPosition(Vector2f pos);
	void SetAll(string font, string string, int size, Color color, Vector2f pos);
	void SetLetter(MessageChoice message);
	void Draw(RenderWindow& window);
	Text& GetText();
};

