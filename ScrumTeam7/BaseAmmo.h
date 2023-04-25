#pragma once

#include "Entity.h"
#include "Status_Effect.h"

#include "enums.h"



class BaseAmmo : public Entity
{
public:
	static std::vector<BaseAmmo*> ammos;

	Status_Effect status_Effect;
protected:

	bool hit;

public:
	BaseAmmo(const sf::Vector2f& TowerPosition, sf::Texture * texture);
	~BaseAmmo();

	bool isHit();

	virtual AmmoType getAmmoType() = 0;
	virtual float getDamage() = 0;

	void hasHit();

	virtual bool CollisionWithEnemy(sf::FloatRect& Enemy) = 0;

	virtual void update() = 0;
	void render();
	void renderShadow() override;
};


