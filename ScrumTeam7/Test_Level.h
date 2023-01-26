#pragma once
#include "Actors.h"
#include "Shop.h"
#include "Menu_Pause.h"

class Test_Level
{
private:
	bool active;

	Shop testShop;
	Actors actors;

	bool paused;
	Menu_Pause menu;

	void buttonEvents();
public:
	Test_Level();
	~Test_Level();

	void startLevel();
};
