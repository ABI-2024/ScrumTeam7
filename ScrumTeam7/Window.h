#pragma once

#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"

#define Window GameWindow::getWindow()
#define GameEvent GameWindow::getEvent()

class GameWindow
{
private:

	static sf::ContextSettings settings;

	static sf::RenderWindow* window;
	static unsigned int framerateLimit;

	static sf::Event ev;
	static sf::View mainView;
public:

	static void openWindow();
	static void openWindow(const sf::Vector2u& WindowSize);
	static void openFullscreen();
	static void closeWindow();

	static sf::RenderWindow& getWindow();

	static unsigned int getFramerateLimit();
	static void setFramerateLimit(const unsigned int& FramerateLimit);

	static sf::ContextSettings getWindowSettings();
	static void setWindowSettings(const sf::ContextSettings& Settings);

	static sf::Event& getEvent();
	static sf::View& getMainView();
};
