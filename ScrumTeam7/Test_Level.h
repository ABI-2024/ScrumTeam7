#pragma once
#include "AActors.h"
//#include "Shop.h"
#include "Menu_Pause.h"
//#include "Wellen.h"
//#include "TowerSelect.h"

class Test_Level
{
private:
	bool active;

	//Shop testShop;
	AActors actors;

	sf::Texture back;
	sf::RectangleShape background;

	sf::RectangleShape selecteionRectangle[2];

	bool paused;
	Menu_Pause menu;

	//Wellen testwelle;

	sf::Vector2f TileSelection();
	void buttonEvents();
public:
	Test_Level();
	~Test_Level();

	//void Wellenfunktion();

	void startLevel();
};
