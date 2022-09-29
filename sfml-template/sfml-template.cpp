#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include "Graphics.h"
#include "MovingObj.h"

#include <list>

using namespace sf;

#define WIDTH 1920
#define HEIGHT 1080
int main()
{
	//파일 불러오기

	VideoMode vm(WIDTH, HEIGHT);

	RenderWindow window(vm, "Timber!!", Style::Default);

	list<Graphics*> objects;
	//텍스쳐 로딩(클래스 필요)

    objects.push_back(new Graphics("graphics/background.png"));
	objects.push_back(new MovingObj("graphics/cloud.png"));
	objects.push_back(new Graphics("graphics/tree.png", { 960.f, 10.f }));
	objects.push_back(new MovingObj("graphics/bee.png"));
	objects.push_back(new Graphics("graphics/player.png"));
	objects.push_back(new Graphics("graphics/axe.png"));
	objects.push_back(new Graphics("graphics/rip.png"));


	//SoundBuffer chopBuffer;
	//chopBuffer.loadFromFile("sound/chop.wav");
	//Sound chopSound;
	//chopSound.setBuffer(chopBuffer);

	//SoundBuffer deathBuffer;
	//deathBuffer.loadFromFile("sound/death.wav");
	//Sound deathSound;
	//deathSound.setBuffer(deathBuffer);

	//SoundBuffer timeOutBuffer;
	//timeOutBuffer.loadFromFile("sound/out_of_time.wav");
	//Sound timeOutSound;
	//timeOutSound.setBuffer(timeOutBuffer);



	//업데이트
	//드로우
	while (1) {
		for (auto& go : objects)
		{
			go->Draw(window);
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			break;
		window.display();

	}

	//출력

	//딜리트
	for (auto go : objects)
	{
		delete go;
	}
	objects.clear();
	return 0;
}