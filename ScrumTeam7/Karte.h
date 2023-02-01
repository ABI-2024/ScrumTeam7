#pragma once

#include "SFML/Graphics.hpp"
#include "enums.h"

class Karte
{
private:
	sf::RectangleShape Body;
	int cost;
	TowerType type;
	bool hovered;
	sf::FloatRect hitBox;

public:
	Karte(int cost, TowerType type, sf::Texture* texture, sf::Vector2f pos);
	~Karte();

	int getCost();
	TowerType getType();
	sf::Vector2f getPosition();
	bool getHovered();


	void update();

	void render();
};

