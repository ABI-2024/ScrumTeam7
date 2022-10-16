#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

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

	static void setWindowSettings(); // für Options Änderungen
};
