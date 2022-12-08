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
	Diese Klasse enth�lt alle Tower-,Enemies- und Ammotypen
	
	Sie kann die oben Genannten Klassen
		- updaten
		- Collidieren
		- rendern

	ToDo:

*/


class Actors
{
private:


	sf::Text text;

	// Money / Geld
	Geld testGeld;

	// Alle vectoren von Tower / Lehrer
	std::vector<TestTower> testTower;

	// Alle vectoren von Ammo / Geschosse
	std::vector<TestAmmo> testAmmo;

	// Alle vectoren von Enemies / Gegener
	std::vector<TestEnemy> testEnemy;


	// Alle vectoren mit den BasisTypen* der Klassen
	std::vector<BaseTower*> Towers;
	std::vector<BaseAmmo*> Ammos;
	std::vector<BaseEnemy*> Enemies;



	// Updaten alle vectoren und ihre zugeh�rigen BasisTypen*
	void updateTowers();
	void updateAmmos();
	void updateEnemies();

	// Sorgt f�r Collision von den Klassen
	void CollisionEnemyWithTower();
	void CollisionAmmoWithEnemy();

	// Rendert alle Klassen
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

	// Initialisiert die Klassen
	void initializeTower(TowerType TowerType, sf::Vector2f TilePosition);
	void initializeEnemy(EnemyType EnemyType, sf::Vector2f TilePosition);

	void initializeAmmo(AmmoType AmmoType, sf::Vector2f TowerPosition); // Beachte Parametername des Vectors

};

