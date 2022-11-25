#include "Menu.h"
#include "Window.h"

#include <string>


#define Anzahl_Button 3


int Menu::ans = 0;

void Menu::buttonVisuals()
{
	sf::FloatRect mouse(sf::Vector2f(sf::Mouse::getPosition(Window)), { 1,1 });

	for (int i = 0; i < 3; i++) {
		if (button[i].getGlobalBounds().intersects(mouse)) {
			button[i].setFillColor(sf::Color(200,200,200));
		}
		else {
			button[i].setFillColor(sf::Color(255,255,255));
		}
	}
}

void Menu::buttonEvents()
{
	sf::FloatRect mouse(sf::Vector2f(sf::Mouse::getPosition(Window)), { 1,1 });

	for (int i = 0; i < 3; i++) {
		if (button[i].getGlobalBounds().intersects(mouse)) {
			switch (i) {
			case 0:
				Menu::ans = 1;
				this->open = false;
				break;
			case 1:
				Menu::ans = 2;
				this->open = false;
				break;
			case 2:
				Menu::ans = 0;
				Window.close();
				break;
			default:
				break;
			}
		}
	}
}

void Menu::render()
{
	for (int i = 0; i < Anzahl_Button; i++) {
		Window.draw(button[i]);
		Window.draw(buttonText[i]);
	}
}

Menu::Menu()
{

	this->open = true;

	// Button-Texture
	buttonTexture = new sf::Texture();// [Anzahl_Button] ;
	buttonTexture->loadFromFile("resource/Textures/Button_Empty.png");

	// Button-Body
	button = new sf::RectangleShape[Anzahl_Button];
	for (int i = 0; i < Anzahl_Button; i++) {
		button[i].setPosition(((float)Window.getSize().x*2)/4, 200.f*(i)+240);
		button[i].setSize({360,120});
		button[i].setOrigin( button[i].getSize().x/2 , button[i].getSize().y / 2);
		button[i].setTexture(buttonTexture, 1);
	}

	// Font und Text
	font = new sf::Font;
	font->loadFromFile("resource/fonts/Broken Console Bold.otf");

	buttonText = new sf::Text[Anzahl_Button];

	

	buttonText[0].setString("Start");
	buttonText[1].setString("Options");
	buttonText[2].setString("Exit");

	
	for (int i = 0; i < Anzahl_Button; i++) {

		buttonText[i].setFont(*font);
		buttonText[i].setFillColor(sf::Color(34,32,52));
		buttonText[i].setCharacterSize(60);
		size_t tmp = buttonText[i].getString().getSize();
		buttonText[i].setPosition(button[i].getPosition().x - 35 * (tmp /2 + tmp % 2) , button[i].getPosition().y - 35 );
	}

}

Menu::~Menu()
{
	delete[] button;
	delete buttonTexture;
}

int Menu::openMenu()
{
	Menu* menu = new Menu();

	sf::Texture* background_Texture = new sf::Texture;
	background_Texture->loadFromFile("resource/Textures/DefaultTexture.png");

	sf::RectangleShape* background = new sf::RectangleShape;
	background->setPosition(0,0);
	background->setSize(sf::Vector2f( Window.getSize() ));
	background->setTexture(background_Texture,0);


	while (Window.isOpen() && menu->open)
	{
		while ( Window.pollEvent(GameEvent)) {
			switch (GameEvent.type)
			{
			case sf::Event::Closed:
				GameWindow::getWindow().close();
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					Window.close();
				}
				break;
			case sf::Event::MouseMoved:
				menu->buttonVisuals();
				break;
			case sf::Event::MouseButtonPressed:
				menu->buttonEvents();
				break;
			default:
				break;
			}
		}

		Window.clear();

		Window.draw(*background);

		menu->render();

		Window.display();
	}

	delete menu;

	return Menu::ans;
}
