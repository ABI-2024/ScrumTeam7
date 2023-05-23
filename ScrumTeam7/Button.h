#pragma once

#include <string>

#include "SFML/Graphics.hpp"

class Button
{

private:

	sf::Text text;
	sf::RectangleShape* Body;
	sf::FloatRect hitBox;

	bool hovered, standart;
	sf::Texture* texture;

	void initVariables(const sf::Vector2f& Button_Position, const sf::Vector2f& Button_Size);
public:
	Button(const sf::Font& font, const sf::Color& textColor, const std::string& text, sf::Texture* texture, const sf::Vector2f& ButtonPosition, const sf::Vector2f& ButtonSize, bool Standart);
	~Button();

	const bool& isHovered();

	void setText(const std::string& text);

	void update();
	
	void render();
};

