#pragma once

#include <string>

#include "SFML/Graphics.hpp"

class Button
{

private:

	sf::Text text;
	sf::RectangleShape Body[3];
	sf::FloatRect hitBox;

	bool hovered;
	sf::Texture* texture;

	void initVariables(const sf::Vector2f& Button_Position, const sf::Vector2f& Button_Size);
public:
	Button();
	Button(const sf::Font& font, const sf::Color& textColor, const std::string& text, sf::Texture* texture, const sf::Vector2f& ButtonPosition, const sf::Vector2f& ButtonSize);
	~Button();

	const bool& isHovered();

	void update();
	
	void render();
};

