#pragma once
#include <iostream>
#include <string>
#include "Naglowki.h"

using namespace std;

void Zwierze::akcja() {
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
	else {
		this->akcja();
	}
}

void Zwierze::kolizja(int opp_y, int opp_x, Zwierze* napastnik) {
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
		if (new_y >= 0 && new_y < this->getSwiat()->getN() && new_x >= 0 && new_x < this->getSwiat()->getM()
			&& this->getSwiat()->getMapa().mapa[new_y][new_x] == this->getSwiat()->pustosc) {
			if (this->getGatunek() == "Wilk") {
				this->getSwiat()->getZwierzeta()[j] = new Wilk(new_y, new_x, this->getSwiat());
				this->getSwiat()->getMapa().mapa[new_y][new_x] = this->getSwiat()->getZwierzeta()[j]->getZnaczek();
			}
			else if (this->getGatunek() == "Owca") {
				this->getSwiat()->getZwierzeta()[j] = new Owca(new_y, new_x, this->getSwiat());
				this->getSwiat()->getMapa().mapa[new_y][new_x] = this->getSwiat()->getZwierzeta()[j]->getZnaczek();
			}
			else if (this->getGatunek() == "Lis") {
				this->getSwiat()->getZwierzeta()[j] = new Lis(new_y, new_x, this->getSwiat());
				this->getSwiat()->getMapa().mapa[new_y][new_x] = this->getSwiat()->getZwierzeta()[j]->getZnaczek();
			}
			else if (this->getGatunek() == "Zolw") {
				this->getSwiat()->getZwierzeta()[j] = new Zolw(new_y, new_x, this->getSwiat());
				this->getSwiat()->getMapa().mapa[new_y][new_x] = this->getSwiat()->getZwierzeta()[j]->getZnaczek();
			}
			else if (this->getGatunek() == "Antylopa") {
				this->getSwiat()->getZwierzeta()[j] = new Antylopa(new_y, new_x, this->getSwiat());
				this->getSwiat()->getMapa().mapa[new_y][new_x] = this->getSwiat()->getZwierzeta()[j]->getZnaczek();
			}
			this->getSwiat()->setEvents(this->getSwiat()->getEvents() + "Urodzilo sie nowe zwierze: " + this->getSwiat()->getZwierzeta()[j]->getGatunek() + "\n");
		}
		return;
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
		}
	}
}

Zwierze::~Zwierze() {
	
}