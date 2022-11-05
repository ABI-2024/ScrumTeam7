#pragma once

#include "SFML/Graphics.hpp"


class BaseTower
{
protected:
	int towerType;

	sf::RectangleShape Body;
	
	bool alive;
	bool ReadyToAttack;

	float health;

	sf::Vector2f tilePosition;

	sf::Clock clock;

	void initBaseVariables(int TowerType ,float Health, sf::Vector2f tilePosition, sf::Texture *texture);
public:

	BaseTower();
	~BaseTower();

	int getType();

	bool isAlive();
	bool isReadyToAttack();

	sf::FloatRect getFloaRect();
	sf::Vector2f getPosition();
	sf::Vector2f getTilePosition();

	void HasAttacked();
	void wasAttacked(float damage);

	void render();

	virtual void update() = 0;
};




