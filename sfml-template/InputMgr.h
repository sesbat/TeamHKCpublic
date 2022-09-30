#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include <iostream>

using namespace sf;
using namespace std;


class InputMgr
{
private:
	static vector<bool> downList;
	static vector<bool> ingList;
	static vector<bool> upList;
	
	
public:
	static void UpdateInput(Event& ev);
	static void ClearInput();

	static bool GetKeyDown(Keyboard::Key key);
	static bool GetKey(Keyboard::Key key);
	static bool GetKeyUp(Keyboard::Key key);
};
