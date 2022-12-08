#include "Menu_Options.h"

#define Anzahl_Button 3

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
	for (int i = 0; i < Anzahl_Button; i++) {
		button->render();
	}
}
