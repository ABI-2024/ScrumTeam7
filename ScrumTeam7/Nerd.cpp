#include "Nerd.h"
#include "Window.h"
#include "AActors.h"
#include "Cripple.h"

// static Variables

EnemyType Nerd::enemyType = EnemyType::Nerd;

float Nerd::Health = 200;
float Nerd::Damage = 20;

int Nerd::revenue = 8;

sf::Vector2f Nerd::dir = sf::Vector2f(-15, 0);

sf::Texture* Nerd::texture = nullptr;

sf::Time Nerd::attackSpeed = sf::milliseconds(750);


// public static Methoden
void Nerd::LoadTexture()
{
	if (texture == nullptr) {
		texture = new sf::Texture();

		if (!texture->loadFromFile("resource/Textures/Schueler/Nerd.png")) {
			texture->loadFromFile("resource/Textures/DefaultTexture.png");
		}
	}
}

void Nerd::unLoadTexture()
{
	delete texture;
	texture = nullptr;
}


// Constructur & Destructur
Nerd::Nerd(const sf::Vector2f& tilePosition)
	:BaseEnemy(Health, tilePosition, texture)
{
	programmzeit.restart();
}

Nerd::~Nerd()
{
	AActors::addCollectedRevenue(this->revenue);
	male->play();
}

// public Methoden

void Nerd::move()
{
	if (movable) {
		this->body.move(this->dir * dt);
	}
	else {
		movable = true;
	}
}

void Nerd::manipulation()
{
	int rightesttileposition;
	if (programmzeit.getElapsedTime() >= sf::seconds(2)) { //sobald 5 sekunden vergangen sind
		for (int i = 0; i < 5; i++) {
			std::vector<Entity*>* temp = AActors::CollisionPoly(sf::FloatRect(sf::Vector2f(0, 150.f + 150.f * i), sf::Vector2f(GameWindow::getMainView().getSize().x, 1)), CollisionType::ally); // neues array mit lehrer aus der reihe i
			if (temp != nullptr and temp->size() != 0) {
				rightesttileposition = (*temp)[0]->getTilePosition().x; // begin initialisierung für ...
				for (int j = 1; j < temp->size(); j++) {							// die Überprüfung des Lehrer, welcher am weitesten rechts ist in Zeile i
					if (rightesttileposition < (*temp)[j]->getTilePosition().x) {
						rightesttileposition = (*temp)[j]->getTilePosition().x;
					}
				}
				for (int k = 0; k < temp->size(); k++) {							//StatusEffect:Cripple wird auf den Lehrer übertragen
					if ((*temp)[k]->getTilePosition().x == rightesttileposition) {
						(*temp)[k]->addStatusEffect(StatusEffect(StatusType::cripple, sf::seconds(2), 0.5));
					}
				}

			}
			delete temp;
		}
	}
}

void Nerd::update()
{
	manipulation();
	if (health <= Health / 5) {
		body.setFillColor({ 139,0,0 }); //DarkRed
	}
	else if (health <= Health / 2) {
		body.setFillColor({ 255,48,48 }); //firebrick1

	}
	else if (health <= Health * 0.8) {
		body.setFillColor({ 255,99,71 }); //tomato1
	}

	updateStatusprocs(true, true);

	Entity* temp = AActors::CollisionSingle(body.getGlobalBounds(), CollisionType::ally);

	if (temp != nullptr && status.canAttack) {		//True wenn es mit einem Lehrer kollidiert
		movable = false;
		if (clock.getElapsedTime() + this->remainingAttackTime >= this->attackSpeed) {
			temp->takeDamage(this->Damage);

			this->remainingAttackTime = sf::seconds(0);
			clock.restart();
		}
	}
	else {
		movable = true;
	}

	if (status.canWalk) {
		this->move();
	}

	if (!status.alive) {
		AActors::destroy(this);
	}
}
