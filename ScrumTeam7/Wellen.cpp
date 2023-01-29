#include "Wellen.h"
#include <iostream>
#include <string>

int Wellen::welleAnz = 0;

Wellen::Wellen() {
	welleDaten[0] = 0;
	welleDaten[1] = 0;
}

void Wellen::WellenDaten() {
	std::ifstream Datei;
	Datei.open("Datenwellen.csv"); //Dokument wird neu geöffnet (Dateiposition reseted)
	std::string tmp;
	int dateiposition;
	char debug;

	firstSpawn = true;
	spawnEnde = false;

	for (int n = 0; n < welleAnz; n++) { //Skippt bis zur relevanten Teil im Dokument
		std::getline(Datei, tmp, '\n');
	}
	for (int i = 0; i < 2; i++) { //Ließt Wellendaten aus
		std::getline(Datei, tmp, ';');
		welleDaten[i] = stoi(tmp);
	}
	do { //Ließt Schülerdaten aus
		std::getline(Datei, tmp, ';');
		schuelerDaten->push_back(stoi(tmp));
		dateiposition = Datei.tellg();
		Datei.get(debug);
		Datei.seekg(dateiposition);
	} while (debug != '\n');
	/*std::getline(wellenDaten, tmp, '\n');*/
	addWelle();
	setFalse();
	Datei.close();
}

int* Wellen::getWellenDaten() {
	return welleDaten;
}

std::list <int>* Wellen::getSchuelerDaten() {
	return this->schuelerDaten;
}

void Wellen::addWelle() {
	welleAnz++;
}

short Wellen::getWelle() {
	return this->welleAnz;
}

int** Wellen::SortListeSchueler() {
	int j = 0;
	pSchueler = new int* [schuelerDaten->size() / 3 + 1];

	pSchueler[0] = new int(schuelerDaten->size() / 3);
	spawnclock = new sf::Clock[*pSchueler[0]];

	for (int i = 1; i < schuelerDaten->size() / 3 + 1; i++) {
		pSchueler[i] = new int[3];
		j = 0;
		for (auto IList = schuelerDaten->begin(); IList != schuelerDaten->end(); j++, IList++) {
			pSchueler[i][j] = *IList;
			if (j == 2) break;
		}
	}
	return this->pSchueler;
}

void Wellen::WellenEnde(Actors& EnemyAlive) {
	if (EnemyAlive.getEnemy()->size() == 0) {
		wellenEnde = false;
	}
}

void Wellen::SpawnEnde() {
	this->spawnEnde = true;
	for (int i = 0; i < *pSchueler[0]; i++) {
		if (pSchueler[i][1] > 0) {
			this->spawnEnde = false;
		}
	}
}

void Wellen::setFalse() {
	WelleLesenStatus = false;
}

void Wellen::setTrue() {
	WelleLesenStatus = true;
}

void Wellen::SpawnEnemy(Actors& test) {
	SpawnEnde();
	if (spawnEnde == true) { //Wenn alle Schüler der Welle gespawnt wurden muss die Spawnfunktion nicht gecallt werden
		return;
	}
	if (firstSpawn == true) { //Plichtspawn und Erstellung des Timers
		for (int i = 0; i < *pSchueler[0]; i++) {
			test.initializeEnemy(pSchueler[i][0], { 0, (float)(rand() % 5) });
			pSchueler[i][1] = pSchueler[i][1] - 1;
			spawnclock[i].restart();
		}
		firstSpawn == false;
	}
	for (int b = 0; b < *pSchueler[0]; b++) { //Kontinuierlicher Spawn
		if (pSchueler[b][1] > 0 and (int)spawnclock[b].getElapsedTime().asSeconds() - pSchueler[b][2] >= 0) { //Überprüfung ob noch Schüler gespawnt werden müssen und ob die notwendige Ziet vergangen ist
			test.initializeEnemy(pSchueler[b][0], { 0, (float)(rand() % 5) });
			spawnclock[b].restart();
		}
	}
}

void Wellen::startWartetimer() {
	warteclock.restart();
	this->warteTimer = false;
}

void Wellen::Wartefunktion() {
	WelleLesenStatus = true;
	if ((int)warteclock.getElapsedTime().asSeconds() - welleDaten[1]) {
		WellenDaten();
	}
}


/*
Wellen testwelle;
testwelle.WelleDaten();

belibige schleife(){
	maybe wird alles folgende eine eigene Funktion in der Klasse der Schleife?
	if (spawnEnde == false) {
		SpawnEnemy();
		}
	else () {
		WellenEnde(Actors& testActors);
	}
	if (wellenEnde == true){
		if (warteTimer == true) {
			startWartetimer();
		}
	}


	
	

}






*/
