#include "Level_3.h"

Level_3::Level_3()
{
	timeToWin = sf::seconds(500);

	backgroundTexture.loadFromFile("resource/Textures/Level/Background_Sporthalle.png");
	background.setTexture(&backgroundTexture, 0);
}

Level_3::~Level_3()
{
}
