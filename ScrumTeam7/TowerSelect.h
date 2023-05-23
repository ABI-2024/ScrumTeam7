#pragma once
#include "Karte.h"
#include "Actors.h"
#include "SFML/Graphics.hpp"

class TowerSelect
{
private:
	bool open;
	static int anzahlKarten;
	sf::Texture* t;
	Karte** karten;
	Actors* actors;

	void buttonEvents();
	void render();

	static int anzGewKarten;
	Karte** gewKarten;

	TowerSelect();
	~TowerSelect();

public:
	static Karte** openTowerSelect();
};

