#pragma once

#include "Entity.h"
#include "Status_Effect.h"

#include "enums.h"

class BaseEnemy : public Entity
{
	template<class T> friend class Status_Proc;
protected:

	std::vector<Status_Proc<BaseEnemy>>procs;

	bool movable;
	float health;

	sf::Vector2f tilePosition;

	sf::Clock clock;
	sf::Time remainingAttackTime;

public:

	BaseEnemy(float Health,	sf::Vector2f tilePosition, sf::Texture* texture);
	~BaseEnemy();

	const sf::Vector2f& getTilePosition();
	virtual EnemyType getEnemyType() = 0;
	virtual float getDamage() = 0;
	virtual int getRevenue() = 0;

	sf::FloatRect getFloaRect();

	sf::Vector2f getPosition();


	// Status Effecte
	void addStatus_Proc(Status_Effect nStatus );	// Experimentel
	void updateStatus_Proc();

	void paused();
	void Continue();
};

