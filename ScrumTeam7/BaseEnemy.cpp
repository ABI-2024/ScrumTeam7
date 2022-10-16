#include "BaseEnemy.h"

void BaseEnemy::initBaseVariables(float EnemyHealth, float linePosition, sf::Texture* texture)
{
	this->alive = true;
	this->Health = EnemyHealth;
	this->linePosition = linePosition;

	this->Body.setPosition(GameWindow::getWindow().getSize().x , 90.f + 90.f * this->linePosition);
	this->Body.setSize(sf::Vector2f(70.f, 140.f));
	this->Body.setOrigin(sf::Vector2f(this->Body.getSize().x / 2, this->Body.getSize().y / 2));
	this->Body.setTexture(texture, true);
}

BaseEnemy::BaseEnemy()
{
	this->alive = false;
	this->Health = 0;
	this->linePosition = 0;
}

BaseEnemy::~BaseEnemy()
{
}
