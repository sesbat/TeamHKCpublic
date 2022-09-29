#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include <iostream>

using namespace sf;
using namespace std;

//전역적으로 스태틱 함수를 이용하여 키보드 및 마우스 입력을 검사할 수 있는 클래스

class InputMgr2
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
