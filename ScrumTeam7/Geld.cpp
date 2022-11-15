#include "Geld.h"
#include <iostream>

using namespace std;

double Geld::Startgeld = 200;
Geld::Geld() {
	Kontostand = Startgeld;
}

Geld::~Geld(){}

double Geld::getKontostand() {
	return Kontostand;
}

void Geld::addKontostand(double betrag) {
	Kontostand += betrag;
}

void Geld::clearKontostand (){
	Kontostand = 0;
}