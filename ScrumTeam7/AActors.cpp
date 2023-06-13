#include "AActors.h"

// Tower / Lehrer
#include "TestTower.h"
#include "Mathelehrer.h"
#include "INF_Lehrer.h"
#include "EN_Lehrer.h"
#include "DE_Lehrer.h"
#include "METAL_Lehrer.h"
#include "RELI_Lehrer.h"
#include "POWI_Lehrer.h"

// Ammo / Geschosse
#include "TestAmmo.h"
#include "MA_Ammo.h"
#include "INF_Ammo.h"
#include "EN_Ammo.h"
#include "DE_Ammo.h"
#include "METAL_Ammo.h"
#include "RELI_Ammo.h"

// Enemies / Gegener
#include "TestEnemy.h"
#include "Nerd.h"
#include "Steroidenking.h"
#include "Kreative.h"

	// ------------------------------------------ Nebenfuktion
int AActors::collectedRevenue = 0;

int AActors::getCollectedRevenue() {
	int ans = collectedRevenue;
	collectedRevenue = 0;
	return ans;
}
void AActors::addCollectedRevenue(int add) {
	collectedRevenue += add;
}
// ------------------------------------------ Nebenfuktion

// ------------------------------------------ Hauptfunktion

std::vector<Entity*>* AActors::entities = nullptr;

std::vector<Entity*>* AActors::ally = nullptr;
std::vector<Entity*>* AActors::allyAmmo = nullptr;
std::vector<Entity*>* AActors::enemies = nullptr;

void AActors::clearSeprateVectors(std::vector<Entity*>* vector, Entity* other)
{
	for (auto i = vector->begin(); i != vector->end(); i++) {

		if ((*i) == other) {
			vector->erase(i);
			break;
		}
	}
}

// Constructur & Destructur
AActors::AActors()
{
	entities = new std::vector<Entity*>;

	ally = new std::vector<Entity*>;
	allyAmmo = new std::vector<Entity*>;
	enemies = new std::vector<Entity*>;

	// Laden aden der Texturen der Entities
	Entity::loadTexture();

	// Alle TowerTypes
	TestTower::LoadTexture();
	Mathelehrer::LoadTexture();
	INF_Lehrer::LoadTexture();
	EN_Lehrer::LoadTexture();
	DE_Lehrer::LoadTexture();
	METAL_Lehrer::LoadTexture();
	RELI_Lehrer::LoadTexture();
	POWI_Lehrer::LoadTexture();

	// Alle AmmoTypes
	TestAmmo::LoadTexture();
	MA_Ammo::LoadTexture();
	INF_Ammo::LoadTexture();
	EN_Ammo::LoadTexture();
	DE_Ammo::LoadTexture();
	METAL_Ammo::LoadTexture();
	RELI_Ammo::LoadTexture();

	// Alle EnemyTypes
	TestEnemy::LoadTexture();
	Nerd::LoadTexture();
	Steroidenking::LoadTexture();
	Kreative::LoadTexture();

}

AActors::~AActors()
{
	// Delete alle existierende Entities
	for (auto i = entities->begin(); i != entities->end(); i++) {
		delete (*i);
	}

	// Delete der std::vector
	delete entities;

	delete ally;
	delete allyAmmo;
	delete enemies;



	// Endladen der Texturen der Entities
	Entity::unloadTexture();

	// Alle TowerTypes
	TestTower::unLoadTexture();
	Mathelehrer::unLoadTexture();
	INF_Lehrer::unLoadTexture();
	EN_Lehrer::unLoadTexture();
	DE_Lehrer::unLoadTexture();
	METAL_Lehrer::unLoadTexture();
	RELI_Lehrer::unLoadTexture();
	POWI_Lehrer::unLoadTexture();

	// Alle AmmoTypes
	TestAmmo::unLoadTexture();
	MA_Ammo::unLoadTexture();
	INF_Ammo::unLoadTexture();
	EN_Ammo::unLoadTexture();
	DE_Ammo::unLoadTexture();
	METAL_Ammo::unLoadTexture();
	RELI_Ammo::unLoadTexture();

	// Alle EnemyTypes
	TestEnemy::unLoadTexture();
	Nerd::unLoadTexture();
	Steroidenking::unLoadTexture();
	Kreative::unLoadTexture();
}

// Alle create-Fuktionen
bool AActors::create(const AllyType& type, const sf::Vector2f& position)
{
	bool created = 1;
	
	switch (type) { 
		// Wenn type eines der folgenden AllyTypen ist, wird überprüft ob an der übergebenen Funktion schon ein Tower steht

	case AllyType::TestTower:
	case AllyType::Mathelehrer:
	case AllyType::INF_Lehrer:
	case AllyType::EN_Lehrer:
	case AllyType::DE_Lehrer:
	case AllyType::METAL_Lehrer:
	case AllyType::RELI_Lehrer:
	case AllyType::POWI_Lehrer:

		if (position.x < 0 || position.x >7 || position.y < 0 || position.y > 4) {
			return false;
		}

		for (auto i = ally->begin(); i != ally->end(); i++) {
			if ((*i)->getTilePosition() == position) {
				return false;
			}
		}

		break;

	default:
		break;
	}


	switch (type) {

		    case AllyType::TestTower:
				entities->push_back(new TestTower(position));
		        break;
		    case AllyType::Mathelehrer:
				entities->push_back(new Mathelehrer(position));
		        break;
		    case AllyType::INF_Lehrer:
				entities->push_back(new INF_Lehrer(position));
		        break;
		    case AllyType::EN_Lehrer:
				entities->push_back(new EN_Lehrer(position));
		        break;
		    case AllyType::DE_Lehrer:
				entities->push_back(new DE_Lehrer(position));
		        break;
		    case AllyType::METAL_Lehrer:
				entities->push_back(new METAL_Lehrer(position));
		        break;
			case AllyType::RELI_Lehrer:
				entities->push_back(new RELI_Lehrer(position));
		        break;
			case AllyType::POWI_Lehrer:
				entities->push_back(new POWI_Lehrer(position));
		        break;

	default:
		created = 0;
		break;
	}

	if (created) {
		ally->push_back(entities->back());		
	}

	return created;
}

bool AActors::create(const AmmoType& type, const sf::Vector2f& position)
{
	bool created = 1;

	switch (type) {
		case AmmoType::TestAmmo:
			entities->push_back(new TestAmmo(position));
			break;
		case AmmoType::Mathe:
			entities->push_back(new MA_Ammo(position));
			break;
		case AmmoType::Inf_weak: 
		case AmmoType::Inf_medium: 
		case AmmoType::Inf_strong:
			entities->push_back(new INF_Ammo(position, type ));
			break;
		case AmmoType::Englisch_weak: 
		case AmmoType::Englisch_medium: 
		case AmmoType::Englisch_strong: 
		case AmmoType::Englisch_strongest:
			entities->push_back(new EN_Ammo(position, type));
			break;
		case AmmoType::DE_Ammo:
			entities->push_back(new DE_Ammo(position));
			break;
		case AmmoType::METAL_Ammo:
			entities->push_back(new METAL_Ammo(position));
			break;
		case AmmoType::RELI_Ammo:
			entities->push_back(new RELI_Ammo(position));
			break;

	default:
		created = 0;
		break;
	}

	if (created) {
		allyAmmo->push_back(entities->back());
	}

	return created;
}

bool AActors::create(const EnemyType& type, const sf::Vector2f& position)
{
	bool created = 1;

	switch (type) {

		    case EnemyType::TestEnemy:
				entities->push_back(new TestEnemy(position));
		        break;
		    case EnemyType::Nerd:
				entities->push_back(new Nerd(position));
		        break;
		    case EnemyType::Steroidenking:
				entities->push_back(new Steroidenking(position));
		        break;
		    case EnemyType::Kreative:
				entities->push_back(new Kreative(position));
		        break;

	default:
		created = 0;
		break;
	}

	if (created) {
		enemies->push_back(entities->back());
	}

	return created;
}

// destroy-Funktion
void AActors::destroy(Entity* other)
{
	switch (other->getCollisionType()) {

	case CollisionType::ally:
		clearSeprateVectors(ally, other);
		break;
	case CollisionType::allyAmmo:
		clearSeprateVectors(allyAmmo, other);
		break;

	case CollisionType::enemies:
		clearSeprateVectors(enemies, other);
		break;

	default:		break;
	}

	for (auto i = entities->begin(); i != entities->end(); i++) {
				
		if ((*i) == other) {
			
			delete (*i);
			(*i) = nullptr;
			return;
		}
	}
}

// Collisions-Funktionen
Entity* AActors::CollisionSingle(sf::FloatRect hitbox, const CollisionType& type)
{
	Entity* ans = nullptr;
	std::vector<Entity*>* temp = nullptr;

	switch (type) {
	case CollisionType::ally:
		temp = ally;
		break;
	case CollisionType::allyAmmo:
		temp = allyAmmo;
		break;
	case CollisionType::enemies:
		temp = enemies;
		break;

	default:
		break;
	}

	for (auto i = temp->begin(); i != temp->end(); i++) {
		if ((*i)->getHitBox().intersects(hitbox)) {
			ans = (*i);
			return ans;
		}
	}

	return ans;
}

std::vector<Entity*>* AActors::CollisionPoly(sf::FloatRect hitbox, const CollisionType& type)
{
	std::vector<Entity*>* ans = new 	std::vector<Entity*>;
	std::vector<Entity*>* temp = nullptr;

	switch (type) {
	case CollisionType::ally:
		temp = ally;
		break;
	case CollisionType::allyAmmo:
		temp = allyAmmo;
		break;
	case CollisionType::enemies:
		temp = enemies;
		break;

	default:
		break;
	}

	for (auto i = temp->begin(); i != temp->end(); i++) {
		if ((*i)->getHitBox().intersects(hitbox)) {
			ans->push_back((*i));
		}
	}

	return ans;
}

// update- & render-Funktionen
void AActors::updateEntities()
{
	BaseTower::areEnemiesOnLine(enemies);

	for (int i = 0; i < entities->size(); i++) {
		// std::vector kann wie ein Array behandelt werden
		if ((*entities)[i] != nullptr) {
			(*entities)[i]->update();
		}
	}

	for (auto i = entities->begin(); i != entities->end(); i++) {


		if ((*i) == nullptr) {
		redo:
			// löscht momentanes Element aus dem std::vector entities
			i = entities->erase(i);

			// Abfrage ob der zurück gegebene iterator von erase das Ende des std::vectors ist
			if (i == entities->end()) { 
				break;
			}

			/* 
			Abfrage ob der zurück gegebene iterator von erase ebenfalls ein nullptr ist
			und wenn ja wiederhole Vorgang.
			*/
			if ((*i) == nullptr) {
				goto redo;
			}

		}
	}
}

void AActors::renderEntities()
{
	for (auto i = entities->begin(); i != entities->end(); i++) {

		(*i)->render();
	}
}

// Diese Funktonen sind zum Stoppen und fortfahren aller sf::Clock aller Entities
void AActors::pauseEntities()
{
	for (int i = 0; i < entities->size(); i++) {
		// std::vector kann wie ein Array behandelt werden
		if ((*entities)[i] != nullptr) {
			(*entities)[i]->pauseEntitiy();
		}
	}
}

void AActors::continueEntities()
{
	for (int i = 0; i < entities->size(); i++) {
		// std::vector kann wie ein Array behandelt werden
		if ((*entities)[i] != nullptr) {
			(*entities)[i]->continueEntitiy();
		}
	}
}


// ------------------------------------------ Hauptfunktion