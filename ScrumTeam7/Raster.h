#pragma once

#include "SFML/Graphics.hpp"
#include "Window.h"

class Raster
{
private:
	sf::RectangleShape rectangle;
public:
	Raster(int, int);
	void render();
	void setRasterPosition(int, int);
};

