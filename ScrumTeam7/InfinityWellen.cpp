#include "InfinityWellen.h"

#include "Window.h"
#include "AActors.h"
#include "Randomizer.h"

#include <math.h>

#define SPAWNTIME 5.f

InfinityWellen::InfinityWellen()
	:wellenCounter(0), score(0), timeBetweenWave(sf::seconds(60)), allSpawned(false)
{
	enemyGrowth.push_back({ EnemyType::TestEnemy, 6.f });
	enemyGrowth.push_back({ EnemyType::Nerd, 0.5f });
	enemyGrowth.push_back({ EnemyType::Steroidenking, 2.f });
	enemyGrowth.push_back({ EnemyType::Emo, 1.f });
	enemyGrowth.push_back({ EnemyType::Kreative, 1.5f });

	for (int i = 0; i < enemyGrowth.size(); i++) {
		enemyGrowth[i].anzahlDieseWelle = enemyGrowth[i].startAmount * powf(1.15, wellenCounter);
		enemyGrowth[i].spawnRateDieseWelle = enemyGrowth[i].startAmount / SPAWNTIME;
		enemyGrowth[i].nextSpawn = 0;
	}
}

InfinityWellen::~InfinityWellen()
{
}

void InfinityWellen::update(Geld& geld)
{

	float temp = 0;


	if (nextWaveTimer.getElapsedTime() <= sf::seconds(SPAWNTIME)) {
		for (int i = 0; i < enemyGrowth.size(); i++) {

			enemyGrowth[i].nextSpawn += enemyGrowth[i].spawnRateDieseWelle* dt;

			for (temp = 0; enemyGrowth[i].nextSpawn >= 1 && enemyGrowth[i].anzahlDieseWelle > 0;temp++) {
				enemyGrowth[i].nextSpawn--;
				enemyGrowth[i].anzahlDieseWelle--;
			}

			for (int j = 0; j < temp; j++) {
				AActors::create(enemyGrowth[i].type, sf::Vector2f(0.f, Randomizer::randomize(5)));
			}
		}
	}
	else
	{
		if (!allSpawned){
			for (int i = 0; i < enemyGrowth.size(); i++) {

				for (int j = 0; j < enemyGrowth[i].anzahlDieseWelle; j++) {
					AActors::create(enemyGrowth[i].type, sf::Vector2f(0.f, Randomizer::randomize(5)));
				}
			}
			allSpawned = true;
		}
	}

	if (nextWaveTimer.getElapsedTime() >= timeBetweenWave || 
		(AActors::enemies->size() == 0 && nextWaveTimer.getElapsedTime() >= timeBetweenWave - sf::seconds(40) )) {

		geld.addKontostand(25);

		wellenCounter++;
		nextWaveTimer.restart();

		for (int i = 0; i < enemyGrowth.size(); i++) {
			enemyGrowth[i].anzahlDieseWelle = enemyGrowth[i].startAmount * powf(1.15, wellenCounter);
			enemyGrowth[i].spawnRateDieseWelle = enemyGrowth[i].startAmount / SPAWNTIME;
			enemyGrowth[i].nextSpawn = 0;
		}

		allSpawned = false;

	}

}
