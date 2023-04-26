#pragma once

#include "SFML/Graphics.hpp"

enum class Effects {
	burn,
	poison,
	stun,
	music,
	knockback
};

class Status_Effects
{
	// burn
	struct damageOverTime{
		bool active;
		float damage;
		sf::Time duration;
		sf::Clock timer;
	} burn, poison;

	// stun
	bool active;
	sf::Time stunDuration;
	sf::Clock stunTimer;
};

