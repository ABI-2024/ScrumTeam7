#include "BaseAmmo.h"

#include "Window.h"

// public static Variables
std::vector<BaseAmmo*> BaseAmmo::ammos;


// Constructur & Destructur
BaseAmmo::BaseAmmo(const sf::Vector2f& TowerPosition, sf::Texture* texture)
	: Entity() ,hit(false), destroy(false), status_Effect(Status_Type::non, 0.f, sf::milliseconds(0))
{
	this->body.setPosition(TowerPosition);
	this->body.setSize(sf::Vector2f(42.1875f, 42.1875f));
	this->body.setOrigin(this->body.getSize().x / 2, this->body.getSize().y / 2);
	this->body.setTexture(texture, 0);

	this->shadow.setPosition(this->body.getPosition().x, this->body.getPosition().y + 75.f);
	this->shadow.setSize(sf::Vector2f(75.f / 2, 37.5f / 2));
	this->shadow.setOrigin(sf::Vector2f(this->shadow.getSize().x / 2, this->shadow.getSize().y / 2));
	this->shadow.setTexture(this->shadowTexture, 0);

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


bool BaseAmmo::isHit()
{
	return hit;
}

// public Methoden
bool BaseAmmo::isDestroy()
{
	return this->destroy;
}

bool BaseAmmo::CollisionWithEnemy(sf::FloatRect& Enemy)
{
	hit = sf::FloatRect(this->body.getGlobalBounds()).intersects(Enemy);
	destroy = hit;
	return hit;
}

void BaseAmmo::render()
{
	Window.draw(this->body);
}

void BaseAmmo::renderShadow()
{
	this->shadow.setPosition(this->body.getPosition().x, this->body.getPosition().y + 75.f);
	Window.draw(shadow);
}

