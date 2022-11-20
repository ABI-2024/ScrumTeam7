#include "Karte.h"
#include "Window.h"

Karte::Karte(int cost, int type, sf::Texture* texture, sf::Vector2f pos) {
	this->cost = cost;
	this->type = type;

	this->Body.setPosition(pos);
	this->Body.setSize({ 70.f , 140.f});
	this->Body.setTexture(texture , 1);
}

Karte::~Karte() {

}

int Karte::getCost() {
	return cost;
}

int Karte::getType() {
	return type;
}

sf::Vector2f Karte::getPosition() {
	return Body.getPosition();
}

void Karte::render(){
	GameWindow::getWindow().draw(this->Body);
}