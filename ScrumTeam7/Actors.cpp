#include "Actors.h"

#include "Window.h"

#include <iostream>

template<class BaseT> 
void deleteEntities(std::vector<BaseT*> T) {

    for (auto i = T.begin(); i != T.end(); i++) {
        delete (*i);
        (*i) = nullptr;
    }
}



// private Methoden
void Actors::updateTowers()
{

    for (auto i = testTower.begin(); i != testTower.end(); i++) {
        
        if (!(*i)->isAlive()) {
            delete (*i);
            i = testTower.erase(i);
            if (i == testTower.end()) {
                break;
            }
        }

        (*i)->update();

        if ((*i)->isReadyToAttack() && onLine[(int)(*i)->getTilePosition().y]) {
                (*i)->HasAttacked();
                testAmmo.push_back(new TestAmmo( (*i)->getPosition() ));
        }
    }
}

void Actors::updateAmmos()
{
    for (auto i = testAmmo.begin(); i != testAmmo.end(); i++) {

        if ((*i)->isHit()) {
            delete (*i);
            i = testAmmo.erase(i);
            if (i == testAmmo.end()) {
                break;
            }
        }
        (*i)->update();
    }

}

void Actors::updateEnemies()
{
    for (int i = 0; i < 5; i++) {
        onLine[i] = false;
    }

    for (auto i = testEnemy.begin(); i != testEnemy.end(); i++) {

        onLine[(int)(*i)->getTilePosition().y] = true;

        if (!(*i)->isAlive()) {
            testGeld.addKontostand((*i)->getRevenue());

            delete (*i);
            i = testEnemy.erase(i);
            if (i == testEnemy.end()) {
                break;
            
            }
        }

        (*i)->update();
    }

}



void Actors::CollisionEnemyWithTower()
{
    for (BaseTower* i : BaseTower::towers) {
        for (BaseEnemy* j : BaseEnemy::enemies) {

            sf::FloatRect tmp = i->getFloaRect();

            if (j->CollisionWithTower(tmp) && j->isReadyToAttack()) {
                i->wasAttacked(j->getDamage());
                j->hasAttacked();
            }
        }
    }
}

void Actors::CollisionAmmoWithEnemy()
{
    for (BaseEnemy* i : BaseEnemy::enemies) {
        for (BaseAmmo* j : BaseAmmo::ammos) {

            sf::FloatRect tmp = i->getFloaRect();

            if (j->CollisionWithEnemy(tmp) && !j->isHit()) {
                i->wasAttacked(j->getDamage());
                j->hasHit();
            }
        }
    }
}



void Actors::renderShadows()
{
    for (Entity* i : Entity::entities) {
        i->renderShadow();
    }
}

void Actors::renderTowers()
{
    for (BaseTower* i : BaseTower::towers) {
        i->render();
    }
}

void Actors::renderAmmos()
{
    for (BaseAmmo* i : BaseAmmo::ammos) {
        i->render();
    }
}

void Actors::renderEnemies()
{
    for (BaseEnemy* i : BaseEnemy::enemies) {
        i->render();
    }
}

std::vector<BaseEnemy*>* Actors::getEnemy() {
    return &BaseEnemy::enemies;
}


// Constructur & Destructur
Actors::Actors()
{
    for (int i = 0; i < 5; i++) {
        onLine[i] = false;
    }
}

Actors::~Actors()
{
    // L�schung aller Gespeicherten Klassentypen
    deleteEntities(testTower);
    testTower.clear();

    deleteEntities(testAmmo);
    testAmmo.clear();

    deleteEntities(testEnemy);
    testEnemy.clear();

    //// l�schung aller gespicherten BasisTypen*
    //towers.clear();
    //Ammos.clear();
    //Enemies.clear();
}


void Actors::pauseActors()
{
    for (BaseTower* i : BaseTower::towers) {
        i->paused();
    }
    for (BaseEnemy* i : BaseEnemy::enemies) {
        i->paused();
    }
}

void Actors::ContinueActors()
{
    for (BaseTower* i : BaseTower::towers) {
        i->Continue();
    }
    for (BaseEnemy* i : BaseEnemy::enemies) {
        i->Continue();
    }
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
    this->CollisionEnemyWithTower();
    this->CollisionAmmoWithEnemy();
}

void Actors::renderActors()
{
    this->renderShadows();

    this->renderTowers();
    this->renderAmmos();
    this->renderEnemies();

    testGeld.render();
}



bool Actors::initializeTower(TowerType TowerType, sf::Vector2f TilePosition)
{
    if (TilePosition.x < 0 || TilePosition.x >7  ||  TilePosition.y < 0 || TilePosition.y > 4) {
        return false;
    }

    for (BaseTower* i : BaseTower::towers) {
        if ( i->getTilePosition() == TilePosition) {
            return false;
        }
    }

    switch (TowerType)
    {
    case TowerType::TestTower:
        testTower.push_back(new TestTower(TilePosition));
        break;

    default:
        return false;
        break;
    }
    return true;
}

bool Actors::initializeEnemy(EnemyType EnemyType, sf::Vector2f TilePosition )
{
    if (TilePosition.x < 0 || TilePosition.x >7 || TilePosition.y < 0 || TilePosition.y > 4) {
        return false;
    }

    switch (EnemyType)
    {
    case EnemyType::TestEnemy:
        testEnemy.push_back(new TestEnemy(TilePosition));
        break;

    default:
        return false;
        break;
    }
    return true;
}

void Actors::initializeAmmo(AmmoType AmmoType, sf::Vector2f TowerPosition)
{
    switch (AmmoType)
    {
    case AmmoType::TestAmmo:
        testAmmo.push_back(new TestAmmo(TowerPosition));
        break;

    default:
        break;
    }
}

Geld& Actors::getGeld() {
    return testGeld;
}