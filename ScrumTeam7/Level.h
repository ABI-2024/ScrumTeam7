#pragma once

#include <string>

#include "Geld.h"
#include "AActors.h"
#include "Shop.h"
#include "Menu_Pause.h"
#include "Wellen.h"
#include "TowerSelect.h"


class Level
{
protected:
	bool active;

	Geld geld;
	Shop shop;
	AActors actors;

	sf::Texture backgroundTexture;
	sf::RectangleShape background;

	sf::RectangleShape selecteionRectangle[2];

	bool paused;
	Menu_Pause menu;

	Wellen welle;

	sf::Vector2f TileSelection();
	void buttonEvents();
public:
	Level();
	virtual ~Level();


	virtual void start(std::string);
};

