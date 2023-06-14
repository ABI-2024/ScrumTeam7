#pragma once
#include "BaseEnemy.h"
class Emo : public BaseEnemy
{
private:
	static EnemyType enemyType;

	static float Health;
	static float Damage;
	static float SelfharmDMG;

	static int revenue;

	static sf::Vector2f dir;
	static sf::Texture* texture;

	static sf::Time attackSpeed;

	sf::Clock programmzeit;

public:
	static void LoadTexture();
	static void unLoadTexture();

	Emo(const sf::Vector2f& tilePosition);
	virtual ~Emo();

	void move();

	void update() override;
};

