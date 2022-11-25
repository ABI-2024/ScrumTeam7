#pragma once

#include "SFML/Graphics.hpp"

class Menu
{
private:

	bool open;
	static int ans;

	sf::Font* font;
	sf::Text* buttonText;

	sf::Texture* buttonTexture;
	sf::RectangleShape* button;

	void buttonVisuals();
	void buttonEvents();

	void render();

	Menu();
	~Menu();
public:

	static int openMenu();
};

