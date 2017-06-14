#pragma once

#include <vector>
#include <SFML/Audio.hpp>

using namespace std;
class Audio
{
public:
	vector<sf::SoundBuffer> buffer;
	Audio();
	~Audio();
};

