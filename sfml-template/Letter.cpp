#include "Letter.h"

void Letter::SetOrigin(Text& text, Origins origin)
{
	FloatRect rect = text.getLocalBounds();
	Vector2f originPos;
	originPos.x = rect.width * ((int)origin % 3) * 0.5f;
	originPos.y = rect.height * ((int)origin / 3) * 0.5f;
	text.setOrigin(originPos);
}

void Letter::SetOrigin(Origins origin)
{
	FloatRect rect = text.getLocalBounds();
	Vector2f originPos;
	originPos.x = rect.width * ((int)origin % 3) * 0.5f;
	originPos.y = rect.height * ((int)origin / 3) * 0.5f;
	text.setOrigin(originPos);
}

void Letter::SetFont(Font& font)
{
	text.setFont(font);
}

void Letter::SetSize(int size)
{
	text.setCharacterSize(size);
}

void Letter::SetColor(Color color)
{
	text.setFillColor(color);
}

void Letter::SetString(string string)
{
	text.setString(string);
}

void Letter::SetPos(Vector2f pos)
{
	text.setPosition(pos);
}

void Letter::SetAll(Font& font, int size, Color color, string string, Vector2f pos)
{
	text.setFont(font);
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setString(string);
	text.setPosition(pos);
	SetOrigin(text, Origins::MC);
}

void Letter::Draw(RenderWindow& window)
{
	window.draw(text);
}
