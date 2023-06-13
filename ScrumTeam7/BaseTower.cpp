#include "BaseTower.h"

#include "Window.h"

bool BaseTower::enemyOnLines[5] = { false,false,false,false,false };

void BaseTower::areEnemiesOnLine(std::vector<Entity*>* enemies)
{
	for (int i = 0; i < 5; i++) {
		enemyOnLines[i] = false;
	}

	for (int i = 0; i < enemies->size(); i++) {
		switch ( (int)(*enemies)[i]->getTilePosition().y)
		{
		case 0:
			enemyOnLines[0] = true;
			break;
		case 1:
			enemyOnLines[1] = true;
			break;
		case 2:
			enemyOnLines[2] = true;
			break;
		case 3:
			enemyOnLines[3] = true;
			break;
		case 4:
			enemyOnLines[4] = true;
			break;
		default:
			break;
		}
	}

}

// Constructur & Destructur
BaseTower::BaseTower(float Health, sf::Vector2f tilePosition, sf::Texture* texture)
	: Entity({ 75.f, 150.f }, { 400 + 150 * tilePosition.x, 150 + 150 * tilePosition.y }), health(Health), tilePosition(tilePosition)
{
	this->body.setTexture(texture, 0);
	this->statusprocs = new std::vector<StatusProc*>;
	this->shadow.setPosition(this->body.getPosition().x + this->body.getSize().x / 8.f, this->body.getPosition().y + this->body.getSize().y / 2);
	this->shadow.setSize(sf::Vector2f(this->body.getSize().x, 37.5f));
	this->shadow.setOrigin(sf::Vector2f(this->shadow.getSize().x / 2, this->shadow.getSize().y / 2));
	this->shadow.setTexture(this->shadowTexture,0);
}

BaseTower::~BaseTower()
{
}


// public get-Methoden

const CollisionType& BaseTower::getCollisionType()
{
	return CollisionType::ally;
}

sf::FloatRect BaseTower::getFloaRect()
{
	return this->body.getGlobalBounds();
}

sf::Vector2f BaseTower::getPosition()
{
	return this->body.getPosition();
}

sf::Vector2f BaseTower::getTilePosition()
{
	return this->tilePosition;
}


// public Methoden


void BaseTower::pauseEntitiy()
{
	this->remainingAttackTime = this->clock.restart() + this->remainingAttackTime;
}

void BaseTower::continueEntitiy()
{
	this->clock.restart();
}
