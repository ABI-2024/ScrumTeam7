#include "BaseEnemy.h"

#include "Window.h"

std::vector<BaseEnemy*> BaseEnemy::Enemies;

BaseEnemy::BaseEnemy(float Health,	sf::Vector2f tilePosition, sf::Texture* texture)
	: alive(true), ReadyToAttack(false) , Movable(true), health(Health), tilePosition(tilePosition)
{
	this->Body.setPosition(GameWindow::getMainView().getSize().x, 150.f + 150.f * this->tilePosition.y);
	this->Body.setSize(sf::Vector2f(75.f, 150.f));
	this->Body.setOrigin(sf::Vector2f(this->Body.getSize().x / 2, this->Body.getSize().y / 2));
	this->Body.setTexture(texture, 0);

	Enemies.push_back(this);
}

BaseEnemy::~BaseEnemy()
{
	for (auto i = Enemies.begin(); i != Enemies.end(); ++i) {
		if ((*i) == this) {
			Enemies.erase(i);
			break;
		}
	}
}

bool BaseEnemy::isAlive()
{
	return this->alive;
}

bool BaseEnemy::isReadyToAttack()
{
	return this->ReadyToAttack;
}

const sf::Vector2f& BaseEnemy::getTilePosition()
{
	return tilePosition;
}

void BaseEnemy::hasAttacked()
{
	this->ReadyToAttack = false;
	this->clock.restart();
}

void BaseEnemy::wasAttacked(float damage)
{
	this->health -= damage;
	if (health <= 0) {
		this->alive = false;
	}
}

sf::FloatRect BaseEnemy::getFloaRect()
{
	return sf::FloatRect(this->Body.getGlobalBounds());
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
	GameWindow::getWindow().draw(this->Body);
}
