#pragma once
#include "Actors.h"
#include "Karte.h"
#include <vector>

class Shop
{
private:
	
	int anzahlKarten;
	sf::Texture* t;
	Karte** karten; // int cost, int Type, Body, Texture
	int sellection;

	sf::Font font;
	sf::Text* text;

public:
	Shop();
	Shop(int anzahlKarten, Karte** karten);
	~Shop();

	int getSellection();
	void setSellection(int s);

	void buttonEvents(Actors& actors, sf::Vector2f tilePos);

	void render();
};

