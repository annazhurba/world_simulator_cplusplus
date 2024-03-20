#pragma once
#include <iostream>
#include <string>
#include "Naglowki.h"

Lis::Lis() {

}

Lis::Lis(int y, int x, Swiat* swiat) {
	this->setY(y);
	this->setX(x);
	this->setSila(3);
	this->setInicjatywa(7);
	this->setWiek(0);
	this->setGatunek("Lis");
	this->setRodzaj("Zwierze");
	this->setZnaczek('L');
	this->setSwiat(swiat);
}

void Lis::akcja() {
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
			this->setX(curr_x + j);
			this->setY(curr_y + i);
			this->getSwiat()->getMapa().mapa[curr_y][curr_x] = this->getSwiat()->pustosc;
			this->getSwiat()->getMapa().mapa[curr_y + i][curr_x + j] = this->getZnaczek();
		}
		else {
			for (int iter = 0; iter < this->getSwiat()->getN() * this->getSwiat()->getM(); iter++) {
				if (this->getSwiat()->getZwierzeta()[iter] != NULL) {
					if (this->getSwiat()->getZwierzeta()[iter]->getX() == curr_x + j && this->getSwiat()->getZwierzeta()[iter]->getY() == curr_y + i) {
						if (this->getSwiat()->getZwierzeta()[iter]->getSila() > this->getSila()) {
							this->getSwiat()->setEvents(this->getGatunek() + " nie rusza sie na pole " + this->getSwiat()->getZwierzeta()[iter]->getGatunek() + "\n");
							this->akcja();
						}
						else {
							this->getSwiat()->getZwierzeta()[iter]->kolizja(curr_y + i, curr_x + j, this);
							return;
						}
					}
				}
				if (this->getSwiat()->getRosliny()[iter] != NULL) {
					if (this->getSwiat()->getRosliny()[iter]->getX() == curr_x + j && this->getSwiat()->getRosliny()[iter]->getY() == curr_y + i) {
						this->getSwiat()->getRosliny()[iter]->kolizja(curr_y + i, curr_x + j, this);
						return;
					}
				}
			}
		}
	}
}

Lis::~Lis() {

}