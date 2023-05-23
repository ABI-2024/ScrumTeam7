#pragma once
#include "Window.h"
#include "Button.h"

class Menu_Options
{
private:
	bool open;

	sf::Font font;
	sf::Texture* buttonTexture;
	std::string* buttonText;
	Button** button;

	sf::Texture* backgroundTexture;
	sf::RectangleShape background;

	Settings settings;
	sf::Vector2u aufloesung[6];

	Menu_Options();
	~Menu_Options();

	void buttonEvents();
	void updateButtom();
	void render();

public:

	static void openOptions();

};

