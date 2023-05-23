#include "Button2.h"

#include <iostream>

#include "Window.h"

Button2::Button2( sf::Texture* texture, const sf::Vector2f& Button2Position, const sf::Vector2f& Button2Size)
	:hovered(false)
{

	this->texture = texture;
	
	Body = new sf::RectangleShape();
	Body->setPosition(Button2Position);
	Body->setSize(Button2Size);
	Body->setOrigin(Button2Size / 2.f);
	Body->setTexture(texture, 0);

	hitBox = Body->getGlobalBounds();
}

Button2::~Button2()
{
	delete Body;

}

const bool& Button2::isHovered()
{
	return this->hovered;
}

void Button2::setText(const std::string& text)
{
	this->text.setString(text);
	this->text.setOrigin(this->text.getGlobalBounds().width / 2, this->hitBox.height / 4 + this->hitBox.width / 64);
}

void Button2::update()
{
	sf::FloatRect mouse = {sf::Vector2f( Window.mapPixelToCoords(sf::Mouse::getPosition(Window) )), {1,1} };
	
	if (hitBox.intersects(mouse)) {
		for (int i = 0; i < 3; i++) {
			Body[i].setFillColor(sf::Color(200, 200, 200));
		}
		this->hovered = true;
	}
	else {
		for (int i = 0; i < 3; i++) {
			Body[i].setFillColor(sf::Color(255, 255, 255));
		}
		this->hovered = false;
	}
}

void Button2::render()
{
	for (int i = 0; i < 3; i++) {
		Window.draw(Body[i]);
	}
	Window.draw(this->text);
}