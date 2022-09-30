#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include "Graphics.h"
#include "MovingObj.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "InputMgr.h"
#include <list>

using namespace sf;
using namespace std;
#define WIDTH 1920
#define HEIGHT 1080
int main()
{
    //파일 불러오기

    VideoMode vm(WIDTH, HEIGHT);

    RenderWindow window(vm, "Timber!!", Style::Default);

    Graphics tree("graphics/tree.png", { WIDTH / 2, 0});
    Graphics back("graphics/background.png");
    MovingObj bee("graphics/bee.png");
    list<Graphics> env;
    list<MovingObj> movingObj;
    env.push_back(back);
    Scene startMenu(env, movingObj, (int)SceneSelect::StartMenu);
    Scene SkinMenu(env, movingObj, (int)SceneSelect::SkinMenu);
    movingObj.clear();
    env.clear();
    env.push_back(back);

    tree.SetOrigin(Origins::TC);
    env.push_back(tree);

    Scene MainMeun(env, movingObj, (int)SceneSelect::MainMenu);
    SceneMgr::GetInstance()->AddScene(SceneSelect::StartMenu, &startMenu);
    SceneMgr::GetInstance()->AddScene(SceneSelect::MainMenu, &MainMeun);
    SceneMgr::GetInstance()->AddScene(SceneSelect::SkinMenu, &SkinMenu);


    Clock clock;
    while (window.isOpen()) 
    {
        Time dt = clock.restart();
        Event ev;

        while (window.pollEvent(ev))
        {
            InputMgr::UpdateInput(ev);
        }
        SceneMgr::GetInstance()->Draw(window);
        SceneMgr::GetInstance()->Update(dt.asSeconds());

       

        if (InputMgr::GetKeyDown(Keyboard::Key::Escape))
        {
            window.close();
        }

        window.display();
    }

    return 0;
}
