#pragma once

#include "SFML/Graphics.hpp"

#include "Button.h"

class Menu
{
private:

	bool open;		// Menü ist active/offen
	static int ans;	// Buttenaktions auswahl / Rückgabewert von OpenMenu

	// Titel anzeige
	sf::Texture titelTexture;	
	sf::RectangleShape titel;

	// Texte und Button
	sf::Font* font;
	sf::Texture* buttonTexture;
	std::string* buttonText;
	Button** button;

	// Buttenaktions
	void buttonEvents();

	// Render
	void render();

	// diese werden in openMenu aufgeruffen
	Menu();
	~Menu();
public:
	
	// Menü anzeige
	static int openMenu();
};

