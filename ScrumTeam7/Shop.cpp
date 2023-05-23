#include "Shop.h"
#include "Window.h"
#include <iostream>

Shop::Shop(Actors& actors) {

	this->actors = &actors;
	sellection = -1;

	this->anzahlKarten = 6;

	font.loadFromFile("resource/fonts/arial.ttf");
	t = new sf::Texture[anzahlKarten];
	t[0].loadFromFile("resource/Textures/Lehrer/Karten/Karte_MA_Front.png");
	t[1].loadFromFile("resource/Textures/Lehrer/Karten/Karte_INF_Front.png");
	t[2].loadFromFile("resource/Textures/Lehrer/Karten/Karte_EN_Front.png");
	t[3].loadFromFile("resource/Textures/Lehrer/Karten/Karte_DE_Front.png");
	t[4].loadFromFile("resource/Textures/Lehrer/Karten/Karte_SP_Front.png");
	t[5].loadFromFile("resource/Textures/Lehrer/Karten/Karte_METAL_Front.png");


	//this->karten = new Karte(100, 1, &t, { 25.f, 90.f });
	karten = new Karte * [anzahlKarten];
	this->karten[0] = new Karte(100, TowerType::Mathelehrer, &t[0], { 60.f, 150.f * 0 + 90 });
	this->karten[1] = new Karte(100, TowerType::INF_Lehrer, &t[1], { 60.f, 150.f * 1 + 90 });
	this->karten[2] = new Karte(100, TowerType::EN_Lehrer, &t[2], { 60.f, 150.f * 2 + 90 });
	this->karten[3] = new Karte(100, TowerType::DE_Lehrer, &t[3], { 60.f, 150.f * 3 + 90 });
	this->karten[4] = new Karte(100, TowerType::TestTower, &t[4], { 60.f, 150.f * 4 + 90 });
	this->karten[5] = new Karte(100, TowerType::METAL_Lehrer, &t[5], { 60.f, 150.f * 5 + 90 });

	this->text = new sf::Text[anzahlKarten];

	for (int i = 0; i < anzahlKarten; i++) {

		text[i].setFont(font);
		text[i].setCharacterSize(20);
		text[i].setPosition(karten[i]->getPosition());
		text[i].setFillColor(sf::Color::Red);
		text[i].setString(std::to_string(karten[i]->getCost()));

	}

}

Shop::Shop(Actors& actors, int anzahlKarten, Karte** karten) {

	font.loadFromFile("resource/fonts/arial.ttf");
	this->actors = &actors,
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



void Shop::buttonEvents(sf::Vector2f tilePos)
{
	if (sellection != -1) {
		if (karten[sellection]->getCost() <= actors->getGeld()->getKontostand()) {
			if (actors->initializeTower(karten[sellection]->getType(), tilePos)) {
				actors->getGeld()->subKontostand(karten[sellection]->getCost());
			}
		}
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

		if (actors->getGeld()->getKontostand() >= karten[i]->getCost()) {
			text[i].setFillColor(sf::Color::Green);
		}
		else text[i].setFillColor(sf::Color::Red);
		GameWindow::getWindow().draw(text[i]);
	}
}