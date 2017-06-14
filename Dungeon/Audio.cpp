#include "Audio.h"



Audio::Audio()
{
	sf::SoundBuffer tmp;
	tmp.loadFromFile("projectile1.flac");
	buffer.push_back(tmp);
	tmp.loadFromFile("projectile2.wav");
	buffer.push_back(tmp);
	tmp.loadFromFile("burp.wav");
	buffer.push_back(tmp);
	tmp.loadFromFile("pain.wav");
	buffer.push_back(tmp);
	tmp.loadFromFile("death.wav");
	buffer.push_back(tmp);
	
}


Audio::~Audio()
{
}
