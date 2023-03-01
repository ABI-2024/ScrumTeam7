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

		bool firstSpawn = true;
		bool wellenEnde = false;
		bool spawnEnde = false;
		bool warteTimer = true;
		bool eof = false;


		int welleDaten[2];
		std::list <int>* schuelerDaten = new std::list <int>;
		int** pSchueler = 0;
		sf::Clock* spawnclock;
		sf::Clock warteclock;
	public:
		Wellen();

		void WellenDaten(); // Ließt die Daten aus der Datei aus

		void SortListeSchueler(); // Sortiert die Schüler aus der random Liste in ein Array
		
		void WellenEnde(Actors&); // Checkt ob alle Schüler in der Welle getötet wurden
		void SpawnEnde(); // Checkt ob alle Schüler in der Welle gespawnt wurden

		void Wartefunktion(); //Setzt den Wellenspawn auf Pause
		void startWartetimer();


		void SpawnEnemy(Actors&);
		/*void Time(Actors& test);*/

		int* getWellenDaten();
		std::list <int>* getSchuelerDaten();

		void addWelle();
		int getWelle();
		bool getspawnEnde();
		bool getwellenEnde();
		bool getwarteTimer();
		bool geteof();


};

