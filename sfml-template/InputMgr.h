#pragma once
#include <SFML/Graphics.hpp>
#include <list>

using namespace sf;
using namespace std;

//class about verifying keyboard and mouse input by function 

class InputMgr
{
private:

	static vector<bool> downList;
	static vector<bool> ingList;
	static vector<bool> upList;

public:
	static void ClearInput();
	static void UpdateInput(Event& ev);
	static void Set();
	static void againSet();
	static bool GetKeyDown(Keyboard::Key key);
	static bool GetKey(Keyboard::Key key);
	static bool GetKeyUp(Keyboard::Key key);

};

