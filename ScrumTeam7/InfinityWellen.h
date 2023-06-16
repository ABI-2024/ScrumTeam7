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

	float anzahlDieseWelle , nextSpawn;
	float spawnRateDieseWelle;

	Grow(EnemyType ntype, float startAmount)
		:type(ntype), startAmount(startAmount), anzahlDieseWelle(0.f), spawnRateDieseWelle(0.f), nextSpawn(0)
	{	}
};

class InfinityWellen
{
private:
	int wellenCounter, score;

	sf::Clock nextWaveTimer;
	sf::Time timeBetweenWave;

	bool allSpawned;
	std::vector<Grow> enemyGrowth;
	
public:
	InfinityWellen();
	~InfinityWellen();

	void update(Geld&);
};

