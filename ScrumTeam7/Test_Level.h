#pragma once
#include "Actors.h"
#include "Menu_Pause.h"

class Test_Level
{
private:
	bool active;

	Actors actors;

	bool paused;
	Menu_Pause menu;


	sf::Vector2f TileSelection();
	void buttonEvents();
public:
	Test_Level();
	~Test_Level();

	void startLevel();
};
