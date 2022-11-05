#include "Actors.h"

#include "Window.h"


// private Methoden
void Actors::updateTowers()
{
    Towers.clear();

    for (auto i = testTower.begin(); i != testTower.end(); i++) {
        if (!i->isAlive()) {
            i = testTower.erase(i);
            if (i == testTower.end()) {
                break;
            }
        }

        i->update();

        if (i->isReadyToAttack()) {
            switch (i->getType()) {
            case 1:
                i->HasAttacked();
                testAmmo.push_back(i->getPosition());
                break;
            default:
                break;
            }
        }

        this->Towers.push_back( &(*i) );
    }
}

void Actors::updateAmmos()
{
    Ammos.clear();

    for (auto i = testAmmo.begin(); i != testAmmo.end(); i++) {

        if (i->isHit()) {
            i = testAmmo.erase(i);
            if (i == testAmmo.end()) {
                break;
            }
        }
        i->update();

        this->Ammos.push_back(&(*i));
    }

}

void Actors::updateEnemies()
{
    Enemies.clear();

    for (auto i = testEnemy.begin(); i != testEnemy.end(); i++) {

        if (!i->isAlive()) {
            i = testEnemy.erase(i);
            if (i == testEnemy.end()) {
                break;
            }
        }

        i->update();

        this->Enemies.push_back(&(*i));
    }

}



void Actors::CollisionEnemyWithTower()
{
    for (auto i = this->Towers.begin(); i != this->Towers.end(); i++) {
        for (auto j = this->Enemies.begin(); j != this->Enemies.end(); j++) {

            sf::FloatRect tmp = (*i)->getFloaRect();

            if ((*j)->CollisionWithTower(tmp)) {
                (*i)->wasAttacked((*j)->getDamage());
                (*j)->hasAttacked();
            }
        }
    }
}

void Actors::CollisionAmmoWithEnemy()
{
    for (auto i = this->Enemies.begin(); i != this->Enemies.end(); i++) {
        for (auto j = this->Ammos.begin(); j != this->Ammos.end(); j++) {

            sf::FloatRect tmp = (*i)->getFloaRect();

            if ((*j)->CollisionWithEnemy(tmp)) {
                (*i)->wasAttacked((*j)->getDamage());
                (*j)->hasHit();
            }
        }
    }
}



void Actors::renderTowers()
{
    for (auto i = Towers.begin(); i != Towers.end(); i++) {
        (*i)->render();
    }
}

void Actors::renderAmmos()
{
    for (auto i = Ammos.begin(); i != Ammos.end(); i++) {
        (*i)->render();
    }
}

void Actors::renderEnemies()
{
    for (auto i = Enemies.begin(); i != Enemies.end(); i++) {
        (*i)->render();
    }
}


// Constructur & Destructur
Actors::Actors()
{
}

Actors::~Actors()
{
    // Löschung aller Gespeicherten Klassentypen
    testTower.clear();

    testAmmo.clear();

    testEnemy.clear();

    // löschung aller gespicherten BasisTypen*
    Towers.clear();
    Ammos.clear();
    Enemies.clear();
}


//public Methoden
void Actors::updateActors()
{
    this->updateTowers();
    this->updateAmmos();
    this->updateEnemies();
}

void Actors::Collisions() 
{
    this->CollisionEnemyWithTower(); {

    }
}

void Actors::renderActors()
{
    this->renderTowers();
    this->renderAmmos();
    this->renderEnemies();
}



void Actors::initializeTower(int TowerType, sf::Vector2f TilePosition)
{
    for (auto i = Towers.begin(); i != Towers.end(); i++) {
        if ((*i)->getTilePosition() == TilePosition) {
            return;
        }
    }

    switch (TowerType)
    {
    case TypeTestTower:
        testTower.push_back(TilePosition);
        break;

    default:
        break;
    }
}

void Actors::initializeAmmo(int AmmoType, sf::Vector2f TilePosition)
{
    switch (AmmoType)
    {
    case TypeTestAmmo:
        testAmmo.push_back(TilePosition);
        break;

    default:
        break;
    }
}

void Actors::initializeEnemy(int EnemyType, sf::Vector2f TowerPosition)
{
    switch (EnemyType)
    {
    case TypeTestEnemy:
        testEnemy.push_back(TowerPosition.y);
        break;

    default:
        break;
    }
}
