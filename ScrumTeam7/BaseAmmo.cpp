#include "BaseAmmo.h"


// protected Methoden
void BaseAmmo::initBaseVariables(sf::Vector2f TowerPosition, sf::Texture* texture)
{
	this->hit = false;

	this->Body.setPosition(TowerPosition);
	this->Body.setSize(sf::Vector2f(70.f,70.f));
	this->Body.setOrigin(this->Body.getSize().x/2, this->Body.getSize().y/2);
	this->Body.setTexture(texture, true);
}


// Constructur & Destructur
BaseAmmo::BaseAmmo()
{
	this->hit = false;
}


BaseAmmo::~BaseAmmo()
{
}

bool BaseAmmo::isHit()
{
	return this->hit;
}

