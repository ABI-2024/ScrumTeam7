#include "BaseTower.h"

#include "Window.h"

#include <iostream>

// protected Methoden
void BaseTower::initBaseVariables(float Health, sf::Vector2f tilePosition, sf::Texture *texture)
{
	this->alive = true;
	this->health = Health;
	this->tilePosition = tilePosition;

	this->Body.setPosition(160 + 160*this->tilePosition.x ,135 + 135*this->tilePosition.y);
	this->Body.setSize(sf::Vector2f(70.f , 140.f));
	this->Body.setOrigin(sf::Vector2f(this->Body.getSize().x/2, this->Body.getSize().y / 2));
	this->Body.setTexture(texture, 0);

}

// Constructur & Destructur
BaseTower::BaseTower()
{
	this->ReadyToAttack = false;
	this->alive = false;
	this->health = 0;
}

BaseTower::~BaseTower()
{
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
}

sf::Vector2f BaseTower::getPosition()
{
	return this->Body.getPosition();
}

sf::Vector2f BaseTower::getTilePosition()
{
	return this->tilePosition;
}

// public Methoden

void BaseTower::render()
{
	GameWindow::getWindow().draw(this->Body);
}
