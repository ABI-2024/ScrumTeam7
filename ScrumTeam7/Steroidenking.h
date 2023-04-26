#pragma once

#include "BaseEnemy.h"

class Steroidenking : public BaseEnemy
{
private:
	static EnemyType enemyType;

	static float Health;
	static float Damage[2];

	static int revenue;

	static sf::Vector2f dir[2];
	static sf::Texture* texture;

	static sf::Time attackSpeed;

	bool running;



public:
	static void LoadTexture();
	static void unLoadTexture();

	Steroidenking(const sf::Vector2f& tilePosition);
	~Steroidenking();

	int getRevenue() override;


	EnemyType getEnemyType() override;
	float getDamage() override;

	bool CollisionWithTower(sf::FloatRect& Tower) override;

	void move();

	void update() override;



};

