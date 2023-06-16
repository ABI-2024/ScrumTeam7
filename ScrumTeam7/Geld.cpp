#include "Geld.h"
#include "Window.h"

using namespace std;

int Geld::Startgeld = 500;
Geld::Geld() {
	Kontostand = Startgeld;
	font.loadFromFile("resource/fonts/arial.ttf");
	text.setFont(font);
	text.setCharacterSize(20);
	text.setPosition(1500, 30);
	text.setFillColor(sf::Color::White);

	texture.loadFromFile("resource/Textures/Geld.png");

	body.setPosition(1510, 35);
	body.setSize( sf::Vector2f(23.f, 9.f ) * 3.f );
	body.setOrigin(0 , body.getSize().y/2);
	body.setTexture(&texture ,0);

}

Geld::~Geld(){}

int Geld::getKontostand() {
	return Kontostand;
}

void Geld::addKontostand(int betrag) {
	Kontostand += betrag;
}

void Geld::subKontostand(int betrag) {
	Kontostand -= betrag;
}

void Geld::clearKontostand (){
	Kontostand = 0;
}

void Geld::render()
{
	text.setString(std::to_string( Kontostand));
	text.setOrigin(text.getGlobalBounds().width, text.getGlobalBounds().height / 2);
	Window.draw(text);
	Window.draw(body);
}