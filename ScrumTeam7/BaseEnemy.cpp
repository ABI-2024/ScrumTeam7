#include "BaseEnemy.h"

#include "Window.h"

// public static Variables
std::vector<BaseEnemy*> BaseEnemy::enemies;


// Constructur & Destructur
BaseEnemy::BaseEnemy(float Health, sf::Vector2f tilePosition, sf::Texture* texture)
	: Entity(), alive(true), readyToAttack(false), movable(true), health(Health), tilePosition(tilePosition)
{
	this->body.setPosition(GameWindow::getMainView().getSize().x, 150.f + 150.f * this->tilePosition.y);
	this->body.setSize(sf::Vector2f(75.f, 150.f));
	this->body.setOrigin(sf::Vector2f(this->body.getSize().x / 2, this->body.getSize().y / 2));
	this->body.setTexture(texture, 0);

	this->shadow.setPosition(this->body.getPosition().x - this->body.getSize().x / 8.f, this->body.getPosition().y + this->body.getSize().y / 2);
	this->shadow.setSize(sf::Vector2f(this->body.getSize().x, 37.5f));
	this->shadow.setOrigin(sf::Vector2f(this->shadow.getSize().x / 2, this->shadow.getSize().y / 2));
	this->shadow.setTexture(this->shadowTexture, 0);

	enemies.push_back(this);
}

BaseEnemy::~BaseEnemy()
{
	for (auto i = enemies.begin(); i != enemies.end(); ++i) {
		if ((*i) == this) {
			enemies.erase(i);
			break;
		}
	}
}


// public get-Methoden
bool BaseEnemy::isAlive()
{
	return this->alive;
}

bool BaseEnemy::isReadyToAttack()
{
	return this->readyToAttack;
}

const sf::Vector2f& BaseEnemy::getTilePosition()
{
	return tilePosition;
}

sf::FloatRect BaseEnemy::getFloaRect()
{
	return sf::FloatRect(this->body.getGlobalBounds());
}


sf::Vector2f BaseEnemy::getPosition()
{
	return body.getPosition();
}

// public Methoden
void BaseEnemy::hasAttacked()
{
	this->readyToAttack = false;
	this->clock.restart();
}

void BaseEnemy::wasAttacked(float damage)
{
	this->health -= damage;
	if (health <= 0) {
		this->alive = false;
	}
}

void BaseEnemy::paused()
{
	this->remainingAttackTime = this->clock.restart() + this->remainingAttackTime ;
}

void BaseEnemy::Continue()
{
	this->clock.restart();
}

void BaseEnemy::render()
{
	this->shadow.setPosition(this->body.getPosition().x - this->body.getSize().x / 8.f, this->body.getPosition().y + this->body.getSize().y / 2);

	Window.draw(this->body);
}
