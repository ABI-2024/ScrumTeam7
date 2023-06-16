#pragma once

#include "SFML/Audio.hpp"


// Music != sf::Music

class Music abstract
{
private:

	static bool activ;		// wurden alle Music datein schon geladen
	static bool activend;
	static int currend;		// wellche music momentan ausgef�hrt wird
	static sf::Music* music;	// Music Anlagen
	static sf::Music* musicend;

public:
	// Start oder pausiert die Music
	static void startMusic();
	static void startENDMusic();
	static void stopMusic();
	static void stopENDMusic();

	// L�scht alle noch vorhandene Music aus dem Speicher
	static void unloadMusic();

	// setzt die Lautst�rke fest
	static void setVolume();
};

