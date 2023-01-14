#pragma once
#include "Actors.h"
#include "Karte.h"
#include <vector>

class Shop
{
private:
	
	int anzahlKarten;
	Karte** karten; // int cost, int Type, Body, Texture
	int sellection;

	sf::Font font;
	sf::Text* text;

public:
	Shop(int anzahlKarten, Karte** karten);
	~Shop();

	int getSellection();

	void setSellection(int s);

	void render();
};

