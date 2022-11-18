#pragma once
#include "SFML/Graphics.hpp"

class Geld
{
private:
	static double Startgeld;
	int Kontostand;
	sf::Font font;
	sf::Text text;
public:
	Geld();
	~Geld();

	
	int getKontostand();
	void addKontostand(int);
	void clearKontostand();
	void render();
};

