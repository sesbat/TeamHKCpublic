#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include "Graphics.h"
#include "MovingObj.h"
#include "SceneMgr.h"

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

    Graphics tree("graphics/tree.png");
    Graphics back("graphics/background.png");

    list<Graphics> env;
    env.push_back(back);
    env.push_back(tree);
    SceneMgr::GetInstance()->SetSel(SceneSelect::Couple);

    //텍스쳐 로딩(클래스 필요)
    for (auto& v : env)
        SceneMgr::GetInstance()->SetGraphic(v);

    while (window.isOpen()) {
        Event ev;
        while (window.pollEvent(ev))
        {

        }
        SceneMgr::GetInstance()->Draw(window);

        /*switch (SceneMgr::GetInstance()->GetSel()) {
        case SceneSelect::Couple:

            break;
        }*/

            window.display();
    }

    return 0;
}