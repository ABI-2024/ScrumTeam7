#pragma once

#include "SFML/Graphics.hpp"

#include "enums.h"
#include "Geld.h"
#include <vector>

struct Grow {
	// Anzahl der Gegnerspawn
public:

	EnemyType type;
	float startAmount;

	sf::Clock timer;
	sf::Time remainTime;

	Grow(EnemyType ntype, float startAmount)
		:type(ntype), startAmount(startAmount)
	{	}
};

class InfinityWellen
{
private:
	int wellenCounter, score;

	sf::Clock nextWaveTimer;
	sf::Time timeBetweenWave;

	std::vector<Grow> enemyGrowth;
	
public:
	InfinityWellen();
	~InfinityWellen();

	void update(Geld&);
};

