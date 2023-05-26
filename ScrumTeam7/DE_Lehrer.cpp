#include "DE_Lehrer.h"

#include "Randomizer.h"

// private static Variables 
int DE_Lehrer::Cost = 20;
float DE_Lehrer::Health = 200;
sf::Time DE_Lehrer::fireRate = sf::milliseconds(1500);
sf::Time DE_Lehrer::maximumFireRateDiviation = sf::milliseconds(150);
sf::Texture* DE_Lehrer::texture = nullptr;


// public static Methoden
void DE_Lehrer::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/Lehrer/DE/DE-Lehrer.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}

}

void DE_Lehrer::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}


// Constructur & Destructur
DE_Lehrer::DE_Lehrer(sf::Vector2f tilePosition)
	: BaseTower(this->Health, tilePosition, texture)
{}

DE_Lehrer::~DE_Lehrer()
{
}

//public Methoden
void DE_Lehrer::update()
{
	if (health <= Health / 5) {
		body.setFillColor({ 139,0,0 }); //DarkRed
	}
	else if (health <= Health / 2) {
		body.setFillColor({ 255,48,48 }); //firebrick1

	}
	else if (health <= Health * 0.8) {
		body.setFillColor({ 255,99,71 }); //tomato1
	}
}

