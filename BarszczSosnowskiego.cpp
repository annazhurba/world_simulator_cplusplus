#pragma once
#include <iostream>
#include <string>
#include "Naglowki.h"

BarszczSosnowskiego::BarszczSosnowskiego() {

}

BarszczSosnowskiego::BarszczSosnowskiego(int y, int x, Swiat* swiat) {
	this->setY(y);
	this->setX(x);
	this->setSila(10);
	this->setInicjatywa(0);
	this->setWiek(0);
	this->setGatunek("BarszczSosnowskiego");
	this->setRodzaj("Roslina");
	this->setZnaczek('b');
	this->setSwiat(swiat);
}

void BarszczSosnowskiego::akcja() {
	int curr_x = this->getX();
	int curr_y = this->getY();
	if (this->getSwiat()->getMapa().mapa[curr_y][curr_x - 1] != this->getSwiat()->pustosc) {
		for (int i = 0; i < this->getSwiat()->getN() * this->getSwiat()->getM(); i++) {
			if (this->getSwiat()->getZwierzeta()[i] != NULL && this->getSwiat()->getZwierzeta()[i]->getX() == curr_x - 1 && this->getSwiat()->getZwierzeta()[i]->getY() == curr_y) {
				this->getSwiat()->getZwierzeta()[i]->setZyje(false);
				this->getSwiat()->setEvents(this->getSwiat()->getEvents() + this->getGatunek() + " zabija " + this->getSwiat()->getZwierzeta()[i]->getGatunek() + "\n");
				this->getSwiat()->getZwierzeta()[i] = NULL;
				break;
			}
		}
	}
	else if (this->getSwiat()->getMapa().mapa[curr_y][curr_x + 1] != this->getSwiat()->pustosc) {
		for (int i = 0; i < this->getSwiat()->getN() * this->getSwiat()->getM(); i++) {
			if (this->getSwiat()->getZwierzeta()[i] != NULL && this->getSwiat()->getZwierzeta()[i]->getX() == curr_x + 1 && this->getSwiat()->getZwierzeta()[i]->getY() == curr_y) {
				this->getSwiat()->getZwierzeta()[i]->setZyje(false);
				this->getSwiat()->setEvents(this->getSwiat()->getEvents() + this->getGatunek() + " zabija " + this->getSwiat()->getZwierzeta()[i]->getGatunek() + "\n");
				this->getSwiat()->getZwierzeta()[i] = NULL;
				break;
			}
		}
	}
	else if (this->getSwiat()->getMapa().mapa[curr_y - 1][curr_x] != this->getSwiat()->pustosc) {
		for (int i = 0; i < this->getSwiat()->getN() * this->getSwiat()->getM(); i++) {
			if (this->getSwiat()->getZwierzeta()[i] != NULL && this->getSwiat()->getZwierzeta()[i]->getX() == curr_x && this->getSwiat()->getZwierzeta()[i]->getY() == curr_y - 1) {
				this->getSwiat()->getZwierzeta()[i]->setZyje(false);
				this->getSwiat()->setEvents(this->getSwiat()->getEvents() + this->getGatunek() + " zabija " + this->getSwiat()->getZwierzeta()[i]->getGatunek() + "\n");
				this->getSwiat()->getZwierzeta()[i] = NULL;
				break;
			}
		}
	}
	else if (this->getSwiat()->getMapa().mapa[curr_y + 1][curr_x] != this->getSwiat()->pustosc) {
		for (int i = 0; i < this->getSwiat()->getN() * this->getSwiat()->getM(); i++) {
			if (this->getSwiat()->getZwierzeta()[i] != NULL && this->getSwiat()->getZwierzeta()[i]->getX() == curr_x && this->getSwiat()->getZwierzeta()[i]->getY() == curr_y + 1) {
				this->getSwiat()->getZwierzeta()[i]->setZyje(false);
				this->getSwiat()->setEvents(this->getSwiat()->getEvents() + this->getGatunek() + " zabija " + this->getSwiat()->getZwierzeta()[i]->getGatunek() + "\n");
				this->getSwiat()->getZwierzeta()[i] = NULL;
				break;
			}
		}
	}
	else if (this->getSwiat()->getMapa().mapa[curr_y - 1][curr_x - 1] != this->getSwiat()->pustosc) {
		for (int i = 0; i < this->getSwiat()->getN() * this->getSwiat()->getM(); i++) {
			if (this->getSwiat()->getZwierzeta()[i] != NULL && this->getSwiat()->getZwierzeta()[i]->getX() == curr_x - 1 && this->getSwiat()->getZwierzeta()[i]->getY() == curr_y - 1) {
				this->getSwiat()->getZwierzeta()[i]->setZyje(false);
				this->getSwiat()->setEvents(this->getSwiat()->getEvents() + this->getGatunek() + " zabija " + this->getSwiat()->getZwierzeta()[i]->getGatunek() + "\n");
				this->getSwiat()->getZwierzeta()[i] = NULL;
				break;
			}
		}
	}
	else if (this->getSwiat()->getMapa().mapa[curr_y + 1][curr_x - 1] != this->getSwiat()->pustosc) {
		for (int i = 0; i < this->getSwiat()->getN() * this->getSwiat()->getM(); i++) {
			if (this->getSwiat()->getZwierzeta()[i] != NULL && this->getSwiat()->getZwierzeta()[i]->getX() == curr_x - 1 && this->getSwiat()->getZwierzeta()[i]->getY() == curr_y + 1) {
				this->kolizja(curr_y + 1, curr_x - 1, this->getSwiat()->getZwierzeta()[i]);
				break;
			}
		}
	}
	else if (this->getSwiat()->getMapa().mapa[curr_y - 1][curr_x + 1] != this->getSwiat()->pustosc) {
		for (int i = 0; i < this->getSwiat()->getN() * this->getSwiat()->getM(); i++) {
			if (this->getSwiat()->getZwierzeta()[i] != NULL && this->getSwiat()->getZwierzeta()[i]->getX() == curr_x + 1 && this->getSwiat()->getZwierzeta()[i]->getY() == curr_y - 1) {
				this->getSwiat()->getZwierzeta()[i]->setZyje(false);
				this->getSwiat()->setEvents(this->getSwiat()->getEvents() + this->getGatunek() + " zabija " + this->getSwiat()->getZwierzeta()[i]->getGatunek() + "\n");
				this->getSwiat()->getZwierzeta()[i] = NULL;
				break;
			}
		}
	}
	else if (this->getSwiat()->getMapa().mapa[curr_y + 1][curr_x + 1] != this->getSwiat()->pustosc) {
		for (int i = 0; i < this->getSwiat()->getN() * this->getSwiat()->getM(); i++) {
			if (this->getSwiat()->getZwierzeta()[i] != NULL && this->getSwiat()->getZwierzeta()[i]->getX() == curr_x + 1 && this->getSwiat()->getZwierzeta()[i]->getY() == curr_y + 1) {
				this->getSwiat()->getZwierzeta()[i]->setZyje(false);
				this->getSwiat()->setEvents(this->getSwiat()->getEvents() + this->getGatunek() + " zabija " + this->getSwiat()->getZwierzeta()[i]->getGatunek() + "\n");
				this->getSwiat()->getZwierzeta()[i] = NULL;
				break;
			}
		}
	}

	int szansa = rand() % 10;
	if (szansa == 0 || szansa == 1 || szansa == 2) {
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
				Roslina* new_roslina = new BarszczSosnowskiego(curr_y + i, curr_x + j, this->getSwiat());
				this->getSwiat()->getRosliny()[d] = new_roslina;
				this->getSwiat()->getMapa().mapa[curr_y + i][curr_x + j] = new_roslina->getZnaczek();
				this->getSwiat()->setEvents(this->getSwiat()->getEvents() + "Wyrosla nowa roslina: " + this->getSwiat()->getRosliny()[d]->getGatunek()  );
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
		else {
			this->akcja();
		}
	}
}

void BarszczSosnowskiego::kolizja(int opp_y, int opp_x, Zwierze* napastnik) {
	this->getSwiat()->getMapa().mapa[opp_y][opp_x] = this->getSwiat()->pustosc;
	napastnik->setZyje(false);
	this->getSwiat()->setEvents(this->getSwiat()->getEvents() + this->getGatunek() + " zabija " + napastnik->getGatunek() + "\n");
	napastnik = NULL;
}

BarszczSosnowskiego::~BarszczSosnowskiego() {

}