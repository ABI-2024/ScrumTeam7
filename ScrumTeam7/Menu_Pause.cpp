#include "Menu_Pause.h"

#include "Window.h"

#define Anzahl_Button 3

Menu_Pause::Menu_Pause()
{
	background.setPosition(0, 0);
	background.setSize(sf::Vector2f(Window.getSize()));
	background.setFillColor(sf::Color(0,0,0,200));

	// Font
	font.loadFromFile("resource/fonts/Broken Console Bold.otf");

	// Button-Texture
	buttonTexture = new sf::Texture[3];
	buttonTexture[0].loadFromFile("resource/Textures/Button_Side1.png");
	buttonTexture[1].loadFromFile("resource/Textures/Button_Middle.png");
	buttonTexture[2].loadFromFile("resource/Textures/Button_Side2.png");

	//Button-text
	buttonText = new std::string[Anzahl_Button];
	buttonText[0] = "Continue";
	buttonText[1] = "Options";
	buttonText[2] = "Exit";

	button = new Button[Anzahl_Button];
	for (int i = 0; i < Anzahl_Button; i++) {
		button[i] = Button(font, sf::Color(34, 32, 52), buttonText[i], buttonTexture, { (float)Window.getSize().x / 2 , 240.f + 200.f * i }, { 500.f, 120.f });
	}
}

Menu_Pause::~Menu_Pause()
{
	delete[] buttonTexture;
	delete[] buttonText;
	delete[] button;
}

int Menu_Pause::mouseClick()
{
	for (int i = 0; i < Anzahl_Button; i++) {
		if (button[i].isHovered()) {
			return i;
		}
	}
	return -1;
}

void Menu_Pause::update()
{
	for (int i = 0; i < Anzahl_Button; i++) {
		button[i].update();
	}
}


void Menu_Pause::render()
{
	Window.draw(background);
	for (int i = 0; i < Anzahl_Button; i++) {
		button[i].render();
	}

}
