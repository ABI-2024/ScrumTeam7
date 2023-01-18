#include "BaseAmmo.h"

#include "Window.h"

std::vector<BaseAmmo*> BaseAmmo::Ammos;

// Constructur & Destructur
BaseAmmo::BaseAmmo(sf::Vector2f TowerPosition, sf::Texture* texture)
	: hit(false)
{
	this->Body.setPosition(TowerPosition);
	this->Body.setSize(sf::Vector2f(70.f, 70.f));
	this->Body.setOrigin(this->Body.getSize().x / 2, this->Body.getSize().y / 2);
	this->Body.setTexture(texture, true);

	Ammos.push_back(this);
}

BaseAmmo::~BaseAmmo() 
{
	for (auto i = Ammos.begin(); i != Ammos.end(); ++i) {
		if ((*i) == this) {
			Ammos.erase(i);
			break;
		}
	}
}

bool BaseAmmo::isHit()
{
	return this->hit;
}

void BaseAmmo::hasHit()
{
	this->hit = true;
}

void BaseAmmo::render()
{
	GameWindow::getWindow().draw(this->Body);
}

