#include "DE_Ammo.h"

#include "Window.h"
#include "AActors.h"

// public static Variables
AmmoType DE_Ammo::ammoType = AmmoType::DE_Ammo;


// static Variables private
float DE_Ammo::damage = 50.f;
sf::Texture* DE_Ammo::texture = nullptr;

sf::Time DE_Ammo::damageWindowStart = {sf::milliseconds(200)};
sf::Time DE_Ammo::activeTime = { sf::milliseconds(300) };


// public static Methoden 
void DE_Ammo::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture[3];

		if (!texture[0].loadFromFile("resource/Textures/Lehrer/DE/DE-Ammo-Start.png")) {
			texture[0].loadFromFile("resource/Textures/DefaultTexture.png");
		}
		if (!texture[1].loadFromFile("resource/Textures/Lehrer/DE/DE-Ammo-Middle.png")) {
			texture[1].loadFromFile("resource/Textures/DefaultTexture.png");
		}
		if (!texture[2].loadFromFile("resource/Textures/Lehrer/DE/DE-Ammo-End.png")) {
			texture[2].loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}
}

void DE_Ammo::unLoadTexture()
{
	delete[] texture;
	texture = nullptr;
}


// Constructur & Destructur
DE_Ammo::DE_Ammo(sf::Vector2f TowerPosition)
	:BaseAmmo(TowerPosition, &texture[0]), state(AttackState::Book)
{
	status_Effect = {Status_Type::stun, 20.f, sf::seconds(0) };
	body.setSize(sf::Vector2f(42.1875f * 8.f/9.f, 42.1875f * 11.f/9.f)*1.5f );
	body.setOrigin({ 0.f, body.getSize().y /2.f});
}

DE_Ammo::~DE_Ammo() {}

// public Methoden
AmmoType DE_Ammo::getAmmoType()
{
	return this->ammoType;
}

float DE_Ammo::getDamage()
{
	return this->damage;
}

void DE_Ammo::update()
{

	if (timer.getElapsedTime()  <= damageWindowStart- sf::milliseconds(150)) {

		if (state != AttackState::Book) {
			body.setSize(sf::Vector2f(42.1875f * 8.f / 9.f, 42.1875f * 11.f / 9.f) * 1.5f);
			body.setTexture(&texture[0], 1);
			state = AttackState::Book;
		}

	}
	if (timer.getElapsedTime() <= damageWindowStart) {

		if (state != AttackState::Accelerate) {
			body.setSize(sf::Vector2f(42.1875f * 18.f / 9.f, 42.1875f * 11.f / 9.f) * 1.5f);
			body.setTexture(&texture[1], 1);
			state = AttackState::Accelerate;
		}
	}
	else if (timer.getElapsedTime() >= damageWindowStart) {
		if (state != AttackState::Hit) {
			body.setSize(sf::Vector2f(42.1875f * 32.f / 9.f, 42.1875f * 11.f / 9.f) * 1.5f);
			body.setTexture(&texture[2], 1);
			state = AttackState::Hit;
		}
	}

	std::vector<Entity*>* temp = nullptr;
	if (alive && state == AttackState::Hit) {

		temp = AActors::CollisionPoly(this,CollisionType::enemies);
		for (int i = 0; i < temp->size(); i++) {
			(*temp)[i]->takeDamage(this->damage);
		}

		alive = false;
		delete temp;
	}

	if (!alive && timer.getElapsedTime() >= this->activeTime) {
		AActors::destroy(this);
	}
}
