#include "BaseAmmo.h"

#include "Window.h"

// protected Methoden
void BaseAmmo::initBaseVariables(int ammoType,float damage, sf::Vector2f TowerPosition, sf::Texture* texture)
{
	this->AmmoType = ammoType;
	this->hit = false;
	this->damage = damage;

	this->Body.setPosition(TowerPosition);
	this->Body.setSize(sf::Vector2f(70.f,70.f));
	this->Body.setOrigin(this->Body.getSize().x/2, this->Body.getSize().y/2);
	this->Body.setTexture(texture, true);
}


// Constructur & Destructur
BaseAmmo::BaseAmmo()
{
	this->AmmoType = 0;
	this->hit = false;
	this->damage = 0;
}

BaseAmmo::~BaseAmmo()
{
}

bool BaseAmmo::isHit()
{
	return this->hit;
}

int BaseAmmo::getType()
{
	return this->AmmoType;
}

float BaseAmmo::getDamage()
{
	return this->damage;
}

void BaseAmmo::hasHit()
{
	this->hit = true;
}

void BaseAmmo::render()
{
	GameWindow::getWindow().draw(this->Body);
}

