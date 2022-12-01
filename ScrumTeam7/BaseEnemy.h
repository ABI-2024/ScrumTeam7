#pragma once
#include "enums.h"
#include "SFML/Graphics.hpp"

class BaseEnemy
{
protected:

	sf::RectangleShape Body;

	bool alive;
	bool ReadyToAttack;
	bool Movable;
	float health;

	float linePosition;

	sf::Clock clock;

	void initBaseVariables(float Health , float linePosition, sf::Texture *texture);
public:
	BaseEnemy();
	~BaseEnemy();

	bool isAlive();
	bool isReadyToAttack();


	virtual EnemyType getEnemyType() = 0;
	virtual float getDamage() = 0;

	void hasAttacked();
	void wasAttacked(float damage);

	sf::FloatRect getFloaRect();

	virtual bool CollisionWithTower(sf::FloatRect& Tower) =0;

	virtual void update() =0;
	void render();
};

