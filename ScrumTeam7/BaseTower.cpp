#include "BaseTower.h"

#include "Window.h"

// Constructur & Destructur
BaseTower::BaseTower(float Health, sf::Vector2f tilePosition, sf::Texture* texture)
	:health(Health), tilePosition(tilePosition)
{
	this->body.setPosition(400 + 150 * this->tilePosition.x, 150 + 150 * this->tilePosition.y);
	this->body.setSize(sf::Vector2f(75.f, 150.f));
	this->body.setOrigin(sf::Vector2f(this->body.getSize().x / 2, this->body.getSize().y / 2));
	this->body.setTexture(texture, 0);

	this->shadow.setPosition(this->body.getPosition().x + this->body.getSize().x / 8.f, this->body.getPosition().y + this->body.getSize().y / 2);
	this->shadow.setSize(sf::Vector2f(this->body.getSize().x, 37.5f));
	this->shadow.setOrigin(sf::Vector2f(this->shadow.getSize().x / 2, this->shadow.getSize().y / 2));
	this->shadow.setTexture(this->shadowTexture,0);
}

BaseTower::~BaseTower()
{
}


// public get-Methoden

const CollisionType& BaseTower::getCollisionType()
{
	return CollisionType::ally;
}

sf::FloatRect BaseTower::getFloaRect()
{
	return this->body.getGlobalBounds();	
}

sf::Vector2f BaseTower::getPosition()
{
	return this->body.getPosition();
}

sf::Vector2f BaseTower::getTilePosition()
{
	return this->tilePosition;
}


// public Methoden

void BaseTower::pauseEntitiy()
{
	this->remainingAttackTime = this->clock.restart() + this->remainingAttackTime;
}

void BaseTower::continueEntitiy()
{
	this->clock.restart();
}
