#include "Wellen.h"
#include <iostream>
#include <string>

short Wellen::welleAnz = 0;

Wellen::Wellen() {
	welleDaten[0] = 0;
	welleDaten[1] = 0;
	welleDaten[2] = 0;
}

void Wellen::setWellenDaten() {
	std::ifstream wellenDaten;
	wellenDaten.open("Datenwellen.csv");
	std::string tmp;
	for (int n = 0; n < welleAnz; n++) {
		std::getline(wellenDaten, tmp, '\n');
	}
	for (int i = 0; i < 3; i++) {
		std::getline(wellenDaten, tmp, ';');
		welleDaten[i] = stoi(tmp);
	}
	std::getline(wellenDaten, tmp, '\n');
	addWelle();
	wellenDaten.close();
}

int* Wellen::getWellenDaten() {
	return welleDaten;
}

void Wellen::addWelle() {
	welleAnz++;
}

short Wellen::getWelle() {
	return this->welleAnz;
}

void Wellen::SpawnEnemy() {
	//clock.restart();
	Wellen* pWellen = new Wellen;
	pWellen->setWellenDaten();
	
}

void Wellen::Time(Actors& test) {
	if (EnemyTimer.getElapsedTime().asSeconds() >= welleDaten[3] / welleDaten[2]) {
		test.initializeEnemy(welleDaten[1], {0, (float)(rand() % 5) });
		EnemyTimer.restart();
	}
}