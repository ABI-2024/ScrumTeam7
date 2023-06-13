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
				level->start(datafiles[i-1], progress);
				delete level;
				if (progress.status < Level_Progression::Level_1) {
					progress.status= Level_Progression::Level_1;
				}
				open = false;

				break;

			case 2:
				if (progress.status < Level_Progression::Level_1) {
					break;
				}
				level = new Level_2();
				level->start(datafiles[i-1], progress);
				delete level;
				if (progress.status < Level_Progression::Level_2) {
					progress.status = Level_Progression::Level_2;
				}
				open = false;
				break;

			case 3:
				if (progress.status < Level_Progression::Level_2) {
					break;
				}
				level = new Level_3();
				level->start(datafiles[i-1], progress);
				delete level;
				if (progress.status < Level_Progression::Level_3) {
					progress.status = Level_Progression::Level_3;
				}
				open = false;
				break;

			case 4:
				if (progress.status < Level_Progression::Level_3) {
				break;
				}
				level = new Level_Final();
				level->start(datafiles[i-1], progress);
				delete level;
				if (progress.status < Level_Progression::AllOnlocked) {
					progress.status = Level_Progression::AllOnlocked;
				}
				open = false;
				break;

			case 5:
				if (progress.status < Level_Progression::AllOnlocked) {
					break;
				}
				level = new Level_Endless();
				level->start(datafiles[i-1], progress);
				delete level;

				open = false;
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


	buttonTexture = new sf::Texture*[8];
	buttonTexture[0] = new sf::Texture[3];
	for(int i = 1 ; i < 8; i++)
		buttonTexture[i] = new sf::Texture();


	buttonTexture[0][0].loadFromFile("resource/Textures/Button_Side1.png");
	buttonTexture[0][1].loadFromFile("resource/Textures/Button_Middle.png");
	buttonTexture[0][2].loadFromFile("resource/Textures/Button_Side2.png");

	buttonTexture[1]->loadFromFile("resource/Textures/Level/Select/Select-Small-Complete.png");
	buttonTexture[2]->loadFromFile("resource/Textures/Level/Select/Select-Small-Uncomplete.png");
	buttonTexture[3]->loadFromFile("resource/Textures/Level/Select/Select-Small-Sperren.png");

	buttonTexture[4]->loadFromFile("resource/Textures/Level/Select/Select-Big-Complete.png");
	buttonTexture[5]->loadFromFile("resource/Textures/Level/Select/Select-Big-Uncomplete.png");
	buttonTexture[6]->loadFromFile("resource/Textures/Level/Select/Select-Big-Sperren.png");
	buttonTexture[7]->loadFromFile("resource/Textures/Level/Select/Select-Big-Special.png");


	buttons = new Button * [ButtonCount];
	
	float randAbstand = 50;
	buttons[0] = new Button(*font, sf::Color(34, 32, 52), buttonText[0], buttonTexture[0], {randAbstand+200, 800 }, { 400.f, 100.f }, false);

	for (int i = 1; i <= 3; i++) {
		if (this->progress.status > Level_Progression(i-1)) {
			buttons[i] = new Button(*font, sf::Color(34, 32, 52), buttonText[i], buttonTexture[1], { randAbstand + 130 + 200 + 420 * (i - 1), randAbstand + 180 }, { 400.f, 300.f }, true);
		}
		else if (this->progress.status == Level_Progression(i - 1)) {
			buttons[i] = new Button(*font, sf::Color(34, 32, 52), buttonText[i], buttonTexture[2], { randAbstand + 130 + 200 + 420 * (i - 1), randAbstand + 180 }, { 400.f, 300.f }, true);
		}
		else {
			buttons[i] = new Button(*font, sf::Color(34, 32, 52), buttonText[i], buttonTexture[3], { randAbstand + 130 + 200 + 420 * (i - 1), randAbstand + 180 }, { 400.f, 300.f }, true);
		}
	}

	if (this->progress.status > Level_Progression(4 - 1)) {
		buttons[4] = new Button(*font, sf::Color(34, 32, 52), buttonText[4], buttonTexture[4], { randAbstand + 130 + 300 + 640 * (4 - 4),randAbstand + 500 }, { 600.f, 300.f }, true);
	}
	else if (this->progress.status == Level_Progression(4 - 1)) {
		buttons[4] = new Button(*font, sf::Color(34, 32, 52), buttonText[4], buttonTexture[5], { randAbstand + 130 + 300 + 640 * (4 - 4),randAbstand + 500 }, { 600.f, 300.f }, true);
	}
	else {
		buttons[4] = new Button(*font, sf::Color(34, 32, 52), buttonText[4], buttonTexture[6], { randAbstand + 130 + 300 + 640 * (4 - 4),randAbstand + 500 }, { 600.f, 300.f }, true);
	}

	if (this->progress.status >= Level_Progression(5 - 1)) {
		buttons[5] = new Button(*font, sf::Color(34, 32, 52), buttonText[5], buttonTexture[7], { randAbstand + 130 + 300 + 640 * (5 - 4),randAbstand + 500 }, { 600.f, 300.f }, true);
	}
	else {
		buttons[5] = new Button(*font, sf::Color(34, 32, 52), buttonText[5], buttonTexture[6], { randAbstand + 130 + 300 + 640 * (5 - 4),randAbstand + 500 }, { 600.f, 300.f }, true);
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
				if (!open) {
					return;
				}
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
