#pragma once

#include <vector>

#include "SFML/Graphics.hpp"

#include "enums.h"



class BaseTower
{
public:
	static std::vector<BaseTower*> Towers;
protected:

	sf::RectangleShape Body;
	
	bool alive;
	bool ReadyToAttack;

	float health;

	sf::Vector2f tilePosition;

	sf::Clock clock;
	sf::Time remainingAttackTime;

public:

	BaseTower(float Health, sf::Vector2f tilePosition, sf::Texture* texture);
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




