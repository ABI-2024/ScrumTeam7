#include "Karte.h"
#include "Window.h"

Karte::Karte(int cost, TowerType type, sf::Texture* texture, sf::Vector2f pos) {
	this->cost = cost;
	this->type = type;
	this->hovered = false;

	this->Body.setPosition(pos);
	sf::Vector2f size = { 180.f , 140.f };
	this->Body.setSize(size);
	//this->Body.setTexture(texture , 0);

	hitBox = Body.getGlobalBounds();
}

Karte::~Karte() {

}

int Karte::getCost() {
	return cost;
}

TowerType Karte::getType() {
	return type;
}

sf::Vector2f Karte::getPosition() {
	return Body.getPosition();
}


bool Karte::getHovered() {
	return this->hovered;
}

void Karte::update()
{
	sf::FloatRect mouse = { sf::Vector2f(Window.mapPixelToCoords(sf::Mouse::getPosition(Window))), {1,1} };
	
	if (hitBox.intersects(mouse)) {
		Body.setFillColor(sf::Color(200, 200, 200));
		this->hovered = true;
	}
	else {
		Body.setFillColor(sf::Color(255, 255, 255));
		this->hovered = false;
	}
}

void Karte::render(){
	update();
	GameWindow::getWindow().draw(this->Body);
}