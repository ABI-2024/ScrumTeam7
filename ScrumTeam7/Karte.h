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

	void setPosition(sf::Vector2f pos);

	sf::RectangleShape getBody();
	int getCost();
	TowerType getType();
	sf::Vector2f getPosition();
	bool getHovered();
	sf::FloatRect getHitBox();


	void update();

	void render();
};

