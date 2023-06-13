//#pragma once
//#include <string>
//#include <vector>
//
//#include "enums.h"
//#include "Geld.h"
//
//// Tower / Lehrer
//#include "TestTower.h"
//#include "Mathelehrer.h"
//#include "INF_Lehrer.h"
//#include "EN_Lehrer.h"
//#include "DE_Lehrer.h"
//#include "METAL_Lehrer.h"
//
//// Ammo / Geschosse
//#include "TestAmmo.h"
//#include "MA_Ammo.h"
//#include "INF_Ammo.h"
//#include "EN_Ammo.h"
//#include "DE_Ammo.h"
//#include "METAL_Ammo.h"
//
//// Enemies / Gegener
//#include "TestEnemy.h"
//#include "Nerd.h"
//#include "Steroidenking.h"
//
//
///*
//	Diese Klasse enthält alle Tower-,Enemies- und Ammotypen
//	
//	Sie kann die oben Genannten Klassen
//		- updaten
//		- Collidieren
//		- rendern
//
//	
//	Guide um neue Entities anzuschließen
//	1. Einen [ std::vector<Klassenname*> ] in Actors.h erstellen
//	2. In der "Actors.cpp" in den Methoden updateTowers() / updateAmmos() oder updateEnemies() wie die Anderen einbinden.
//	3. In der "Actors.cpp" in den Methoden ~Actors() in die Funktionen einbinden.
//*/
//
//class Wellen;
//
//
//class Actors
//{
//	friend Wellen;
//private:
//
//	// Gibt an ob ein gegner auf dem Feld ist
//	bool onLine[5];
//
//	sf::Text text;
//
//	// Money / Geld
//	Geld testGeld;
//
//	// Alle vectoren von Tower / Lehrer
//	std::vector<TestTower*> testTower;
//	std::vector<Mathelehrer*> mathelehrer;
//	std::vector<INF_Lehrer*> inf_Lehrer;
//	std::vector<EN_Lehrer*> en_Lehrer;
//	std::vector<DE_Lehrer*> de_Lehrer;
//	std::vector<METAL_Lehrer*> metal_Lehrer;
//
//	// Alle vectoren von Ammo / Geschosse
//	std::vector<TestAmmo*> testAmmo;
//	std::vector<MA_Ammo*> ma_Ammo;
//	std::vector<INF_Ammo*> inf_Ammo;
//	std::vector<EN_Ammo*> en_Ammo;
//	std::vector<DE_Ammo*> de_Ammo;
//	std::vector<METAL_Ammo*> metal_Ammo;
//
//
//	// Alle vectoren von Enemies / Gegener
//	std::vector<TestEnemy*> testEnemy;
//	std::vector<Nerd*> nerd;
//	std::vector<Steroidenking*> steroidenking;
//
//	
//
//	template<class BaseT>
//	void updateTower(std::vector<BaseT*>* T);
//
//	template<class BaseT>
//	void updateAmmo(std::vector<BaseT*>* T);
//
//	template<class BaseT>
//	void updateEnemy(std::vector<BaseT*>* T);
//
//	template<class BaseT>
//	void deleteEntities(std::vector<BaseT*>* T);
//
//
//
//	// Updaten alle vectoren und ihre zugehörigen BasisTypen*
//	void updateTowers();
//	void updateAmmos();
//	void updateEnemies();
//
//	// Sorgt für Collision von den Klassen
//	void CollisionEnemyWithTower();
//	void CollisionAmmoWithEnemy();
//
//	// Rendert alle Klassen
//	void renderShadows();
//	void renderTowers();
//	void renderAmmos();
//	void renderEnemies();
//public:
//	Actors();
//	~Actors();
//
//	// get Methoden
//	Geld* getGeld();
//
//	void pauseActors();
//	void ContinueActors();
//
//	// Ruft alle Update-Methoden
//	void updateActors();
//
//	// Ruft alle Collisions-Methoden
//	void Collisions();
//
//	// Ruft alle Render-Methoden
//	void renderActors();
//
//	// Gibt die Liste der Enemys zurück
//	std::vector<BaseEnemy*>* getEnemy();
//
//	// Initialisiert die Klassen
//	bool initializeTower(TowerType TowerType, sf::Vector2f TilePosition);
//	bool initializeEnemy(EnemyType EnemyType, sf::Vector2f TilePosition);
//
//	void initializeAmmo(AmmoType AmmoType, sf::Vector2f TowerPosition); // Beachte Parametername des Vectors
//
//	// Verändert die Geldmenge
//
//
//};