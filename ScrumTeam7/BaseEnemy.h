#pragma once

#include "Entity.h"
#include "Status_Effect.h"

#include "enums.h"

class BaseEnemy : public Entity
{
	template<class T> friend class Status_Proc;
public:
	static std::vector<BaseEnemy*> enemies;
protected:

	std::vector<Status_Proc<BaseEnemy>>procs;

	bool alive;
	bool readyToAttack;
	bool movable;
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
	virtual int getRevenue() = 0;

	sf::FloatRect getFloaRect();

	sf::Vector2f getPosition();
	void hasAttacked();
	void wasAttacked(float damage);

	// Status Effecte
	void addStatus_Proc(Status_Effect nStatus );	// Experimentel
	void updateStatus_Proc();


	virtual bool CollisionWithTower(sf::FloatRect& Tower) =0;

	void paused();
	void Continue();

	virtual void update() =0;
	void render();
};

