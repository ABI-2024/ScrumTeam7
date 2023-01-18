#pragma once

#include "SFML/Graphics.hpp"
#include "Window.h"

class Raster
{
public:
	static float offset;
private:
	sf::RectangleShape rectangle;
public:
	Raster(int, int);
	void render();
	void setRasterPosition(int, int);
};

