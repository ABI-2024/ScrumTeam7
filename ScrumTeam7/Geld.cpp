#include "Geld.h"
#include "Window.h"
#include <iostream>

using namespace std;

int Geld::Startgeld = 200;
Geld::Geld() {
	Kontostand = Startgeld;
	font.loadFromFile("resource/fonts/arial.ttf");
	text.setFont(font);
	text.setCharacterSize(20);
	text.setPosition(1500, 30);
	text.setFillColor(sf::Color::Red);
}

Geld::~Geld(){}

int Geld::getKontostand() {
	return Kontostand;
}

void Geld::addKontostand(int betrag) {
	Kontostand += betrag;
}

void Geld::subKontostand(int betrag) {
	Kontostand -= betrag;
}

void Geld::clearKontostand (){
	Kontostand = 0;
}

void Geld::render()
{
	text.setString(std::to_string( Kontostand));
	GameWindow::getWindow().draw(text);
}