#include "BaseAmmo.h"

#include "Window.h"

// Constructur & Destructur
BaseAmmo::BaseAmmo(const sf::Vector2f& TowerPosition, sf::Texture* texture)
	: Entity(sf::Vector2f(42.1875f, 42.1875f), TowerPosition)
{

	this->body.setTexture(texture, 0);

	this->shadow.setPosition(this->body.getPosition().x, this->body.getPosition().y + 75.f);
	this->shadow.setSize(sf::Vector2f(75.f / 2, 37.5f / 2));
	this->shadow.setOrigin(sf::Vector2f(this->shadow.getSize().x / 2, this->shadow.getSize().y / 2));
	this->shadow.setTexture(this->shadowTexture, 0);
}

BaseAmmo::~BaseAmmo()
{
}

const CollisionType& BaseAmmo::getCollisionType()
{
	return CollisionType::allyAmmo;
}

// public Methoden
void BaseAmmo::renderShadow()
{
	this->shadow.setPosition(this->body.getPosition().x, this->body.getPosition().y + 75.f);
	Window.draw(shadow);
}

