#include "Level_2.h"

Level_2::Level_2()
{
	backgroundTexture.loadFromFile("resource/Textures/Level/Background_Sporthalle.png");
	background.setTexture(&backgroundTexture, 0);
}

Level_2::~Level_2()
{
}
