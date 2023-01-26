#include "Raster.h"

float Raster::offset = 0;

Raster::Raster(int x, int y) {
	rectangle.setSize(sf::Vector2f(150, 150));
	rectangle.setOrigin(sf::Vector2f(rectangle.getSize().x /2, rectangle.getSize().y / 2));
	rectangle.setOutlineColor(sf::Color(127, 127, 127, 152));
	rectangle.setOutlineThickness(2);
	rectangle.setFillColor(sf::Color::Transparent);
	rectangle.setPosition(x, y);
}

void Raster::render() {

	GameWindow::getWindow().draw(this->rectangle);
}

void Raster::setRasterPosition(int x, int y) {
	rectangle.setPosition(400 + 150 * x, 150 + offset + 150 * y); //Size mal Anzahl (bei Y + 3 wegen Größe des pngs)
}
