#include "Shop.h"
#include "Window.h"
#include <iostream>

Shop::Shop() {

	sellection = -1;

	font.loadFromFile("resource/fonts/arial.ttf");
	t.loadFromFile("resource/Textures/SportLehre1.png");

	this->anzahlKarten = 5;

	//this->karten = new Karte(100, 1, &t, { 25.f, 90.f });
	karten = new Karte * [anzahlKarten];
	for (int i = 0; i < anzahlKarten; i++) {
		this->karten[i] = new Karte(100, TowerType::TestTower, &t, { 60.f, 150.f * i + 90 });
	}

	this->text = new sf::Text[anzahlKarten];

	for (int i = 0; i < anzahlKarten; i++) {

		text[i].setFont(font);
		text[i].setCharacterSize(20);
		text[i].setPosition(karten[i]->getPosition());
		text[i].setFillColor(sf::Color::Green);
		text[i].setString(std::to_string(karten[i]->getCost()));

	}

}

Shop::Shop(int anzahlKarten, Karte** karten) {

	font.loadFromFile("resource/fonts/arial.ttf");
	this->anzahlKarten = anzahlKarten;
	this->karten = karten;
	this->sellection = -1;

	this->text = new sf::Text[anzahlKarten];

	for(int i = 0; i < anzahlKarten; i++){
	
		text[i].setFont(font);
		text[i].setCharacterSize(20);
		text[i].setPosition(karten[i]->getPosition());
		text[i].setFillColor(sf::Color::Green);
		text[i].setString(std::to_string(karten[i]->getCost()));

	}
}

Shop::~Shop() {
	delete[] this->text;
}


int Shop::getSellection() {
	return this->sellection;
}


void Shop::setSellection(int s) {
	if (s > 0 && s < 6) {
		this->sellection = s;
	}
	else this->sellection = 0;
}



void Shop::buttonEvents(Actors& actors, sf::Vector2f tilePos)
{
	if (sellection != -1) {
		actors.initializeTower(karten[sellection]->getType(), tilePos);
	}
	this->sellection = -1;
	for (int i = 0; i < anzahlKarten; i++) {
		if (karten[i]->getHovered()) {
			this->sellection = i;
		}
	}
}


void Shop::render() {
	for (int i = 0; i < anzahlKarten; i++) {
		karten[i]->render();

		


		GameWindow::getWindow().draw(text[i]);
	}

}