#pragma once
#include "BaseEnemy.h"
class Emo : public BaseEnemy
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

	Emo(const sf::Vector2f& tilePosition);
	~Emo();

	int getRevenue() override;


	EnemyType getEnemyType() override;
	float getDamage() override;

	bool CollisionWithTower(sf::FloatRect& Tower) override;

	void move();

	void update() override;
};

