#pragma once
#include "Karte.h"
#include "Geld.h"

#include <vector>

class Shop
{
private:
	
	int anzahlKarten;
	sf::Texture* t;
	Karte** karten; // int cost, int Type, Body, Texture
	Geld* geld;
	int sellection;

	sf::Font font;
	sf::Text* text;

public:
	Shop(Geld* nGeld);
	Shop(Geld* nGeld,int anzahlKarten, Karte** karten);
	~Shop();

	int getSellection();
	void setSellection(int s);
	void setKarten(Karte** karten);

	void buttonEvents(sf::Vector2f tilePos);

	void render();
};

