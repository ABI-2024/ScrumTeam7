#pragma once
#include <stdio.h>
#include <fstream>
#include "Actors.h"
#include "SFML/Graphics.hpp"
#include <stdlib.h>
class Wellen
{
	private:
		static short welleAnz;
		sf::Clock WellenTimer;
		sf::Clock EnemyTimer;

		/*bool WelleStatus;*/
		int welleDaten[3];
	public:
		Wellen();

		void setWellenDaten();
		int* getWellenDaten();

		void SpawnEnemy();
		void Time(Actors& test);

		void addWelle();
		short getWelle();


};

