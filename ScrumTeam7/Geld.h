#pragma once
#include "SFML/Graphics.hpp"

class Geld
{
private:
	static int Startgeld;
	int Kontostand;
	sf::Font font;
	sf::Text text;

	sf::Texture texture;
	sf::RectangleShape body;
public:
	Geld();
	~Geld();

	
	int getKontostand();
	void addKontostand(int);
	void subKontostand(int);
	void clearKontostand();
	void render();
};

