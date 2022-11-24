#pragma once

#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"

#define Window GameWindow::getWindow()
#define GameEvent GameWindow::getEvent()

class GameWindow
{
private:

	static sf::ContextSettings* settings;

	static sf::RenderWindow* window;
	static unsigned int framerateLimit;

	static sf::Event* ev;

public:

	static void createWindow();
	static void deleteWindow();

	static sf::RenderWindow& getWindow();

	static unsigned int getFramerateLimit();
	static void setFramerateLimit(unsigned int FramerateLimit);

	static void setWindowSize(sf::Vector2u& WindowSize);
	static sf::ContextSettings* getWindowSettings();

	static sf::Event& getEvent();
};
