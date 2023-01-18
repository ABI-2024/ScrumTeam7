#pragma once

#include "SFML/Graphics.hpp"

class Karte
{
private:
	sf::RectangleShape Body;
	int cost;
	int type;

public:
	Karte(int cost, int type, sf::Texture* texture, sf::Vector2f pos);
	~Karte();

	int getCost();
	int getType();
	sf::Vector2f getPosition();

	void render();
};

