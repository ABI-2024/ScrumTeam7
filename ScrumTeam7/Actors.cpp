//#include "Actors.h"
//
//#include "Window.h"
//
//#include <iostream>
//
//
//template<class BaseT>
//void  Actors::updateTower(std::vector<BaseT*>* T) {
//
//    for (auto i = T->begin(); i != T->end(); i++) {
//
//        if (!(*i)->isAlive()) {
//            delete (*i);
//            i = T->erase(i);
//            if (i == T->end()) {
//                break;
//            }
//        }
//
//        (*i)->update();
//
//        if ((*i)->isReadyToAttack() && onLine[(int)(*i)->getTilePosition().y]) {
//            (*i)->HasAttacked();
//            initializeAmmo((*i)->getAmmoType(), (*i)->getPosition());
//        }
//    }
//
//}
//
//template<class BaseT>
//void  Actors::updateAmmo(std::vector<BaseT*>* T) {
//
//    for (auto i = T->begin(); i != T->end(); i++) {
//
//        if ((*i)->isDestroy()) {
//            delete (*i);
//            i = T->erase(i);
//            if (i == T->end()) {
//                break;
//            }
//        }
//        (*i)->update();
//    }
//
//}
//
//template<class BaseT>
//void  Actors::updateEnemy(std::vector<BaseT*>* T) {
//
//    for (auto i = T->begin(); i != T->end(); i++) {
//
//        onLine[(int)(*i)->getTilePosition().y] = true;
//
//        (*i)->update();
//
//        if (!(*i)->isAlive()) {
//            testGeld.addKontostand((*i)->getRevenue());
//
//            delete (*i);
//            i = T->erase(i);
//            if (i == T->end()) {
//                break;
//            }
//        }
//    }
//}
//
//template<class BaseT>
//void  Actors::deleteEntities(std::vector<BaseT*>* T) {
//
//    for (auto i = T->begin(); i != T->end(); i++) {
//        delete (*i);
//        (*i) = nullptr;
//    }
//
//    T->clear();
//}
//
//
//
//// get Methoden
//Geld* Actors::getGeld() {
//    return &testGeld;
//}
//
//
//// private Methoden
//void Actors::updateTowers()
//{
//    updateTower(&testTower);
//    updateTower(&mathelehrer);
//    updateTower(&inf_Lehrer);
//    updateTower(&en_Lehrer);
//    updateTower(&de_Lehrer);
//    updateTower(&metal_Lehrer);
//}
//
//void Actors::updateAmmos()
//{
//    updateAmmo(&testAmmo);
//    updateAmmo(&ma_Ammo);
//    updateAmmo(&inf_Ammo);
//    updateAmmo(&en_Ammo);
//    updateAmmo(&de_Ammo);
//    updateAmmo(&metal_Ammo);
//
//}
//
//void Actors::updateEnemies()
//{
//    for (int i = 0; i < 5; i++) {
//        onLine[i] = false;
//    }
//
//    updateEnemy(&testEnemy);
//    updateEnemy(&nerd);
//    updateEnemy(&steroidenking);
//
//}
//
//
//
//void Actors::CollisionEnemyWithTower()
//{
//    for (BaseTower* i : BaseTower::towers) {
//        for (BaseEnemy* j : BaseEnemy::enemies) {
//
//            sf::FloatRect tmp = i->getFloaRect();
//
//            if (j->CollisionWithTower(tmp) && j->isReadyToAttack()) {
//                i->wasAttacked(j->getDamage());
//                j->hasAttacked();
//            }
//        }
//    }
//}
//
//void Actors::CollisionAmmoWithEnemy()
//{
//    for (BaseEnemy* i : BaseEnemy::enemies) {
//        for (BaseAmmo* j : BaseAmmo::ammos) {
//
//            sf::FloatRect tmp = i->getFloaRect();
//
//            if (!j->isHit() && j->CollisionWithEnemy(tmp)) {
//                i->wasAttacked(j->getDamage());
//                if (j->status_Effect.getType() != Status_Type::non) {
//                    i->addStatus_Proc(j->status_Effect);
//                }
//            }
//        }
//    }
//}
//
//
//
//void Actors::renderShadows()
//{
//    for (BaseTower* i : BaseTower::towers) {
//        i->renderShadow();
//    }
//    for (BaseAmmo* i : BaseAmmo::ammos) {
//        i->renderShadow();
//    }
//    for (BaseEnemy* i : BaseEnemy::enemies) {
//        i->renderShadow();
//    }
//}
//
//void Actors::renderTowers()
//{
//    for (BaseTower* i : BaseTower::towers) {
//        i->render();
//    }
//}
//
//void Actors::renderAmmos()
//{
//    for (BaseAmmo* i : BaseAmmo::ammos) {
//        i->render();
//    }
//}
//
//void Actors::renderEnemies()
//{
//    for (BaseEnemy* i : BaseEnemy::enemies) {
//        i->render();
//    }
//}
//
//std::vector<BaseEnemy*>* Actors::getEnemy() {
//    return &BaseEnemy::enemies;
//}
//
//
//// Constructur & Destructur
//Actors::Actors()
//{
//    for (int i = 0; i < 5; i++) {
//        onLine[i] = false;
//    }
//}
//
//Actors::~Actors()
//{
//    // L�schung aller Gespeicherten Klassentypen
//
//    // Delete Towers
//    deleteEntities(&testTower);
//    deleteEntities(&mathelehrer);
//    deleteEntities(&inf_Lehrer);
//    deleteEntities(&en_Lehrer);
//    deleteEntities(&de_Lehrer);
//    deleteEntities(&metal_Lehrer);
//    
//
//    // Delete Ammos
//    deleteEntities(&testAmmo);
//    deleteEntities(&ma_Ammo);
//    deleteEntities(&inf_Ammo);
//    deleteEntities(&en_Ammo);
//    deleteEntities(&de_Ammo);
//
//
//    // Delete Enemies
//    deleteEntities(&testEnemy);
//    deleteEntities(&nerd);
//    deleteEntities(&steroidenking);
//
//}
//
//
////public Methoden
//void Actors::pauseActors()
//{
//    for (BaseTower* i : BaseTower::towers) {
//        i->paused();
//    }
//    for (BaseEnemy* i : BaseEnemy::enemies) {
//        i->paused();
//    }
//}
//
//void Actors::ContinueActors()
//{
//    for (BaseTower* i : BaseTower::towers) {
//        i->Continue();
//    }
//    for (BaseEnemy* i : BaseEnemy::enemies) {
//        i->Continue();
//    }
//}
//
//
//void Actors::updateActors()
//{
//    this->updateTowers();
//    this->updateAmmos();
//    this->updateEnemies();
//}
//
//void Actors::Collisions() 
//{
//    this->CollisionEnemyWithTower();
//    this->CollisionAmmoWithEnemy();
//}
//
//void Actors::renderActors()
//{
//    this->renderShadows();
//
//    this->renderTowers();
//    this->renderAmmos();
//    this->renderEnemies();
//
//    testGeld.render();
//}
//
//
//
//bool Actors::initializeTower(TowerType TowerType, sf::Vector2f TilePosition)
//{
//    if (TilePosition.x < 0 || TilePosition.x >7  ||  TilePosition.y < 0 || TilePosition.y > 4) {
//        return false;
//    }
//
//    for (BaseTower* i : BaseTower::towers) {
//        if ( i->getTilePosition() == TilePosition) {
//            return false;
//        }
//    }
//
//    switch (TowerType)
//    {
//    case TowerType::TestTower:
//        testTower.push_back(new TestTower(TilePosition));
//        break;
//    case TowerType::Mathelehrer:
//        mathelehrer.push_back(new Mathelehrer(TilePosition));
//        break;
//    case TowerType::INF_Lehrer:
//        inf_Lehrer.push_back(new INF_Lehrer(TilePosition));
//        break;
//    case TowerType::EN_Lehrer:
//        en_Lehrer.push_back(new EN_Lehrer(TilePosition));
//        break;
//    case TowerType::DE_Lehrer:
//        de_Lehrer.push_back(new DE_Lehrer(TilePosition));
//        break;
//    case TowerType::METAL_Lehrer:
//        metal_Lehrer.push_back(new METAL_Lehrer(TilePosition));
//        break;
//
//    default:
//        return false;
//        break;
//    }
//    return true;
//}
//
//bool Actors::initializeEnemy(EnemyType EnemyType, sf::Vector2f TilePosition )
//{
//    if (TilePosition.x < 0 || TilePosition.x >7 || TilePosition.y < 0 || TilePosition.y > 4) {
//        return false;
//    }
//
//    switch (EnemyType)
//    {
//    case EnemyType::TestEnemy:
//        testEnemy.push_back(new TestEnemy(TilePosition));
//        break;
//    case EnemyType::Nerd:
//        nerd.push_back(new Nerd(TilePosition));
//        break;
//    case EnemyType::Steroidenking:
//        steroidenking.push_back(new Steroidenking(TilePosition));
//        break;
//    default:
//        return false;
//        break;
//    }
//    return true;
//}
//
//void Actors::initializeAmmo(AmmoType AmmoType, sf::Vector2f TowerPosition)
//{
//    switch (AmmoType)
//    {
//    case AmmoType::TestAmmo:
//        testAmmo.push_back(new TestAmmo(TowerPosition));
//        break;
//    case AmmoType::Mathe:
//        ma_Ammo.push_back(new MA_Ammo(TowerPosition));
//        break;
//    case AmmoType::Inf_weak: 
//    case AmmoType::Inf_medium: 
//    case AmmoType::Inf_strong:
//        inf_Ammo.push_back(new INF_Ammo(TowerPosition, AmmoType ));
//        break;
//    case AmmoType::Englisch_weak: 
//    case AmmoType::Englisch_medium: 
//    case AmmoType::Englisch_strong: 
//    case AmmoType::Englisch_strongest:
//        en_Ammo.push_back(new EN_Ammo(TowerPosition, AmmoType));
//        break;
//    case AmmoType::DE_Ammo:
//        de_Ammo.push_back(new DE_Ammo(TowerPosition));
//        break;
//    case AmmoType::METAL_Ammo:
//        metal_Ammo.push_back(new METAL_Ammo(TowerPosition));
//        break;
//
//    default:
//        break;
//    }
//}
