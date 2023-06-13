#pragma once
#include "BaseEnemy.h"
class Simp : public BaseEnemy
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

	Simp(const sf::Vector2f& tilePosition);
	virtual ~Simp();

	void move();

	void update() override;
};
