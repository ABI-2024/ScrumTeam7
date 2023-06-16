#include "Music.h"
#include "Randomizer.h"
#include "Window.h"

// Anzahl der Tracks
#define trackCount 2

// static Attribute
bool Music::activ = false;
int Music::currend = 0;
sf::Music* Music::music = nullptr;

// public-Methoden
void Music::startMusic()
{
	Music::stopMusic(); // Stoppt music fals welche schon gespielt wird
	currend = Randomizer::randomize(2);		// Zufalls zahl

	if (!activ) {		// Wenn nicht geladen dann Music laden
		music = new sf::Music[trackCount];

		music[0].openFromFile("resource/Sound/Music/Anode.wav");
		music[1].openFromFile("resource/Sound/Music/Quote.wav");

		activ = true;

		setVolume();
	}

	// Start Music und spiele sie solange ab, bis sie gestoppt wird
	music[currend].play();
	music[currend].setLoop(true);
}

void Music::stopMusic()
{
	if(activ){	// wenn music geladen, dann music stoppen
		music[currend].stop();
	}
}

void Music::unloadMusic()
{
	if (activ) {	// wenn music geladen, dann music löschen
		delete[] music;
		activ = false;
	}
}

void Music::setVolume()
{
	if (activ) {

		music[0].setVolume(100*GameWindow::getSettings()->MasterVolume* GameWindow::getSettings()->MusicVolume / 10000);
		music[1].setVolume(100*GameWindow::getSettings()->MasterVolume* GameWindow::getSettings()->MusicVolume / 10000);
	}
}
