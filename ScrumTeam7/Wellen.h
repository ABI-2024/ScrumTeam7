#pragma once
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <list>
#include <string>

#include "Actors.h"
#include "SFML/Graphics.hpp"
#include "Geld.h"
class Wellen
{
	private:
		std::string filename;

		Geld testgeld;
		int welleAnz;

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

		void Wartefunktion(Actors&); //Setzt den Wellenspawn auf Pause
		void startWartetimer();

		void GeldproWelle(Actors&);

		void SpawnEnemy(Actors&);
		/*void Time(Actors& test);*/

		void setFilename(const std::string&);

		int* getWellenDaten();
		std::list <int>* getSchuelerDaten();

		void addWelle();
		int getWelle();
		bool getspawnEnde();
		bool getwellenEnde();
		bool getwarteTimer();
		bool geteof();


};

