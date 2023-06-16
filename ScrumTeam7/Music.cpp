#include "Music.h"
#include "Randomizer.h"
#include "Window.h"

// Anzahl der Tracks
#define trackCount 2

// static Attribute
bool Music::activ = false;
bool Music::activend = false;
int Music::currend = 0;
sf::Music* Music::music = nullptr;
sf::Music* Music::musicend = nullptr;

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

void Music::startENDMusic()
{
	Music::stopMusic(); // Stoppt music fals welche schon gespielt wird

	if (!activend) {		// Wenn nicht geladen dann Music laden
		musicend = new sf::Music;

		musicend->openFromFile("resource/Sound/Music/Landing.wav");

		activend = true;

		setVolume();
	}

	// Start Music und spiele sie solange ab, bis sie gestoppt wird
	musicend->play();
}

void Music::stopMusic()
{
	if(activ){	// wenn music geladen, dann music stoppen
		music[currend].stop();
	}
}

void Music::stopENDMusic()
{
	if (activend) {	// wenn music geladen, dann music stoppen
		musicend->stop();
	}
}

void Music::unloadMusic()
{
	if (activ) {	// wenn music geladen, dann music löschen
		delete[] music;
		activ = false;
	}
	if (activend == true) {
		delete musicend;
		activend = false;
	}
}

void Music::setVolume()
{
	if (activend) {
		musicend->setVolume(100 * GameWindow::getSettings()->MasterVolume * GameWindow::getSettings()->MusicVolume / 10000);
	}
	if (activ) {

		music[0].setVolume(100*GameWindow::getSettings()->MasterVolume* GameWindow::getSettings()->MusicVolume / 10000);
		music[1].setVolume(100*GameWindow::getSettings()->MasterVolume* GameWindow::getSettings()->MusicVolume / 10000);
	}
}
