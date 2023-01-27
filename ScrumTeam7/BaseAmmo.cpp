#include "BaseAmmo.h"

#include "Window.h"

// public static Variables
std::vector<BaseAmmo*> BaseAmmo::ammos;


// Constructur & Destructur
BaseAmmo::BaseAmmo(sf::Vector2f TowerPosition, sf::Texture* texture)
	: Entity() ,hit(false)
{
	this->body.setPosition(TowerPosition);
	this->body.setSize(sf::Vector2f(70.f, 70.f));
	this->body.setOrigin(this->body.getSize().x / 2, this->body.getSize().y / 2);
	this->body.setTexture(texture, true);

	ammos.push_back(this);
}

BaseAmmo::~BaseAmmo()
{
	for (auto i = ammos.begin(); i != ammos.end(); ++i) {
		if ((*i) == this) {
			ammos.erase(i);
			break;
		}
	}
}


// public Methoden
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
	GameWindow::getWindow().draw(this->body);
}

