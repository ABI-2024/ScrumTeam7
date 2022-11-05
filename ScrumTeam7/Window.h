#pragma once

#include <SFML/Graphics.hpp>

// Es darf nur ein Objekt dieser Klasse geben

class GameWindow
{
private:

	static sf::RenderWindow* window;
	static unsigned int framerateLimit;

public:

	GameWindow();
	~GameWindow();

	static sf::RenderWindow& getWindow();

	static unsigned int getFramerateLimit();
	static void setFramerateLimit(unsigned int FramerateLimit);

	static void setWindowSettings(); // für Options Änderungen
};
