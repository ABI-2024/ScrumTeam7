#include "Menu_Options.h"

#define Anzahl_Button 3

#include "Window.h"

Menu_Options::Menu_Options() {
	this->open = true;

	backgroundTexture = new sf::Texture();
	backgroundTexture->loadFromFile("resource/Textures/DefaultTexture.png");

	background.setPosition(0, 0);
	background.setSize(sf::Vector2f(Window.getSize()));
	background.setTexture(backgroundTexture, 0);

	// Font
	font.loadFromFile("resource/fonts/Broken Console Bold.otf");

	// Button-Texture
	buttonTexture = new sf::Texture[3];
	buttonTexture[0].loadFromFile("resource/Textures/Button_Side1.png");
	buttonTexture[1].loadFromFile("resource/Textures/Button_Middle.png");
	buttonTexture[2].loadFromFile("resource/Textures/Button_Side2.png");

	//Button-text
	/*
		Auflösung, Lautstärke(Musik, Sound), 
	
	
	*/

	buttonText = new std::string[Anzahl_Button];
	buttonText[0] = "";
	buttonText[1] = "";
	buttonText[2] = "";

	button = new Button[Anzahl_Button];
	for (int i = 0; i < Anzahl_Button; i++) {
		button[i] = Button(font, sf::Color(34, 32, 52), buttonText[i], buttonTexture, { GameWindow::getMainView().getSize().x/2  , 240.f + 200.f * i }, { 360.f, 120.f });
	}
}

Menu_Options::~Menu_Options()
{
	delete[] buttonText;
	delete[] buttonTexture;
	delete[] button;
}

void Menu_Options::buttonEvents()
{
	for (int i = 0; i < Anzahl_Button; i++) {
		if (button[i].isHovered()) {
			switch (i) {
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			default:
				break;
			}
		}
	}
}

void Menu_Options::updateButtom()
{
	for (int i = 0; i < Anzahl_Button; i++) {
		button->update();
	}
}

void Menu_Options::render()
{
	Window.draw(background);
	for (int i = 0; i < Anzahl_Button; i++) {
		button->render();
	}
}

void Menu_Options::openOptions()
{
	Menu_Options menu;

	while (Window.isOpen() && menu.open)
	{
		while (Window.pollEvent(GameEvent)) {
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

		menu.updateButtom();

		Window.clear();

		menu.render();

		Window.display();
	}
}
