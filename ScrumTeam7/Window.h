#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#define Window GameWindow::getWindow()
#define GameEvent GameWindow::getEvent()
#define dt GameWindow::getDeltaTime()

// "Container-Klasse" mit Constructers
struct Settings {

	sf::Vector2u WindowSize;
	bool Fullscreen;

	unsigned int FrameRateLimit;

	unsigned int MasterVolume;
	unsigned int SoundVolume;
	unsigned int MusicVolume;

	Settings()
		: WindowSize({1600u, 900u}), Fullscreen(false), FrameRateLimit(30u),
		MasterVolume(100u), SoundVolume(100u), MusicVolume(100u) {}

	Settings(const sf::Vector2u& WindowSize, const bool& Fullscreen, const unsigned int& FrameRateLimit,
		const unsigned int& MasterVolume, const unsigned int& SoundVolume, const unsigned int& MusicVolume)
		: WindowSize(WindowSize), Fullscreen(Fullscreen), FrameRateLimit(FrameRateLimit),
		MasterVolume(MasterVolume), SoundVolume(SoundVolume), MusicVolume(MusicVolume) {}

	Settings(const Settings& other) 
		: WindowSize(other.WindowSize), Fullscreen(other.Fullscreen), FrameRateLimit(other.FrameRateLimit),
		MasterVolume(other.MasterVolume), SoundVolume(other.SoundVolume), MusicVolume(other.MusicVolume) {}

};

class GameWindow
{
private:
	// Window relevant
	static Settings settings;
	static sf::RenderWindow* window;
	static sf::Event ev;
	static sf::View mainView; 

	//	!Wichtig! Erkl�rung f�r sf::RenderWindow und sf::View. Gro�e Hilfe
	//	https://github.com/SFML/SFML/wiki/Tutorial:-Using-View

	// DeltaTime
	// DeltaTime ist die Zeit, welche das Programm pro Frame an Abreitszeit ben�tigt.
	// Diese wird jeden Frame neu berechnet
	static sf::Clock deltaTimer;
	static float deltaTime;

public:
	// Erstellt ein Fenster mit den Aktuellen settings
	static void openWindow();

	// L�scht das Fenster falls eins Existiert
	static void closeWindow();

	// Gibt eine Reverens auf das Fenster zur�ck
	// Diese wird so oft verwendet und ist so n�tztlich das es einen #define bekommt f�r Leserlichen Code
	static sf::RenderWindow& getWindow();

	static const Settings* getSettings();
	static void setSettings(const Settings& newSettings);

	// Gibt eine Reverens auf die Event-Klasse zur�ck
	static sf::Event& getEvent();
	// Gibt eine Reverens auf die View-Klasse zur�ck
	// f�r mehr Detais siehe oben der Link unter den Attributen
	static sf::View& getMainView();


	// Berechnung der DeltaTime
	static void updateDeltaTime();

	// Gibt eine Reverens auf die DeltaTime zur�ck
	// Diese wird so oft verwendet und ist so n�tztlich das es einen #define bekommt f�r Leserlichen Code
	static const float& getDeltaTime();
};
