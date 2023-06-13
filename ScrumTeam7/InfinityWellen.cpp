#include "InfinityWellen.h"

#include "AActors.h"
#include "Randomizer.h"

#include <math.h>

InfinityWellen::InfinityWellen()
	:wellenCounter(0), score(0), timeBetweenWave(sf::seconds(60))
{
	enemyGrowth.push_back({ EnemyType::TestEnemy, 10.f });
	enemyGrowth.push_back({ EnemyType::Nerd, 5.f });
	enemyGrowth.push_back({ EnemyType::Steroidenking, 3.f });
}

InfinityWellen::~InfinityWellen()
{
}

void InfinityWellen::update(Geld& geld)
{

	float temp = 0, rate = 0, spawnTime = 10;


	if (nextWaveTimer.getElapsedTime() <= sf::seconds(spawnTime)) {
		for (int i = 0; i < enemyGrowth.size(); i++) {

			// Anzahl an Enemies, die gespwant werden 
			// Enemey Spawnrate über 5 Sekunden
			rate = spawnTime / enemyGrowth[i].startAmount * powf(1.15, wellenCounter);

			if (enemyGrowth[i].timer.getElapsedTime().asSeconds() / rate >= 1) {
				enemyGrowth[i].remainTime = enemyGrowth[i].timer.restart() + enemyGrowth[i].remainTime;

				temp = int(enemyGrowth[i].remainTime.asSeconds() / rate);
				enemyGrowth[i].remainTime -= sf::seconds(temp * rate);

				for (int j = 0; j < temp; j++) {
					AActors::create(enemyGrowth[i].type, sf::Vector2f(0.f, Randomizer::randomize(5)));
				}
			}
		}
	}

	if (nextWaveTimer.getElapsedTime() >= timeBetweenWave || 
		(AActors::enemies->size() == 0 && nextWaveTimer.getElapsedTime() >= timeBetweenWave - sf::seconds(20) )) {

		geld.addKontostand(50);

		wellenCounter++;
		nextWaveTimer.restart();

		for (int i = 0; i < enemyGrowth.size(); i++) {
			enemyGrowth[i].remainTime = sf::seconds(0);
			enemyGrowth[i].timer.restart();
		}


	}

}
