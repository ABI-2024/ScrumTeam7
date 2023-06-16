#pragma once
#include "Window.h"
#include "Button.h"

class Menu_Options
{
private:
	bool open;		// Menü ist active/offen

	// Hintergrund
	sf::Texture* backgroundTexture;
	sf::RectangleShape background;

	// Texte und Button
	sf::Font font;
	sf::Texture* buttonTexture;
	std::string* buttonText;
	Button** button;

	// settings die verändert werden
	Settings settings;

	// Änderbare Fenstergrößen
	sf::Vector2u aufloesung[6];

	Menu_Options();
	~Menu_Options();

	// Buttenaktions
	void buttonEvents();
	void updateButtom();

	// Render
	void render();

public:

	// Menü anzeige
	static void openOptions();

};

