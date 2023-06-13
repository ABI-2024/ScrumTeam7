#pragma once

#include "BaseTower.h"
#include "RELI_Book.h"

class RELI_Lehrer : public BaseTower
{
private:
	static AllyType type;

	static float Health; // Leben des Lehrers

	static sf::Time fireRate;	// Feuerrate
	static sf::Time maximumFireRateDiviation;	// Maximale abweichung der Feuerrate

	static sf::Time bookRespawnTime; // Zeit wie lange das Buch braucht, um sich wiederherzustellen

	static sf::Texture* texture;

	RELI_Book book;	// Buch (Schild) des Lehrers

public:
	static void LoadTexture();		// laden der Texturen
	static void unLoadTexture();	// entladen der Texturen

	RELI_Lehrer(sf::Vector2f tilePosition);
	virtual ~RELI_Lehrer();

	void takeDamage(float) override;

	void update() override;
	void render() override;
};

