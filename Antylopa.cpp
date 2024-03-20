#pragma once
#include <iostream>
#include "Naglowki.h"

Antylopa::Antylopa() {
	
}

Antylopa::Antylopa(int y, int x, Swiat* swiat) {
	this->setY(y);
	this->setX(x);
	this->setSila(4);
	this->setInicjatywa(4);
	this->setWiek(0);
	this->setGatunek("Antylopa");
	this->setRodzaj("Zwierze");
	this->setZnaczek('A');
	this->setSwiat(swiat);
}

void Antylopa::akcja() {
	int kier = rand() % 8;
	int curr_x = this->getX();
	int curr_y = this->getY();
	int i = 0, j = 0;
	switch (kier) {
	case LEWO:
		j -= 2;
		break;
	case PRAWO:
		j += 2;
		break;
	case GORA:
		i -= 2;
		break;
	case DOL:
		i += 2;
		break;
	case L_G:
		i -= 2;
		j -= 2;
		break;
	case L_D:
		i += 2;
		j -= 2;
		break;
	case P_G:
		i -= 2;
		j += 2;
		break;
	case P_D:
		i += 2;
		j += 2;
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
						this->getSwiat()->getZwierzeta()[iter]->kolizja(curr_y + i, curr_x + j, this);
						return;
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

void Antylopa::kolizja(int opp_y, int opp_x, Zwierze* napastnik) {
	if (this->getGatunek() == napastnik->getGatunek()) {
		//stworz nowego zwierzaka
		int j = 0;
		while (this->getSwiat()->getZwierzeta()[j] != NULL) {
			j++;
		}

		int new_y = -1, new_x = -1;
		int k = 0, d = 0;

		if (opp_y != 0 && this->getSwiat()->getMapa().mapa[opp_y - 1][opp_x] == this->getSwiat()->pustosc) {
			k--;
		}
		else if (opp_y != this->getSwiat()->getN() - 1 && this->getSwiat()->getMapa().mapa[opp_y + 1][opp_x] == this->getSwiat()->pustosc) {
			k++;
		}
		else if (opp_x != 0 && this->getSwiat()->getMapa().mapa[opp_y][opp_x - 1] != this->getSwiat()->pustosc) {
			d--;
		}
		else if (opp_x != this->getSwiat()->getM() - 1 && this->getSwiat()->getMapa().mapa[opp_y][opp_x + 1] == this->getSwiat()->pustosc) {
			d++;
		}
		new_y = opp_y + k;
		new_x = opp_x + d;
		if (new_y >= 0 && new_y < this->getSwiat()->getN() && new_x >= 0 && new_x + j < this->getSwiat()->getM() 
			&& this->getSwiat()->getMapa().mapa[new_y][new_x] == this->getSwiat()->pustosc) {
			this->getSwiat()->getZwierzeta()[j] = new Antylopa(new_y, new_x, this->getSwiat());
			this->getSwiat()->getMapa().mapa[new_y][new_x] = this->getSwiat()->getZwierzeta()[j]->getZnaczek();
			this->getSwiat()->setEvents(this->getSwiat()->getEvents() + "Urodzil sie nowy organizm: " + this->getSwiat()->getZwierzeta()[j]->getGatunek() + "\n");
		}
	}
	else {
		int szansa = rand() % 4;
		if (szansa == 0 || szansa == 1) {

			int new_y = -1, new_x = -1;
			int k = 0, d = 0;
			if (opp_y != 0 && this->getSwiat()->getMapa().mapa[opp_y - 1][opp_x] == this->getSwiat()->pustosc) {
				k--;
			}
			else if (opp_y != this->getSwiat()->getN() - 1 && this->getSwiat()->getMapa().mapa[opp_y + 1][opp_x] == this->getSwiat()->pustosc) {
				k++;
			}
			else if (opp_x != 0 && this->getSwiat()->getMapa().mapa[opp_y][opp_x - 1] != this->getSwiat()->pustosc) {
				d--;
			}
			else if (opp_x != this->getSwiat()->getM() - 1 && this->getSwiat()->getMapa().mapa[opp_y][opp_x + 1] == this->getSwiat()->pustosc) {
				d++;
			}
			new_y = opp_y + k;
			new_x = opp_x + d;

			if (new_y >= 0 && new_y < this->getSwiat()->getN() && new_x >= 0 && new_x < this->getSwiat()->getM()) {
				this->getSwiat()->getMapa().mapa[this->getY()][this->getX()] = this->getSwiat()->pustosc;
				this->getSwiat()->getMapa().mapa[new_y][new_x] = this->getZnaczek();
				this->setX(new_x);
				this->setY(new_y);
				this->getSwiat()->getMapa().mapa[napastnik->getY()][napastnik->getX()] = this->getSwiat()->pustosc;
				this->getSwiat()->getMapa().mapa[opp_y][opp_x] = napastnik->getZnaczek();
				napastnik->setX(opp_x);
				napastnik->setY(opp_y);
				this->getSwiat()->setEvents(this->getSwiat()->getEvents() + this->getGatunek() + " ucieka przed walka z " + napastnik->getGatunek() + "\n");
				return;
			}
		}
		else {
			if (this->getSila() > napastnik->getSila()) {
				this->getSwiat()->setEvents(this->getSwiat()->getEvents() + this->getGatunek() + " zabija " + napastnik->getGatunek() + "\n");
				this->getSwiat()->getMapa().mapa[napastnik->getY()][napastnik->getX()] = this->getSwiat()->pustosc;
				napastnik->setZyje(false);
				napastnik = NULL;
			}
			else if (this->getSila() <= napastnik->getSila()) {
				//opponent wins
				this->getSwiat()->setEvents(this->getSwiat()->getEvents() + napastnik->getGatunek() + " zabija " + this->getGatunek() + "\n");

				this->getSwiat()->getMapa().mapa[opp_y][opp_x] = this->getSwiat()->pustosc;
				this->setZyje(false);
				for (int i = 0; i < this->getSwiat()->getN() * this->getSwiat()->getM(); i++) {
					if (this->getSwiat()->getZwierzeta()[i] != NULL && this->getSwiat()->getZwierzeta()[i]->getX() == this->getX() && this->getSwiat()->getZwierzeta()[i]->getY() == this->getY()) {
						this->getSwiat()->getZwierzeta()[i] = NULL;
						break;
					}
					if (this->getSwiat()->getRosliny()[i] != NULL && this->getSwiat()->getRosliny()[i]->getX() == this->getX() && this->getSwiat()->getRosliny()[i]->getY() == this->getY()) {
						this->getSwiat()->getRosliny()[i] = NULL;
						break;
					}

				}
				//cout << napastnik->getGatunek() << " jest napastnikiem i wygrywa" << endl;
			}
		}
	}
}

Antylopa::~Antylopa() {

}