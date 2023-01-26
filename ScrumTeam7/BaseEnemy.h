#pragma once

#include <vector>

#include "SFML/Graphics.hpp"

#include "enums.h"

class BaseEnemy
{
public:
	static std::vector<BaseEnemy*> Enemies;
protected:

	sf::RectangleShape Body;

	bool alive;
	bool ReadyToAttack;
	bool Movable;
	float health;

	sf::Vector2f tilePosition;

	sf::Clock clock;
	sf::Time remainingAttackTime;

public:

	BaseEnemy(float Health,	sf::Vector2f tilePosition, sf::Texture* texture);
	~BaseEnemy();

	bool isAlive();
	bool isReadyToAttack();
	const sf::Vector2f& getTilePosition();

	virtual EnemyType getEnemyType() = 0;
	virtual float getDamage() = 0;

	void hasAttacked();
	void wasAttacked(float damage);

	sf::FloatRect getFloaRect();

	virtual bool CollisionWithTower(sf::FloatRect& Tower) =0;

	void paused();
	void Continue();

	virtual void update() =0;
	void render();
};

