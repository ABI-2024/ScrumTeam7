#pragma once

#include "Actors.h"
#include "Shop.h"
#include "Menu_Pause.h"
#include "Wellen.h"
#include <string>

class Level
{
protected:
	bool active;

	Shop shop;
	Actors actors;

	sf::Texture backgroundTexture;
	sf::RectangleShape background;

	sf::RectangleShape selecteionRectangle[2];

	bool paused;
	Menu_Pause menu;

	Wellen welle;

	sf::Vector2f TileSelection();
	void buttonEvents();
	void Wellenfunktion();

public:
	Level();
	virtual ~Level();


	virtual void start(std::string);
};

