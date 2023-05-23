#include "TowerSelect.h"
#include "Window.h"

int TowerSelect::anzahlKarten = 6;
int TowerSelect::anzGewKarten = 0;

void TowerSelect::buttonEvents()
{
	bool exist = false;
	// Karte ausw�hlen
	for (int i = 0; i < anzahlKarten; i++) {
		if (karten[i]->getHovered()) {

			for (int j = 0; j < anzGewKarten; j++) {
				if (gewKarten[j] == karten[i]) {
					exist = true;
				}
			}
			if (!exist) {
				// Karte zu gew Karten hinzuf�gen
				gewKarten[anzGewKarten] = karten[i];
				// Karte als gew Karte anzeigen (linker rand)
				karten[i]->setPosition({ 60.f, 150.f * anzGewKarten + 90 });

				anzGewKarten++;
			}
		}
	}
}

void TowerSelect::render()
{
	for (int i = 0; i < anzahlKarten; i++) {

		if (karten[i]->getHovered()) {
			this->R�ckseite.setPosition(karten[i]->getPosition());
			this->R�ckseite.setFillColor(sf::Color::White);
			this->R�ckseite.setTexture(&tb[i], 0);
		}
		//else {
		//	this->R�ckseite.setFillColor(sf::Color::Transparent);
		//}

		GameWindow::getWindow().draw(this->R�ckseite);

		karten[i]->render();
	}

}


TowerSelect::TowerSelect()
{
	this->open = true;


	// Texturen f�r die Voderseite der Karten
	t = new sf::Texture[6];
	t[0].loadFromFile("resource/Textures/Lehrer/Karten/Karte_MA_Front.png");
	t[1].loadFromFile("resource/Textures/Lehrer/Karten/Karte_INF_Front.png");
	t[2].loadFromFile("resource/Textures/Lehrer/Karten/Karte_EN_Front.png");
	t[3].loadFromFile("resource/Textures/Lehrer/Karten/Karte_DE_Front.png");
	t[4].loadFromFile("resource/Textures/Lehrer/Karten/Karte_SP_Front.png");
	t[5].loadFromFile("resource/Textures/Lehrer/Karten/Karte_METAL_Front.png");

	// Texturen f�r die R�ckseite der Karten
	tb = new sf::Texture[6];
	tb[0].loadFromFile("resource/Textures/Basketball.png");
	tb[1].loadFromFile("resource/Textures/Basketball.png");
	tb[2].loadFromFile("resource/Textures/Basketball.png");
	tb[3].loadFromFile("resource/Textures/Basketball.png");
	tb[4].loadFromFile("resource/Textures/Basketball.png");
	tb[5].loadFromFile("resource/Textures/Basketball.png");

	sf::Vector2f size = { 210.f , 140.f };
	this->R�ckseite.setSize(size);
	this->R�ckseite.setFillColor(sf::Color::Transparent);


	karten = new Karte * [anzahlKarten];

	this->karten[0] = new Karte(100, TowerType::Mathelehrer, &t[0], { 220.f * 0 + 600, 100.f });
	this->karten[1] = new Karte(100, TowerType::INF_Lehrer, &t[1], { 220.f * 1 + 600, 100.f });
	this->karten[2] = new Karte(100, TowerType::EN_Lehrer, &t[2], { 220.f * 2 + 600, 100.f });
	this->karten[3] = new Karte(100, TowerType::DE_Lehrer, &t[3], { 220.f * 3 + 600, 100.f });

	this->karten[4] = new Karte(100, TowerType::TestTower, &t[4], { 220.f * 0 + 600, 250.f });
	this->karten[5] = new Karte(100, TowerType::METAL_Lehrer, &t[5], { 220.f * 1 + 600, 250.f });

	

}

TowerSelect::~TowerSelect()
{

}


Karte** TowerSelect::openTowerSelect()
{
	TowerSelect TowerSelect;
	
	// "array" f�r gew�hlte Karten
	TowerSelect.gewKarten = new Karte * [5];


	// erzeugt Hintergrundbild
	sf::Texture* background_Texture = new sf::Texture();
	background_Texture->loadFromFile("resource/Textures/Menu_Options.png");

	sf::RectangleShape background;
	background.setPosition(0, 0);
	background.setSize(GameWindow::getMainView().getSize());
	background.setTexture(background_Texture, 0);


	while (Window.isOpen() && TowerSelect.open)
	{
		while (Window.pollEvent(GameEvent)) {
			switch (GameEvent.type)
			{

			case sf::Event::Closed:
				GameWindow::getWindow().close();
				break;

			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					TowerSelect.open = false;
				}
				break;

			case sf::Event::MouseButtonPressed:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

					TowerSelect.buttonEvents();

				}
				//if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {

				//}

			default:
				break;
			}
		}

		Window.clear();

		Window.setView(GameWindow::getMainView());

		Window.draw(background);
		TowerSelect.render();

		Window.display();

		//abbruch-bedingung
		if (anzGewKarten >= 5) break;
	}

	return TowerSelect.gewKarten;
}