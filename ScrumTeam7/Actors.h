#pragma once
#include <string>
#include <vector>

#include "enums.h"
#include "Geld.h"

// Tower / Lehrer
#include "TestTower.h"

// Ammo / Geschosse
#include "TestAmmo.h"

// Enemies / Gegener
#include "TestEnemy.h"


/*
	Diese Klasse enthält alle Tower-,Enemies- und Ammotypen
	
	Sie kann die oben Genannten Klassen
		- updaten
		- Collidieren
		- rendern
*/

class Wellen;
class Actors
{
	friend Wellen;
private:

	// Gibt an ob ein gegner auf dem Feld ist
	bool onLine[5];

	sf::Text text;

	// Money / Geld
	Geld testGeld;

	// Alle vectoren von Tower / Lehrer
	std::vector<TestTower*> testTower;

	// Alle vectoren von Ammo / Geschosse
	std::vector<TestAmmo*> testAmmo;

	// Alle vectoren von Enemies / Gegener
	std::vector<TestEnemy*> testEnemy;

	

	// Updaten alle vectoren und ihre zugehörigen BasisTypen*
	void updateTowers();
	void updateAmmos();
	void updateEnemies();

	// Sorgt für Collision von den Klassen
	void CollisionEnemyWithTower();
	void CollisionAmmoWithEnemy();

	// Rendert alle Klassen
	void renderShadows();
	void renderTowers();
	void renderAmmos();
	void renderEnemies();
public:
	Actors();
	~Actors();

	void pauseActors();
	void ContinueActors();

	// Ruft alle Update-Methoden
	void updateActors();

	// Ruft alle Collisions-Methoden
	void Collisions();

	// Ruft alle Render-Methoden
	void renderActors();

	// Gibt die Liste der Enemys zurück
	std::vector<BaseEnemy*>* getEnemy();

	Geld& getGeld();

	// Initialisiert die Klassen
	bool initializeTower(TowerType TowerType, sf::Vector2f TilePosition);
	bool initializeEnemy(EnemyType EnemyType, sf::Vector2f TilePosition);

	void initializeAmmo(AmmoType AmmoType, sf::Vector2f TowerPosition); // Beachte Parametername des Vectors

	// Verändert die Geldmenge

};