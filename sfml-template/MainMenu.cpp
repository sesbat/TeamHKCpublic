#include "MainMenu.h"
#include <iostream>
#include"sceneMgr.h"

using namespace std;

void MainMenu::Draw(RenderWindow& e)
{
	Scene::Draw(e);
	tree.Draw(e);
	cout << "main draw" << endl;
	
}

void MainMenu::Update(float dt)
{
	//위에 draw함수에 화살표왼쪽=1p 오른쪽 =2p 텍스트 넣어줘
	if (InputMgr::GetKeyDown(Keyboard::Left)) {
		SceneMgr::GetInstance()->SetScene(SceneSelect::SkinMenu);
		mode = 0;
	}
	if (InputMgr::GetKeyDown(Keyboard::Right)) {
		SceneMgr::GetInstance()->SetScene(SceneSelect::SkinMenu);
		mode = 1;
	}
	cout << "main" << endl;
}
