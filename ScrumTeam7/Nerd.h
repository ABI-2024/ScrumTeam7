#pragma once
#include "BaseEnemy.h"
class Nerd : public BaseEnemy
{
private:
	static EnemyType enemyType;

	static float Health;
	static float Damage;

	static int revenue;

	static sf::Vector2f dir;
	static sf::Texture* texture;

	static sf::Time attackSpeed;

	sf::Clock programmzeit;

public:
	static void LoadTexture();
	static void unLoadTexture();

	Nerd(const sf::Vector2f& tilePosition);
	~Nerd();

	int getRevenue() override;

	EnemyType getEnemyType() override;
	float getDamage() override;

	void move();

	void manipulation();

	void update() override;
};

