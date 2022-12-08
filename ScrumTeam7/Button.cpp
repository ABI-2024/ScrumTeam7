#include "Button.h"

#include <iostream>

#include "Window.h"

void Button::initVariables(const sf::Vector2f& Button_Position, const sf::Vector2f& Button_Size)
{
	sf::Vector2f side = { Button_Size.y / 2, Button_Size.y };
	sf::Vector2f middle = { Button_Size.x - Button_Size.y, Button_Size.y };

	// Button Left
	Body[0].setPosition(Button_Position.x - middle.x / 2 , Button_Position.y);
	Body[0].setSize(side);
	Body[0].setOrigin({ Body[0].getSize().x , Body[0].getSize().y / 2 });
	Body[0].setTexture( &texture[0] , 0);

	// Button Middle
	Body[1].setPosition(Button_Position);
	Body[1].setSize(middle);
	Body[1].setOrigin({ Body[1].getSize().x/2 , Body[1].getSize().y / 2 });
	Body[1].setTexture( &texture[1] , 0);

	// Button Right
	Body[2].setPosition(Button_Position.x + middle.x / 2, Button_Position.y);
	Body[2].setSize({ side });
	Body[2].setOrigin({ 0 , Body[2].getSize().y / 2 });
	Body[2].setTexture( &texture[2] , 0);

	hitBox = { { Button_Position.x - Button_Size.x / 2, Button_Position.y - Button_Size .y/ 2.f }, Button_Size };
}

Button::Button()
{
	this->hovered = false;
	this->texture = nullptr;
}

Button::Button(const sf::Font& font, const sf::Color& textColor, const std::string& text, sf::Texture* texture, const sf::Vector2f& ButtonPosition, const sf::Vector2f& ButtonSize)
{
	this->text.setFont(font);
	this->text.setFillColor(textColor);
	this->text.setString(text);
	this->text.setCharacterSize( ButtonSize.y / 2.f);
	this->text.setOrigin(this->text.getGlobalBounds().width/2 , ButtonSize.y/4 + ButtonSize.x / 64);
	this->text.setPosition(ButtonPosition );

	this->hovered = false;

	this->texture = texture;

	this->initVariables( ButtonPosition, ButtonSize);
}

Button::~Button()
{
}

const bool& Button::isHovered()
{
	return this->hovered;
}

void Button::update()
{
	sf::FloatRect mouse = {sf::Vector2f( sf::Mouse::getPosition(Window) ), {1,1} };

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

void Button::render()
{
	for (int i = 0; i < 3; i++) {
		Window.draw(Body[i]);
	}
	Window.draw(this->text);
}