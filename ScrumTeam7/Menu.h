#pragma once

#include "SFML/Graphics.hpp"

#include "Button.h"

class Menu
{
private:

	bool open;
	static int ans;

	sf::Font* font;
	sf::Texture* buttonTexture;
	std::string* buttonText;
	Button* button;


	void buttonEvents();

	void render();

	Menu();
	~Menu();
public:

	static int openMenu();
};

