#include "Level_Selector.h"

#include "Level_1.h"
#include "Level_2.h"
#include "Level_3.h"
#include "Level_Final.h"
#include "Level_Endless.h"

#define LevelButtonCount 5
#define ButtonCount 1 + LevelButtonCount

void Level_Selector::buttonEvents()
{
	Level* level = nullptr;

	for (int i = 0; i < ButtonCount; i++) {
		if (buttons[i]->isHovered()) {
			switch (i) {
			case 0:
				this->open = false;
				break;

			case 1:
				level = new Level_1();
				level->start(datafiles[i-1]);
				delete level;
				break;

			case 2:
				level = new Level_2();
				level->start(datafiles[i-1]);
				delete level;
				break;

			case 3:
				level = new Level_3();
				level->start(datafiles[i-1]);
				delete level;
				break;

			case 4:
				level = new Level_Final();
				level->start(datafiles[i-1]);
				delete level;
				break;

			case 5:
				level = new Level_Endless();
				level->start(datafiles[i]);
				delete level;
				break;

			default:
				break;
			}
		}
	}

}

void Level_Selector::render()
{
	for (int i = 0; i < ButtonCount; i++) {
		buttons[i]->render();
	}

}

Level_Selector::Level_Selector()
	:open(true)
{


	datafiles = new std::string[LevelButtonCount];

	datafiles[0] = "resource/Data/Level_1.csv";
	datafiles[1] = "resource/Data/Level_2.csv";
	datafiles[2] = "resource/Data/Level_3.csv";
	datafiles[3] = "resource/Data/Level_Final.csv";
	datafiles[4] = "Datenwellen.csv";


	font = new sf::Font();
	font->loadFromFile("resource/fonts/Broken Console Bold.otf");

	buttonText = new std::string[ButtonCount];
	buttonText[0] = "Zurück";
	buttonText[1] = "1";
	buttonText[2] = "2";
	buttonText[3] = "3";
	buttonText[4] = "";
	buttonText[5] = "";


	buttonTexture = new sf::Texture*[ButtonCount];
	buttonTexture[0] = new sf::Texture[3];
	for(int i = 1 ; i < ButtonCount; i++)
		buttonTexture[i] = new sf::Texture();


	buttonTexture[0][0].loadFromFile("resource/Textures/Button_Side1.png");
	buttonTexture[0][1].loadFromFile("resource/Textures/Button_Middle.png");
	buttonTexture[0][2].loadFromFile("resource/Textures/Button_Side2.png");

	buttonTexture[1]->loadFromFile("resource/Textures/Level/Select/Select-Small-Uncomplete.png");
	buttonTexture[2]->loadFromFile("resource/Textures/Level/Select/Select-Small-Uncomplete.png");
	buttonTexture[3]->loadFromFile("resource/Textures/Level/Select/Select-Small-Uncomplete.png");
	buttonTexture[4]->loadFromFile("resource/Textures/Level/Select/Select-Big-Sperren.png");
	buttonTexture[5]->loadFromFile("resource/Textures/Level/Select/Select-Big-Special.png");


	buttons = new Button * [ButtonCount];
	
	float randAbstand = 50;
	buttons[0] = new Button(*font, sf::Color(34, 32, 52), buttonText[0], buttonTexture[0], {randAbstand+200, 800 }, { 400.f, 100.f }, false);

	for (int i = 1; i <= 3; i++) {
		buttons[i] = new Button(*font, sf::Color(34, 32, 52), buttonText[i], buttonTexture[i], { randAbstand+130 + 200 + 420 * (i - 1), randAbstand + 180 }, { 400.f, 300.f }, true);
	}
	for (int i = 4; i <= 5; i++) {
		buttons[i] = new Button(*font, sf::Color(34, 32, 52), buttonText[i], buttonTexture[i], { randAbstand+130 + 300 + 640 * (i - 4),randAbstand + 500 }, { 600.f, 300.f }, true);
	}
}

Level_Selector::~Level_Selector()
{

	delete[] datafiles;
	delete font;

	delete[] buttonTexture[0];
	for (int i = 1; i < ButtonCount; i++)
		delete buttonTexture[i];

	delete[] buttonTexture;


	delete[] buttonText;
	for (int i = 0; i < ButtonCount; i++)
		delete buttons[i];

	delete[] buttons;

}

void Level_Selector::openMenu()
{
	sf::Texture* background_Texture = new sf::Texture();
	background_Texture->loadFromFile("resource/Textures/Menu_Options.png");

	sf::RectangleShape background;
	background.setPosition(0, 0);
	background.setSize(GameWindow::getMainView().getSize());
	background.setTexture(background_Texture, 0);


	while (Window.isOpen() && open)
	{
		while (Window.pollEvent(GameEvent)) {
			switch (GameEvent.type)
			{

			case sf::Event::Closed:
				GameWindow::getWindow().close();
				break;

			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					open = false;
				}
				break;

			case sf::Event::MouseButtonPressed:
				buttonEvents();
				break;

			default:
				break;
			}
		}

		for (int i = 0; i < ButtonCount; i++) {

			buttons[i]->update();

		}

		Window.clear();

		Window.setView(GameWindow::getMainView());

		Window.draw(background);
		render();

		Window.display();
	}
}
