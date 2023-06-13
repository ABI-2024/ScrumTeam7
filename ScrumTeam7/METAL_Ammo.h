#pragma once

#include "BaseAmmo.h"

class METAL_Ammo : public BaseAmmo
{
private:
	static AmmoType ammoType;

	static float damage;

	static sf::Texture* texture;

	static sf::Time damageWindowStart, activeTime;

	sf::Clock timer;
	enum class AttackState {
		Accelerate,
		Hit
	} state;

public:
	static void LoadTexture();
	static void unLoadTexture();

	METAL_Ammo(sf::Vector2f TowerPosition);
	virtual ~METAL_Ammo();


	void update() override;


};

