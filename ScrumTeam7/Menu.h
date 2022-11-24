#pragma once

#include "SFML/Graphics.hpp"

class Menu
{
private:

	bool open;

	sf::Texture* buttonTexture[3]; // 0 Start	1 Options	2 Exit
	sf::RectangleShape button[3];

	void buttonEvents();

	void render();

	Menu();
	~Menu();
public:

	static void openMenu();
};

