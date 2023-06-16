#include "Menu_Options.h"

#include "Music.h"

#define Anzahl_Button 7

Menu_Options::Menu_Options() {
	this->open = true;

	// Hintergrundtextur
	backgroundTexture = new sf::Texture();
	backgroundTexture->loadFromFile("resource/Textures/Menu_Options.png");

	// Hintergrund
	background.setPosition(0, 0);
	background.setSize(sf::Vector2f(GameWindow::getMainView().getSize()));
	background.setTexture(backgroundTexture, 0);

	// Font
	font.loadFromFile("resource/fonts/Broken Console Bold.otf");

	// Button-Texture
	buttonTexture = new sf::Texture[3];
	buttonTexture[0].loadFromFile("resource/Textures/Button_Side1.png");
	buttonTexture[1].loadFromFile("resource/Textures/Button_Middle.png");
	buttonTexture[2].loadFromFile("resource/Textures/Button_Side2.png");

	settings = *GameWindow::getSettings(); // Aktuelle Settings

	// Erstelle Buttons
	buttonText = new std::string[Anzahl_Button];
	if (settings.Fullscreen) {
		buttonText[0] = "Auflösung: Fullscreen";
	}
	else {
		buttonText[0] = "Auflösung: " + std::to_string(settings.WindowSize.x) + " / " + std::to_string(settings.WindowSize.y);
	}
	buttonText[1] = "Fps-Limit: " + std::to_string(settings.FrameRateLimit);
	buttonText[2] = "Master Volume: " + std::to_string(settings.MasterVolume) + "%";
	buttonText[3] = "Sound Volume: " + std::to_string(settings.SoundVolume) + "%";
	buttonText[4] = "Music Volume: " + std::to_string(settings.MusicVolume) + "%";

	button = new Button*[Anzahl_Button];
	for (int i = 0; i < 5; i++) {
		button[i] = new Button(font, sf::Color(34, 32, 52), buttonText[i], buttonTexture, { GameWindow::getMainView().getSize().x/2  , 160.f + 130.f * i }, { 800.f, 120.f }, false);
	}
	button[5] = new Button(font, sf::Color(34, 32, 52), "Zurück", buttonTexture, {GameWindow::getMainView().getSize().x /8  , GameWindow::getMainView().getSize().y * 15 / 16 }, {400.f, 100.f}, false);
	button[6] = new Button(font, sf::Color(34, 32, 52), "Übernehmen", buttonTexture, {GameWindow::getMainView().getSize().x * 7/ 8  , GameWindow::getMainView().getSize().y * 15 / 16 }, {400.f, 100.f}, false);

	// Voreingestellte Fenstergrößen
	aufloesung[0] = { 0, 0 };			// Fullscreen
	aufloesung[1] = { 960, 540 };
	aufloesung[2] = { 1280, 720 };
	aufloesung[3] = { 1440, 810 };
	aufloesung[4] = { 1600, 900 };
	aufloesung[5] = { 1920, 1080 };

}

Menu_Options::~Menu_Options()
{
	// lösche alle mit [new] erstellten Dinge
	delete[] buttonText;
	delete[] buttonTexture;


	for (int i = 0; i < Anzahl_Button; i++)
		delete button[i];

	delete[] button;
}

void Menu_Options::buttonEvents()
{
	// Abfrage der Buttons 
	for (int i = 0; i < Anzahl_Button; i++) {
		if (button[i]->isHovered()) {
			switch (i) {
			case 0:
				// Fenstergröße
				for (int i = 1; i < 6; i++) {
					if (settings.WindowSize == aufloesung[5]) {
						settings.WindowSize = aufloesung[0];
						settings.Fullscreen = true;
						break;
					}
					if (settings.WindowSize == aufloesung[i-1]) {
						settings.WindowSize = aufloesung[i];
						settings.Fullscreen = false;
						break;
					}
				}

				if (settings.Fullscreen) {
					button[0]->setText( "Auflösung: Fullscreen" );
				}
				else {
					button[0]->setText("Auflösung: " + std::to_string(settings.WindowSize.x) + " / " + std::to_string(settings.WindowSize.y));
				}

				break;
			case 1:
				// Frameratelimit
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					if (settings.FrameRateLimit > 30) {
						settings.FrameRateLimit -= 10;
					}
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
					if (settings.FrameRateLimit < 240) {
						settings.FrameRateLimit += 10;
					}
				}
				button[1]->setText( "Fps-Limit: " + std::to_string(settings.FrameRateLimit));
				break;
			case 2:
				// Lautstärke Master
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					if (settings.MasterVolume > 0) {
						settings.MasterVolume -= 10;
					}
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
					if (settings.MasterVolume < 100) {
						settings.MasterVolume += 10;
					}
				}
				button[2]->setText("Master Volume: " + std::to_string(settings.MasterVolume) + "%");
				break;
			case 3:
				// Lautstärke Sound
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					if (settings.SoundVolume > 0) {
						settings.SoundVolume -= 10;
					}
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
					if (settings.SoundVolume < 100) {
						settings.SoundVolume += 10;
					}
				}
				button[3]->setText("Sound Volume: " + std::to_string(settings.SoundVolume) + "%");
				break;
			case 4:
				// Lautstärke Music
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					if (settings.MusicVolume > 0) {
						settings.MusicVolume -= 10;
					}
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
					if (settings.MusicVolume < 100) {
						settings.MusicVolume += 10;
					}
				}
				button[4]->setText("Music Volume: " + std::to_string(settings.MusicVolume) + "%");
				break;
			case 5:
				// Zurück
				this->open = false;
				break;
			case 6:
				// Übernehme Settings
				GameWindow::setSettings(settings);
				Music::setVolume();
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
		button[i]->update();
	}
}

void Menu_Options::render()
{
	Window.draw(background);
	for (int i = 0; i < Anzahl_Button; i++) {
		button[i]->render();
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
				Window.close();
				break;

			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					menu.open = false;
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

		Window.setView(GameWindow::getMainView());

		menu.render();

		Window.display();
	}
}
