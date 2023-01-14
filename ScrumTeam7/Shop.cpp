#include "Shop.h"
#include "Window.h"
#include <iostream>

Shop::Shop(int anzahlKarten, Karte** karten) {
	font.loadFromFile("arial.ttf");
	this->anzahlKarten = anzahlKarten;
	this->karten = karten;

	this->text = new sf::Text[anzahlKarten];

	for(int i = 0; i < anzahlKarten; i++){
	
		text[i].setFont(font);
		text[i].setCharacterSize(20);
		text[i].setPosition((*karten)[i].getPosition());
		text[i].setFillColor(sf::Color::Green);
		text[i].setString(std::to_string((*karten)[i].getCost()));

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


void Shop::render() {
	for (int i = 0; i < anzahlKarten; i++) {
		(*karten)[i].render();

		


		GameWindow::getWindow().draw(text[i]);
	}

}