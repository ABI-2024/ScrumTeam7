#pragma once

#include <vector>

#include "SFML/Graphics.hpp"

#include "Window.h"
#include "TestAmmo.h"

using namespace sf;
using namespace std;

class BaseTower
{
protected:
	sf::RectangleShape Body;
	
	bool alive;
	float Health;

	sf::Vector2f tilePosition;

	sf::Clock clock;

	void initBaseVariables(float towerHealth, sf::Vector2f tilePosition, sf::Texture *texture);
public:

	BaseTower();
	~BaseTower();
};




