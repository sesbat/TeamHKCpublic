#include "StartMenu.h"
#include <iostream>
#include "InputMgr.h"
#include "sceneMgr.h"

using namespace std; 
void StartMenu::Draw(RenderWindow& e)
{
	Scene::Draw(e);
	//여기다가 엔터투 스타트이미지 넣으면됨
	cout << "startmenu draw" << endl;
	

}

void StartMenu::Update(float dt)
{
	if (InputMgr::GetKeyDown(Keyboard::Return)) {
		SceneMgr::GetInstance()->SetScene(SceneSelect::MainMenu);
	}
	cout << "startmenu " << endl;

}
