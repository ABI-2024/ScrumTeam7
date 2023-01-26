#include "Rectangle.h"

Rectangle::Rectangle(int x, int y) {
	rectangle.setSize(sf::Vector2f(160, 142));
	rectangle.setOrigin(sf::Vector2f(80, 80));
	rectangle.setOutlineColor(sf::Color(127, 127, 127, 152));
	rectangle.setOutlineThickness(2);
	rectangle.setFillColor(sf::Color::Transparent);
	rectangle.setPosition(x, y);
}

void Rectangle::render() {

	GameWindow::getWindow().draw(this->rectangle);
}

void Rectangle::setRectanglePosition(int x, int y) {
	rectangle.setPosition(160 * x, 142 * y + 3); //Size mal Anzahl (bei Y + 3 wegen Größe des pngs)
}