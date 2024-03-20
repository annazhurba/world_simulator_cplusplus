#pragma once
#include <iostream>
#include "Naglowki.h"

Mlecz::Mlecz() {

}

Mlecz::Mlecz(int y, int x, Swiat* swiat) {
	this->setY(y);
	this->setX(x);
	this->setSila(0);
	this->setInicjatywa(0);
	this->setWiek(0);
	this->setGatunek("Mlecz");
	this->setRodzaj("Roslina");
	this->setZnaczek('m');
	this->setSwiat(swiat);
}

void Mlecz::akcja() {
	for (int i = 0; i < 3; i++) {
		int szansa = rand() % 10;
		if (szansa == 0 || szansa == 1) {
			int d = 0;
			while (this->getSwiat()->getRosliny()[d] != NULL) {
				d++;
			}
			int kier = rand() % 8;
			int curr_x = this->getX();
			int curr_y = this->getY();
			int i = 0, j = 0;
			switch (kier) {
			case LEWO:
				j--;
				break;
			case PRAWO:
				j++;
				break;
			case GORA:
				i--;
				break;
			case DOL:
				i++;
				break;
			case L_G:
				i--;
				j--;
				break;
			case L_D:
				i++;
				j--;
				break;
			case P_G:
				i--;
				j++;
				break;
			case P_D:
				i++;
				j++;
				break;
			}
			if (curr_y + i >= 0 && curr_y + i < this->getSwiat()->getN() && curr_x + j >= 0 && curr_x + j < this->getSwiat()->getM()) {
				if (this->getSwiat()->getMapa().mapa[curr_y + i][curr_x + j] == this->getSwiat()->pustosc) {
					Roslina* new_roslina = new Mlecz(curr_y + i, curr_x + j, this->getSwiat());
					this->getSwiat()->getRosliny()[d] = new_roslina;
					this->getSwiat()->getMapa().mapa[curr_y + i][curr_x + j] = new_roslina->getZnaczek();
					//this->getSwiat()->setEvents(this->getSwiat()->getEvents() + "Wyrosla nowa roslina: " + this->getSwiat()->getRosliny()[d]->getGatunek() + "\n");
				}
				else {
					for (int iter = 0; iter < this->getSwiat()->getN() * this->getSwiat()->getM(); iter++) {
						if (this->getSwiat()->getZwierzeta()[iter] != NULL) {
							if (this->getSwiat()->getZwierzeta()[iter]->getX() == curr_x + j && this->getSwiat()->getZwierzeta()[iter]->getY() == curr_y + i) {
								this->kolizja(curr_y + i, curr_x + j, this->getSwiat()->getZwierzeta()[iter]);
								return;
							}
						}
						if (this->getSwiat()->getRosliny()[iter] != NULL) {
							if (this->getSwiat()->getRosliny()[iter]->getX() == curr_x + j && this->getSwiat()->getRosliny()[iter]->getY() == curr_y + i) {
								return;
							}
						}
					}
				}
			}
		}
	}
}

Mlecz::~Mlecz() {

}