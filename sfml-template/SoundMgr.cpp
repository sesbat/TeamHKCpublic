#include "SoundMgr.h"

SoundMgr::SoundMgr()
{
	soundName.push_back("sound/titleSound.wav"); // titleSound
	soundName.push_back("sound/playSound.wav"); // playSound
	soundName.push_back("sound/chop.wav");
	soundName.push_back("sound/death.wav");
	soundName.push_back("sound/out_of_time.wav");

	SoundBuffer soundBuffer;
	Sound sound;
	for (int i = 0; i < soundName.size(); i++)
	{
		soundBuffer.loadFromFile(soundName[i]);
		soundBuffers.push_back(soundBuffer);
	}

	for (int i = 0; i < soundBuffers.size(); i++)
	{
		sound.setBuffer(soundBuffers[i]);
		sounds.push_back(sound);
	}
}

SoundMgr::~SoundMgr()
{
	
}

void SoundMgr::SoundPlay(SoundChoice soundchoice)
{
	switch (soundchoice)
	{
	case SoundChoice::TitleSound:

		if (played)
			sounds[0].play();
		if (!played)
			sounds[0].stop();
		break;

	case SoundChoice::PlaySound:
		if (played)
			sounds[1].play();
		if (!played)
			sounds[1].stop();
		break;

	case SoundChoice::ChopSound:
		if (played)
			sounds[2].play();
		if (!played)
			sounds[2].stop();
		break;

	case SoundChoice::DeathSound:
		if (played)
			sounds[3].play();
		if (!played)
			sounds[3].stop();
		break;

	case SoundChoice::TimeOutSound:
		if (played)
			sounds[4].play();
		if (!played)
			sounds[4].stop();
		break;
	}
	this->soundChoice = soundchoice;
}

SoundChoice SoundMgr::GetSoundChoice()
{
	return soundChoice;
}

void SoundMgr::SetPlay(bool tof)
{
	played = tof;
}
