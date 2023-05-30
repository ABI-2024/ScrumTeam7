#pragma once
#include "Karte.h"
#include "SFML/Graphics.hpp"

class TowerSelect
{
private:
	bool open;
	static int anzahlKarten;
	sf::Texture* t;
	sf::Texture* tb;
	sf::RectangleShape Rückseite;
	Karte** karten;

	void buttonEvents();
	void render();

	static int anzGewKarten;
	Karte** gewKarten;

	TowerSelect();
	~TowerSelect();

public:
	static Karte** openTowerSelect();
};

