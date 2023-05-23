#include "Level_Final.h"

Level_Final::Level_Final()
{
	backgroundTexture.loadFromFile("resource/Textures/Level/Background-Lehrerzimmer.png");
	background.setTexture(&backgroundTexture, 0);
}

Level_Final::~Level_Final()
{
}
