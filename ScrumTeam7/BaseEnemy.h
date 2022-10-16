#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"

#include "Window.h"

class BaseEnemy
{
protected:
	sf::RectangleShape Body;

	bool alive;
	float Health;

	float linePosition;

	sf::Clock attackTimer;

	void initBaseVariables(float EnemyHealth , float linePosition, sf::Texture *texture);
public:
	BaseEnemy();
	~BaseEnemy();
};

