#pragma once
#include "InputMgr.h"
#include <algorithm>
#include <iostream>

using namespace std;

vector<bool>InputMgr2::downList(Keyboard::Key::KeyCount);
vector<bool>InputMgr2::ingList(Keyboard::Key::KeyCount);
vector<bool>InputMgr2::upList(Keyboard::Key::KeyCount);

void InputMgr2::UpdateInput(Event& ev)
{
	switch (ev.type)
	{
	case Event::EventType::KeyPressed:
		std::cout << "Keypressed" << ev.key.code << std::endl;
		if (ev.key.code != Keyboard::Key::Unknown && !ingList[ev.key.code])
		{
			downList[ev.key.code] = true;
			ingList[ev.key.code] = true;
		}
		break;
	case Event::EventType::KeyReleased:
		std::cout << "Keyreleased" << ev.key.code << std::endl;
		if (ev.key.code != Keyboard::Key::Unknown) //unknown이 아닐때
		{
			ingList[ev.key.code] = false;
			upList[ev.key.code] = true;
		}
		break;
	}
}

void InputMgr2::ClearInput()
{
	fill(downList.begin(), downList.end(), false);
	fill(upList.begin(), downList.end(), false);
}

bool InputMgr2::GetKeyDown(Keyboard::Key key)
{
	return downList[(int)key];
}

bool InputMgr2::GetKey(Keyboard::Key key)
{
	return ingList[(int)key];
}

bool InputMgr2::GetKeyUp(Keyboard::Key key)
{
	return upList[(int)key];
}
