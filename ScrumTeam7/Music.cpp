#include "Music.h"
#include "Randomizer.h"
#include "Window.h"
//sf::Music music;
//if (!music.openFromFile("music.ogg"))
//return -1; // error
//music.play();


#define trackCount 2

bool Music::activ = false;
int Music::currend = 0;
sf::Music* Music::music = nullptr;

void Music::startMusic()
{
	Music::stopMusic();
	currend = Randomizer::randomize(2);

	if (!activ) {
		music = new sf::Music[trackCount];

		music[0].openFromFile("resource/Sound/Music/Anode.wav");
		music[1].openFromFile("resource/Sound/Music/Quote.wav");

		activ = true;

		setVolume();
	}

	music[currend].play();
	music[currend].setLoop(true);
}

void Music::stopMusic()
{
	if(activ){
		music[currend].stop();
	}
}

void Music::unloadMusic()
{
	if (activ) {
		delete[] music;
	}
}

void Music::setVolume()
{
	if (activ) {

		music[0].setVolume(100*GameWindow::getSettings()->MasterVolume* GameWindow::getSettings()->MusicVolume / 10000);
		music[1].setVolume(100*GameWindow::getSettings()->MasterVolume* GameWindow::getSettings()->MusicVolume / 10000);
	}
}
