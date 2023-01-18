#include "BaseTower.h"

#include "Window.h"

#include <iostream>

std::vector<BaseTower*> BaseTower::Towers;

// Constructur & Destructur
BaseTower::BaseTower(float Health, sf::Vector2f tilePosition, sf::Texture* texture)
	: alive(true), ReadyToAttack(false), health(Health), tilePosition(tilePosition)
{
	this->Body.setPosition(400 + 150 * this->tilePosition.x, 150 + 150 * this->tilePosition.y);
	this->Body.setSize(sf::Vector2f(75.f, 150.f));
	this->Body.setOrigin(sf::Vector2f(this->Body.getSize().x / 2, this->Body.getSize().y / 2));
	this->Body.setTexture(texture, 0);

	Towers.push_back(this);
}

BaseTower::~BaseTower()
{
	for (auto i = Towers.begin(); i != Towers.end(); ++i) {
		if ((*i) == this) {
			Towers.erase(i);
			break;
		}
	}
}

bool BaseTower::isAlive()
{
	return this->alive;
}

bool BaseTower::isReadyToAttack()
{
	return this->ReadyToAttack;
}

void BaseTower::wasAttacked(float damage)
{
	this->health -= damage;
	if (health <= 0) {
		this->alive = false;
	}

}

sf::FloatRect BaseTower::getFloaRect()
{
	sf::FloatRect hitbox = this->Body.getGlobalBounds();
	hitbox.top += 20;
	hitbox.height -= 40;
	return hitbox;
}

void BaseTower::HasAttacked()
{
	this->ReadyToAttack = false;
	this->clock.restart();
	this->remainingAttackTime = sf::milliseconds(0);
}

sf::Vector2f BaseTower::getPosition()
{
	return this->Body.getPosition();
}

sf::Vector2f BaseTower::getTilePosition()
{
	return this->tilePosition;
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
	GameWindow::getWindow().draw(this->Body);
}
