#pragma once

#include "Button.h"

class Menu_Pause
{
private:

	sf::RectangleShape background;

	sf::Font font;
	sf::Texture* buttonTexture;
	std::string* buttonText;
	Button** button;

public:
	Menu_Pause();
	~Menu_Pause();

	int mouseClick();
	void update();
	void render();
};

