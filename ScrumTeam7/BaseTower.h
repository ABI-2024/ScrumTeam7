#pragma once
#include "enums.h"
#include "SFML/Graphics.hpp"


class BaseTower
{
protected:

	sf::RectangleShape Body;
	
	bool alive;
	bool ReadyToAttack;

	float health;

	sf::Vector2f tilePosition;

	sf::Clock clock;
	sf::Time remainingAttackTime;

	void initBaseVariables(float Health, sf::Vector2f tilePosition, sf::Texture *texture);
public:

	BaseTower();
	~BaseTower();

	bool isAlive();
	bool isReadyToAttack();

	sf::FloatRect getFloaRect();
	sf::Vector2f getPosition();
	sf::Vector2f getTilePosition();


	virtual TowerType getTowerType() = 0;

	void HasAttacked();
	void wasAttacked(float damage);


	void paused();
	void Continue();

	void render();

	virtual void update() = 0;
};




