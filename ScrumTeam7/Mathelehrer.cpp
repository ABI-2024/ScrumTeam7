#include "Mathelehrer.h"
#include "Randomizer.h"
#include "Window.h"

#include <math.h>

// public static Variables 
TowerType Mathelehrer::towerType = TowerType::Mathelehrer;


// private static Variables 
int Mathelehrer::Cost = 20;
float Mathelehrer::Health = 200;
sf::Time Mathelehrer::fireRate = sf::milliseconds(1500);
sf::Time Mathelehrer::maximumFireRateDiviation = sf::milliseconds(150);
sf::Texture* Mathelehrer::texture = nullptr;

int Mathelehrer::accuracy = 10;		// Je kleiner die Zahl, desto höher die Genauigkeit
int Mathelehrer::countVertex = 0;
sf::Vertex* Mathelehrer::sinusLine = nullptr;

// public static Methoden
void Mathelehrer::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/Lehrer/MA/MA-Lehrer.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}

	//if (sinusLine == nullptr) {
	//	countVertex = GameWindow::getMainView().getSize().x / accuracy;
	//	countVertex++;
	//	sinusLine = new sf::Vertex[countVertex];
	//	for (int i = 1; i < countVertex; i++) {
	//		sinusLine[i] = sf::Vector2f(float(accuracy * i), (float)sin((double)accuracy * (double)i * (0.01745)) * 140.f);
	//		// * sqrt(1./i)*10
	//	}
	//}

}

void Mathelehrer::unLoadTexture()
{
	delete texture;
	texture = nullptr;

	delete[] sinusLine;
	sinusLine = nullptr;
}


// Constructur & Destructur
Mathelehrer::Mathelehrer(sf::Vector2f tilePosition)
	: BaseTower(this->Health, tilePosition, texture)
{}

Mathelehrer::~Mathelehrer()
{
}

TowerType Mathelehrer::getTowerType()
{
	return this->towerType;
}


void Mathelehrer::HasAttacked()
{
	this->readyToAttack = false;
	this->clock.restart();
	this->remainingAttackTime = sf::milliseconds(0);
	this->fireRateDiviation = sf::milliseconds(Randomizer::randomize((int)this->maximumFireRateDiviation.asMilliseconds() * 2, -(int)this->maximumFireRateDiviation.asMilliseconds()));
}

//public Methoden
void Mathelehrer::update()
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

	if (this->fireRate + this->fireRateDiviation <= this->clock.getElapsedTime() + this->remainingAttackTime) {
		this->readyToAttack = true;
	}
}


