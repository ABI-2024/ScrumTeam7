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

		
		void WellenEnde(); // Checkt ob alle Schüler in der Welle getötet wurden
		void SpawnEnde(); // Checkt ob alle Schüler in der Welle gespawnt wurden

		void Wartefunktion(Geld&); //Setzt den Wellenspawn auf Pause
		void startWartetimer();

		void SpawnEnemy();
		/*void Time(Actors& test);*/

	public:

		void WellenDaten(); // Ließt die Daten aus der Datei aus

		void SortListeSchueler(); // Sortiert die Schüler aus der random Liste in ein Array

		void Wellenfunktion(Geld&); // 


		Wellen();
		void setFilename(const std::string&);

		//int* getWellenDaten();
		//std::list <int>* getSchuelerDaten();

		//void addWelle();
		/*int getWelle();
		bool getspawnEnde();
		bool getwellenEnde();
		bool getwarteTimer();
		bool geteof();*/

		bool geteof();

		void deletepSchueler();


};

