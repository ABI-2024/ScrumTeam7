#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"

#include "Window.h"

using namespace sf;
using namespace std;

class BaseAmmo
{
protected:

	bool hit;

	sf::RectangleShape Body;

	void initBaseVariables(sf::Vector2f TowerPosition, sf::Texture* texture);
public:
	BaseAmmo();
	BaseAmmo(sf::Vector2f TowerPosition);
	~BaseAmmo();

	bool isHit();
};


