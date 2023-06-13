#pragma once

#include <string>

#include "Geld.h"
#include "AActors.h"
#include "Shop.h"
#include "Menu_Pause.h"
#include "Wellen.h"
#include "TowerSelect.h"

#include "Progression.h"

class Level
{
protected:
	bool active;

	sf::RectangleShape endOfTheLevel;
	sf::Font font;
	sf::Text gameOver, victory;

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

	virtual void endLevel(bool victory);
public:
	Level();
	virtual ~Level();


	virtual void start(std::string  , Progression&);
};

