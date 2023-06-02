#include "Wellen.h"
#include "AActors.h"
#include <iostream>

Wellen::Wellen() {
	welleAnz = 0;
	welleDaten[0] = 0;
	welleDaten[1] = 0;
	spawnclock = nullptr;
}

void Wellen::WellenDaten() {
	std::ifstream Datei;
	Datei.open(filename); //Dokument wird neu ge�ffnet (Dateiposition reseted)
	std::string tmp;
	int dateiposition;
	char debug;

	firstSpawn = true;
	spawnEnde = false;
	wellenEnde = false;

	schuelerDaten->clear();

	for (int n = 0; n < welleAnz; n++) { //Skippt bis zur relevanten Teil im Dokument
		if (Datei.eof()) {
			eof = true;
			return;
		}
		std::getline(Datei, tmp, '0');
	}
	for (int i = 0; i < 2; i++) { //Lie�t Wellendaten aus
		if (Datei.eof()) {
			eof = true;
			return;
		}
		std::getline(Datei, tmp, ';');
		welleDaten[i] = stoi(tmp);
	}
	do { //Lie�t Sch�lerdaten aus
		if (Datei.eof()) {
			eof = true;
			return;
		}
		std::getline(Datei, tmp, ';');
		schuelerDaten->push_back(stoi(tmp));
		dateiposition = Datei.tellg();
		Datei.get(debug);
		Datei.seekg(dateiposition);
	} while (debug != '0');
	/*std::getline(wellenDaten, tmp, '\n');*/
	addWelle();
	Datei.close();
}

void Wellen::setFilename(const std::string& name)
{
	filename = name;
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

int Wellen::getWelle() {
	return this->welleAnz;
}

void Wellen::SortListeSchueler() {
	int j = 0;
	pSchueler = new int* [schuelerDaten->size() / 3 + 1];

	pSchueler[0] = new int(schuelerDaten->size() / 3);
	spawnclock = new sf::Clock[*pSchueler[0]];

	auto IList = schuelerDaten->begin();
	
	for (int i = 1; i < schuelerDaten->size() / 3 + 1; i++) {
		pSchueler[i] = new int[3];
		j = 0;
		for (; j != 3 and IList != schuelerDaten->end(); j++, IList++) {
			pSchueler[i][j] = *IList;
		}
	}
}

void Wellen::WellenEnde() { // Checkt ob alle Sch�ler in der Welle get�tet wurden
	if (AActors::enemies->size() == 0) { // Lie�t die Anzahl der lebenden Sch�ler aus
		wellenEnde = true;
		//delete[] * pSchueler; //L�scht die lehre pSch�ler
		//*pSchueler = nullptr;
		//delete[] pSchueler;
		//pSchueler = nullptr;
	}
}

void Wellen::SpawnEnde() { // Checkt ob alle Sch�ler in der Welle gespawnt wurden
	this->spawnEnde = true;
	for (int i = 1; i <= *pSchueler[0]; i++) {
		if (pSchueler[i][1] > 0) { // Falls noch Sch�ler nicht gespawnt wurden wird spawnEnde wieder auf false gesetzt
			this->spawnEnde = false;
		}
	}
}

void Wellen::SpawnEnemy() {
	SpawnEnde();
	if (spawnEnde == true) { //Wenn alle Sch�ler der Welle gespawnt wurden muss die Spawnfunktion nicht gecallt werden
		return;
	}
	if (firstSpawn == true) { //Plichtspawn und Erstellung des Timers
		for (int i = 1; i <= *pSchueler[0]; i++) {

			/*AActors::create((EnemyType)pSchueler[i][0], { 0, (float)(rand() % 5) });
			pSchueler[i][1] = pSchueler[i][1] - 1;*/
			spawnclock[i].restart();
		}
		firstSpawn = false;
	}
	for (int b = 1; b <= *pSchueler[0]; b++) { //Kontinuierlicher Spawn
		if (pSchueler[b][1] > 0 and spawnclock[b].getElapsedTime() >= sf::seconds(pSchueler[b][2])) { //�berpr�fung ob noch Sch�ler gespawnt werden m�ssen und ob die notwendige Ziet vergangen ist
			AActors::create((EnemyType)pSchueler[b][0], { 0, (float)(rand() % 5) });
			pSchueler[b][1]--;
			spawnclock[b].restart();
		}
	}
}

void Wellen::startWartetimer() {
	warteclock.restart();
	this->warteTimer = false;
}

void Wellen::Wartefunktion(Geld& geld) {
	if ((int)warteclock.getElapsedTime().asSeconds() > welleDaten[1]) {
		this->warteTimer = true;
		geld.addKontostand(200 * (1 + 0.1 * getWelle())); // Geld pro Welle
		WellenDaten();
		SortListeSchueler();
	}
}


void Wellen::Wellenfunktion(Geld& geld) {
	if (this->geteof() == true) return;
	this->SpawnEnde();
	if (this->getspawnEnde() == false) {
		this->SpawnEnemy();
	}
	else {
		this->WellenEnde();
	}
	if (this->getwellenEnde() == true) {
		if (this->getwarteTimer() == true)
			this->startWartetimer();
		this->Wartefunktion(geld);
	}
}

bool Wellen::getspawnEnde() {
	return this->spawnEnde;
}

bool Wellen::getwellenEnde() {
	return this->wellenEnde;
}

bool Wellen::getwarteTimer() {
	return this->warteTimer;
}

bool Wellen::geteof() {
	return this->eof;
}

void Wellen::deletepSchueler() {
	
}


/*
Wellen testwelle;
this->WelleDaten();
this->SortListeSchueler(); //geht nicht: Frage an Leo ist R�ckgabewert int** wichtig?

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
		Wartefunktion();
	}
}

*/
