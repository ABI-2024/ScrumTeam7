#pragma once
#include <stdio.h>
#include <fstream>
#include "Actors.h"
#include "SFML/Graphics.hpp"
#include <stdlib.h>
#include <list>
class Wellen
{
	private:
		static int welleAnz;
		bool WelleLesenStatus = true;
		bool firstSpawn = true;
		int welleDaten[2];
		std::list <int>* schuelerDaten = new std::list <int>;
		int** pSchueler;
		sf::Clock* spawnclock;
		sf::Clock warteclock;
	public:
		Wellen();

		void WellenDaten();

		std::list <int>* getSchuelerDaten();
		int* getWellenDaten();

		int** SortListeSchueler();

		void Wartefunktion();



		void SpawnEnemy(Actors&);
		/*void Time(Actors& test);*/

		void setFalse();
		void setTrue();

		void addWelle();
		short getWelle();


};

