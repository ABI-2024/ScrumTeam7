#include "Level_1.h"

Level_1::Level_1()
{

	backgroundTexture.loadFromFile("resource/Textures/Level/Background-Tutorial-3.png");
	background.setTexture(&backgroundTexture,0);
}

Level_1::~Level_1()
{
}
