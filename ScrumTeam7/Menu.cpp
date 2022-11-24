#include "Menu.h"
#include "Window.h"

void Menu::buttonEvents()
{
	sf::FloatRect mouse(sf::Vector2f(sf::Mouse::getPosition(Window)), { 1,1 });

	for (int i = 0; i < 3; i++) {
		if (button[i].getGlobalBounds().intersects(mouse)) {
			switch (i) {
			case 0:
				this->open = false;
				break;
			case 1:

				break;
			case 2:
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
	for (int i = 0; i < 3; i++) {
		Window.draw(button[i]);
	}
}

Menu::Menu()
{

	this->open = true;

	for (int i = 0; i < 3; i++)
		buttonTexture[i] = new sf::Texture();

		buttonTexture[0]->loadFromFile("Textures/Button_Start.png");
		buttonTexture[1]->loadFromFile("Textures/Button_Options.png");
		buttonTexture[2]->loadFromFile("Textures/Button_Exit.png");

	for (int i = 0; i < 3; i++) {
		button[i].setPosition(((float)Window.getSize().x*3)/4, 240.f*(i+1));
		button[i].setSize({360,120});
		button[i].setOrigin( button[i].getSize().x/2 , button[i].getSize().y / 2);
		button[i].setTexture(buttonTexture[i], 1);
	}
}

Menu::~Menu()
{
}

void Menu::openMenu()
{
	Menu* menu = new Menu();

	while (Window.isOpen() && menu->open)
	{
		while ( Window.pollEvent(GameEvent)) {
			switch (GameEvent.type)
			{
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					Window.close();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
					menu->open = false;
				}
				break;
			case sf::Event::MouseButtonPressed:
				menu->buttonEvents();
				break;
			default:
				break;
			}
		}

		Window.clear(sf::Color(63,63,63));

		menu->render();

		Window.display();
	}

	delete menu;

}
