#pragma once

#include "SFML/Audio.hpp"

class Music
{
private:
	static bool activ;
	static int currend;
	static sf::Music* music;

public:
	static void startMusic();
	static void stopMusic();

	static void unloadMusic();

	static void setVolume();
};

