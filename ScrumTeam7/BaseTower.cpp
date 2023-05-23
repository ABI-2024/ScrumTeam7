#include "BaseTower.h"

#include "Window.h"

// public static Variables 
std::vector<BaseTower*> BaseTower::towers;


// Constructur & Destructur
BaseTower::BaseTower(float Health, sf::Vector2f tilePosition, sf::Texture* texture)
	: alive(true), readyToAttack(false), health(Health), tilePosition(tilePosition)
{
	this->body.setPosition(400 + 150 * this->tilePosition.x, 150 + 150 * this->tilePosition.y);
	this->body.setSize(sf::Vector2f(75.f, 150.f));
	this->body.setOrigin(sf::Vector2f(this->body.getSize().x / 2, this->body.getSize().y / 2));
	this->body.setTexture(texture, 0);

	this->shadow.setPosition(this->body.getPosition().x + this->body.getSize().x / 8.f, this->body.getPosition().y + this->body.getSize().y / 2);
	this->shadow.setSize(sf::Vector2f(this->body.getSize().x, 37.5f));
	this->shadow.setOrigin(sf::Vector2f(this->shadow.getSize().x / 2, this->shadow.getSize().y / 2));
	this->shadow.setTexture(this->shadowTexture,0);

	towers.push_back(this);
}

BaseTower::~BaseTower()
{
	for (auto i = towers.begin(); i != towers.end(); ++i) {
		if ((*i) == this) {
			towers.erase(i);
			break;
		}
	}
}


// public get-Methoden
bool BaseTower::isAlive()
{
	return this->alive;
}

bool BaseTower::isReadyToAttack()
{
	return this->readyToAttack;
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
void BaseTower::HasAttacked()
{
	this->readyToAttack = false;
	this->clock.restart();
	this->remainingAttackTime = sf::milliseconds(0);
}

void BaseTower::wasAttacked(float damage)
{
	this->health -= damage;
	if (health <= 0) {
		this->alive = false;
	}

}

void BaseTower::paused()
{
	this->remainingAttackTime = this->clock.restart() + this->remainingAttackTime;
}

void BaseTower::Continue()
{
	this->clock.restart();
}

void BaseTower::render()
{
	Window.draw(this->body);
}

void BaseTower::sortLehrer()
{
	for (BaseTower::towers)
}
