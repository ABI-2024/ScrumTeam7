#include "BaseEnemy.h"

#include "Window.h"

void BaseEnemy::initBaseVariables(int EnemyType, float Damage,float Health, float linePosition, sf::Texture* texture)
{
	this->enemyType = EnemyType;
	this->alive = true;
	this->Movable = true;
	this->health = Health;
	this->damage = Damage;
	this->linePosition = linePosition;

	this->Body.setPosition(GameWindow::getWindow().getSize().x , 135.f + 142.f * this->linePosition);
	this->Body.setSize(sf::Vector2f(70.f, 140.f));
	this->Body.setOrigin(sf::Vector2f(this->Body.getSize().x / 2, this->Body.getSize().y / 2));
	this->Body.setTexture(texture, 0);
}

BaseEnemy::BaseEnemy()
{
	this->enemyType = 0;
	this->alive = false;
	this->ReadyToAttack = false;
	this->Movable = false;
	this->health = 0;
	this->damage = 0;
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

int BaseEnemy::getType()
{
	return this->enemyType;
}

float BaseEnemy::getDamage()
{
	return this->damage;
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

void BaseEnemy::render()
{
	GameWindow::getWindow().draw(this->Body);
}
