#pragma once
#include <string>

#include "SFML/Graphics.hpp"

class Button2
{

private:

	sf::Text text;
	sf::RectangleShape* Body;
	sf::FloatRect hitBox;

	bool hovered;
	sf::Texture* texture;

	void initVariables(const sf::Vector2f& Button_Position, const sf::Vector2f& Button_Size);
public:
	Button2( sf::Texture* texture, const sf::Vector2f& ButtonPosition, const sf::Vector2f& ButtonSize);
	~Button2();

	const bool& isHovered();

	void setText(const std::string& text);

	void update();
	
	void render();
};

