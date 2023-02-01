#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#define Window GameWindow::getWindow()
#define GameEvent GameWindow::getEvent()
#define dt GameWindow::getDeltaTime()


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
	// Window
	static Settings settings;
	static sf::RenderWindow* window;
	static sf::Event ev;
	static sf::View mainView;

	// DeltaTime
	static sf::Clock deltaTimer;
	static float deltaTime;

public:

	static void openWindow();
	static void closeWindow();
	static sf::RenderWindow& getWindow();

	static Settings getSettings();
	static void setSettings(const Settings& newSettings);

	static sf::Event& getEvent();
	static sf::View& getMainView();

	static void updateDeltaTime();
	static const float& getDeltaTime();
};
