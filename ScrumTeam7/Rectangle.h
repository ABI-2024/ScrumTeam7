#pragma once
#include "SFML/Graphics.hpp"
#include "Window.h"
class Rectangle
{
private:
	sf::RectangleShape rectangle;
public:
	Rectangle(int, int);
	void render();
	void setRectanglePosition(int, int);
};

