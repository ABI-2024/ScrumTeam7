#pragma once

#include "Button.h"

class Menu_Pause
{
private:

	// Hintergrund
	sf::RectangleShape background;

	// Texte und Button
	sf::Font font;
	sf::Texture* buttonTexture;
	std::string* buttonText;
	Button** button;

public:
	Menu_Pause();
	~Menu_Pause();

	// Rückgabewert welcher Button geklickt wurde
	int mouseClick();

	// update Menu / Buttons
	void update();

	// render Menu
	void render();
};

