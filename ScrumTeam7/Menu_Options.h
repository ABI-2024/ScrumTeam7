#pragma once

#include "Button.h"

class Menu_Options
{
private:
	bool open;

	sf::Font font;
	sf::Texture* buttonTexture;
	std::string* buttonText;
	Button* button;

	sf::Texture* backgroundTexture;
	sf::RectangleShape background;

	Menu_Options();
	~Menu_Options();

	void buttonEvents();
	void updateButtom();
	void render();

public:

	static void openOptions();

};

