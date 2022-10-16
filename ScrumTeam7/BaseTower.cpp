#include "BaseTower.h"


// protected Methoden


// Constructur & Destructur

void BaseTower::initBaseVariables(float towerHealth, sf::Vector2f tilePosition, sf::Texture *texture)
{
	this->alive = true;
	this->Health = towerHealth;
	this->tilePosition = tilePosition;

	this->Body.setPosition(160 + 160*this->tilePosition.x ,90 + 90*this->tilePosition.y);
	this->Body.setSize(sf::Vector2f(70.f , 140.f));
	this->Body.setOrigin(sf::Vector2f(this->Body.getSize().x/2, this->Body.getSize().y / 2));
	this->Body.setTexture(texture, true);

}

BaseTower::BaseTower()
{
	this->alive = false;
	this->Health = 0;
}

BaseTower::~BaseTower()
{
}
