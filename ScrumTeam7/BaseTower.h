#pragma once

#include "Entity.h"

#include "enums.h"



class BaseTower : public Entity
{
public:
	static std::vector<BaseTower*> towers;
protected:
		
	bool alive;
	bool readyToAttack;

	float health;

	sf::Vector2f tilePosition;

	sf::Clock clock;
	sf::Time remainingAttackTime;

public:

	BaseTower(float Health, sf::Vector2f tilePosition, sf::Texture* texture);
	~BaseTower();


	bool isAlive();
	bool isReadyToAttack();

	sf::FloatRect getFloaRect();
	sf::Vector2f getPosition();
	sf::Vector2f getTilePosition();

	virtual TowerType getTowerType() = 0;


	void HasAttacked();
	void wasAttacked(float damage);

	void paused();
	void Continue();

	virtual void update() = 0;
	void render();
};




