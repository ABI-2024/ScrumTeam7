#pragma once

#include "SFML/Graphics.hpp"
#include "Button.h"

#include "Window.h"

class Level_Selector
{
private:
	bool open;


	std::string* datafiles;

	sf::Font* font;
	sf::Texture** buttonTexture;
	std::string* buttonText;
	Button** buttons;

	void buttonEvents();
	void render();
public:
	Level_Selector();
	~Level_Selector();

	void openMenu();
};
