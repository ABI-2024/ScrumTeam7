#include "Menu.h"
#include "Window.h"

#include <string>


#define Anzahl_Button 3


int Menu::ans = 0;


void Menu::buttonEvents()
{

	for (int i = 0; i < Anzahl_Button; i++) {
		if (button[i].isHovered()) {
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
		button[i].render();
	}

}

Menu::Menu()
{


	this->open = true;

	
	// Font
	font = new sf::Font[1];
	font[0].loadFromFile("resource/fonts/Broken Console Bold.otf");

	// Button-Texture
	buttonTexture = new sf::Texture[3];
	buttonTexture[0].loadFromFile("resource/Textures/Button_Side1.png");
	buttonTexture[1].loadFromFile("resource/Textures/Button_Middle.png");
	buttonTexture[2].loadFromFile("resource/Textures/Button_Side2.png");

	//Button-text
	buttonText = new std::string[Anzahl_Button];
	buttonText[0] = "Start";
	buttonText[1] = "Optionen";
	buttonText[2] = "Exit";

	button = new Button[Anzahl_Button];
	for (int i = 0; i < Anzahl_Button; i++) {
		button[i] = Button(font[0], sf::Color(34, 32, 52), buttonText[i], buttonTexture, { GameWindow::getMainView().getSize().x / 2 , 240.f+ 200.f*i }, { 400.f, 120.f });
	}


}

Menu::~Menu()
{
	delete[] button;
	delete[] buttonTexture;
}

int Menu::openMenu()
{
	Menu menu;

	sf::Texture* background_Texture = new sf::Texture();
	background_Texture->loadFromFile("resource/Textures/DefaultTexture.png");

	sf::RectangleShape background;
	background.setPosition(0,0);
	background.setSize( GameWindow::getMainView().getSize() );
	background.setTexture(background_Texture,0);


	while (Window.isOpen() && menu.open)
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

			case sf::Event::MouseButtonPressed:
				menu.buttonEvents();
				break;

			default:
				break;
			}
		}

		for (int i = 0; i < Anzahl_Button; i++) {
			menu.button[i].update();
		}

		Window.clear();

		Window.setView(GameWindow::getMainView());

		Window.draw(background);

		menu.render();

		Window.display();
	}

	return Menu::ans;
}
