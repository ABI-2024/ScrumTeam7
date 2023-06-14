#include "METAL_Ammo.h"

#include "Window.h"
#include "AActors.h"

// public static Variables
AmmoType METAL_Ammo::ammoType = AmmoType::METAL_Ammo;


// static Variables private
float METAL_Ammo::damage = 0.f;
sf::Texture* METAL_Ammo::texture = nullptr;

sf::Time METAL_Ammo::damageWindowStart = { sf::milliseconds(200) };
sf::Time METAL_Ammo::activeTime = { sf::milliseconds(300) };


// public static Methoden 
void METAL_Ammo::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/Lehrer/METAL/METAL-Ammo.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}
}

void METAL_Ammo::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}


// Constructur & Destructur
METAL_Ammo::METAL_Ammo(sf::Vector2f TowerPosition)
	:BaseAmmo(TowerPosition, texture), state(AttackState::Accelerate)
{
	body.setSize(sf::Vector2f(42.1875f * 48.f / 9.f, 42.1875f * 10.f / 9.f) * 1.5f);
	body.setOrigin({ 0.f, body.getSize().y / 2.f });
}

METAL_Ammo::~METAL_Ammo() {}


// public Methoden

void METAL_Ammo::update()
{
	if (timer.getElapsedTime() >= damageWindowStart) {
		if (state != AttackState::Hit) {
			body.setSize(sf::Vector2f(42.1875f * 48.f / 9.f, 42.1875f * 10.f / 9.f) * 1.5f);
			body.setTexture(&texture[0], 1);
			state = AttackState::Hit;
		}
	}

	std::vector<Entity*>* temp = nullptr;
	if (status.alive && state == AttackState::Hit) {

		temp = AActors::CollisionPoly(body.getGlobalBounds(), CollisionType::enemies);
		for (int i = 0; i < temp->size(); i++) {
			(*temp)[i]->addStatusEffect( StatusEffect(StatusType::burn, sf::milliseconds(2000), 50.f) );
			(*temp)[i]->takeDamage(this->damage);
		}

		status.alive = false;
		delete temp;
	}

	if (!status.alive && timer.getElapsedTime() >= this->activeTime) {
		AActors::destroy(this);
	}
}
