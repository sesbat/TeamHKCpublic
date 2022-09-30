#include <iostream>
#include "InputMgr.h"
#include <algorithm>

vector<bool> InputMgr::downList;
vector<bool> InputMgr::ingList;
vector<bool> InputMgr::upList;

void InputMgr::ClearInput()
{
	downList.clear();
	upList.clear();
	for (int i = 0; i < (int)Keyboard::Key::KeyCount; i++) {
		upList.push_back(false);
		downList.push_back(false);
	}
}

void InputMgr::UpdateInput(Event& ev)
{

	int pos = (int)ev.key.code;

	switch (ev.type)
	{

	case Event::EventType::KeyPressed:
		if (!GetKey(ev.key.code) && !GetKeyDown(ev.key.code)) {
			cout << ev.key.code << endl;
			downList[pos] = true;
			ingList[pos] = true;

		}
		break;
	case Event::EventType::KeyReleased:

		cout << "KeyReleased" << endl;

		ingList[pos] = false;
		upList[pos] = true;
		//		downList[pos] = false;
		break;
	}
}



void InputMgr::Set()
{
	int count = (int)Keyboard::Key::KeyCount;
	for (int i = 0; i < count; i++) {
		downList.push_back(false);
		ingList.push_back(false);
		upList.push_back(false);
	}

}

void InputMgr::againSet()
{
}

bool InputMgr::GetKeyDown(Keyboard::Key key)
{
	return downList[key];
}

bool InputMgr::GetKey(Keyboard::Key key)
{
	return ingList[key];
}

bool InputMgr::GetKeyUp(Keyboard::Key key)
{
	return upList[key];
}
