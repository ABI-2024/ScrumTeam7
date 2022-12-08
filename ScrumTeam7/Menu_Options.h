#pragma once

#include "Button.h"

class Menu_Options
{
private:
	sf::Font* font;
	sf::Texture* buttonTexture;
	std::string* buttonText;
	Button* button;

	sf::Texture backgroundTexture;
	sf::RectangleShape background;

public:
	Menu_Options();
	~Menu_Options();


	void buttonEvents();
	void updateButtom();
	void render();


};

