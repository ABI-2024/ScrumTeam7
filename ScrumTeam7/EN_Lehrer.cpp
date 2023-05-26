#include "En_Lehrer.h"

#include "Randomizer.h"

// public static Variables 
AllyType EN_Lehrer::type;

// private static Variables 
int EN_Lehrer::Cost = 20;
float EN_Lehrer::Health = 200;
sf::Time EN_Lehrer::fireRate = sf::milliseconds(2000);
sf::Time EN_Lehrer::maximumFireRateDiviation = sf::milliseconds(150);
sf::Texture* EN_Lehrer::texture = nullptr;


// public static Methoden
void EN_Lehrer::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/Lehrer/EN/EN-Lehrer.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}

}

void EN_Lehrer::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}


// Constructur & Destructur
EN_Lehrer::EN_Lehrer(sf::Vector2f tilePosition)
	: BaseTower(this->Health, tilePosition, texture)
{}

EN_Lehrer::~EN_Lehrer()
{
}

//public Methoden
void EN_Lehrer::update()
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

