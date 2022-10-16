#pragma once

#include "SFML/Graphics.hpp"

class BaseTower
{
protected:
	sf::RectangleShape Body;

	bool alive;
	float Health;


	sf::Clock clock;
	sf::Time timmer;

	void initVariables();
public:

	BaseTower();
	~BaseTower();


};