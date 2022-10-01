#include "Letter.h"

Letter::Letter()
{
}

Letter::~Letter()
{
}

void Letter::SetOrigin(Text& obj, Origins origin)
{
	FloatRect rect = obj.getLocalBounds();
	Vector2f originPos;
	originPos.x = rect.width * ((int)origin % 3) * 0.5f;
	originPos.y = rect.height * ((int)origin % 3) * 0.5f;
	obj.setOrigin(originPos);
}

void Letter::SetFont(string font)
{
	this->font.loadFromFile(font);
}

void Letter::SetString(string string)
{
	text.setString(string);
}

void Letter::SetFontSize(int size)
{
	text.setCharacterSize(size);
}

void Letter::SetFontColor(Color color)
{
	text.setFillColor(color);
}

void Letter::SetPosition(Vector2f pos)
{
	this->pos = pos;
}

void Letter::SetAll(string font, string string, int size, Color color, Vector2f pos)
{
	this->font.loadFromFile(font);
	SetString(string);
	SetFontSize(size);
	SetFontColor(color);
	SetPosition(pos);
}

void Letter::SetLetter(MessageChoice message)
{
	switch (message)
	{
	case MessageChoice::DeathText:
		SetAll(fontname, "YOU  DIE  !", 100, Color::Black, { ScreenSize.x * 0.5f, ScreenSize.y * 0.4f });
		SetOrigin(text, Origins::MC);
		break;

	case MessageChoice::RestartText:
		SetAll(fontname, "RE  START ?", 80, Color::Blue, { ScreenSize.x * 0.3f, ScreenSize.y * 0.55f });
		SetOrigin(text, Origins::MC);
		break;

	case MessageChoice::MenuText:
		SetAll(fontname, "MAIN  MENU", 80, Color::Blue, { ScreenSize.x * 0.7f, ScreenSize.y * 0.55f });
		SetOrigin(text, Origins::MC);
		break;

	case MessageChoice::PressToEnTer:
		SetAll(fontname, "(PRESS  TO  ENTER  KEY)", 45, Color::White, { ScreenSize.x * 0.3f, ScreenSize.y * 0.6f });
		SetOrigin(text, Origins::MC);
		break;

	case MessageChoice::PressToRShift:
		SetAll(fontname, "(PRESS  TO  RSHIFT  KEY)", 45, Color::White, { ScreenSize.x * 0.7f, ScreenSize.y * 0.6f });
		SetOrigin(text, Origins::MC);
		break;
	}
}

void Letter::Draw(RenderWindow& window)
{
	window.draw(text);
}

Text& Letter::GetText()
{
	return text;
}
