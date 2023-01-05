#include "BaseEnemy.h"
#include "Window.h"

void BaseEnemy::initBaseVariables( float Health, float linePosition, sf::Texture* texture)
{
	this->alive = true;
	this->Movable = true;
	this->health = Health;
	this->linePosition = linePosition;

	this->Body.setPosition(GameWindow::getMainView().getSize().x , 135.f + 142.f * this->linePosition);
	this->Body.setSize(sf::Vector2f(70.f, 140.f));
	this->Body.setOrigin(sf::Vector2f(this->Body.getSize().x / 2, this->Body.getSize().y / 2));
	this->Body.setTexture(texture, 0);
}

BaseEnemy::BaseEnemy()
{
	this->alive = false;
	this->ReadyToAttack = false;
	this->Movable = false;
	this->health = 0;
	this->linePosition = 0;
}

BaseEnemy::~BaseEnemy()
{
}

bool BaseEnemy::isAlive()
{
	return this->alive;
}

bool BaseEnemy::isReadyToAttack()
{
	return this->ReadyToAttack;
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
