#pragma once

#include "SFML/Graphics.hpp"

class BaseEnemy
{
protected:

	int enemyType;
	sf::RectangleShape Body;

	bool alive;
	bool ReadyToAttack;

	float health;
	float damage;

	float linePosition;

	sf::Clock clock;

	void initBaseVariables(int EnemyType ,float Damage ,float Health , float linePosition, sf::Texture *texture);
public:
	BaseEnemy();
	~BaseEnemy();

	bool isAlive();
	bool isReadyToAttack();
	int getType();
	float getDamage();

	void hasAttacked();
	void wasAttacked(float damage);

	sf::FloatRect getFloaRect();

	virtual bool CollisionWithTower(sf::FloatRect& Tower) =0;

	virtual void update() =0;
	void render();
};

