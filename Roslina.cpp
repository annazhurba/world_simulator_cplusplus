#pragma once
#include <iostream>
#include "Naglowki.h"

void Roslina::akcja() {
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
				if (this->getGatunek() == "Trawa") {
					Roslina* new_roslina = new Trawa(curr_y + i, curr_x + j, this->getSwiat());
					this->getSwiat()->getRosliny()[d] = new_roslina;
					this->getSwiat()->getMapa().mapa[curr_y + i][curr_x + j] = new_roslina->getZnaczek();
				}
				else if (this->getGatunek() == "Mlecz") {
					Roslina* new_roslina = new Mlecz(curr_y + i, curr_x + j, this->getSwiat());
					this->getSwiat()->getRosliny()[d] = new_roslina;
					this->getSwiat()->getMapa().mapa[curr_y + i][curr_x + j] = new_roslina->getZnaczek();
				}
				else if (this->getGatunek() == "Guarana") {
					Roslina* new_roslina = new Guarana(curr_y + i, curr_x + j, this->getSwiat());
					this->getSwiat()->getRosliny()[d] = new_roslina;
					this->getSwiat()->getMapa().mapa[curr_y + i][curr_x + j] = new_roslina->getZnaczek();
				}
				else if (this->getGatunek() == "WilczeJagody") {
					Roslina* new_roslina = new WilczeJagody(curr_y + i, curr_x + j, this->getSwiat());
					this->getSwiat()->getRosliny()[d] = new_roslina;
					this->getSwiat()->getMapa().mapa[curr_y + i][curr_x + j] = new_roslina->getZnaczek();
				}
				else if (this->getGatunek() == "BarszczSosnowskiego") {
					Roslina* new_roslina = new BarszczSosnowskiego(curr_y + i, curr_x + j, this->getSwiat());
					this->getSwiat()->getRosliny()[d] = new_roslina;
					this->getSwiat()->getMapa().mapa[curr_y + i][curr_x + j] = new_roslina->getZnaczek();
				}
				this->getSwiat()->setEvents(this->getSwiat()->getEvents() + "Wyrosla nowa roslina: " + this->getSwiat()->getRosliny()[d]->getGatunek() + "\n");
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

void Roslina::kolizja(int opp_y, int opp_x, Zwierze* napastnik){
	int lp = -1;
	for (int i = 0; i < this->getSwiat()->getN(); i++) {
		if (this->getSwiat()->getZwierzeta()[i] != NULL && this->getSwiat()->getZwierzeta()[i]->getY() == napastnik->getY() && this->getSwiat()->getZwierzeta()[i]->getX() == napastnik->getX()) {
			lp = i;
			break;
		}
	}
	this->getSwiat()->getMapa().mapa[napastnik->getY()][napastnik->getX()] = this->getSwiat()->pustosc;
	this->getSwiat()->getMapa().mapa[this->getY()][this->getX()] = napastnik->getZnaczek();
	this->getSwiat()->getZwierzeta()[lp]->setX(this->getX());
	this->getSwiat()->getZwierzeta()[lp]->setY(this->getY());
	this->getSwiat()->setEvents(this->getSwiat()->getEvents() + napastnik->getGatunek() + " zjada " + this->getGatunek() + "\n");
	this->setZyje(false);
	for (int i = 0; i < this->getSwiat()->getN(); i++) {
		if (this->getSwiat()->getRosliny()[i] != NULL && this->getSwiat()->getRosliny()[i]->getY() == this->getY() && this->getSwiat()->getRosliny()[i]->getX() == this->getX()) {
			this->getSwiat()->getRosliny()[i] = NULL;
			break;
		}
	}
}


Roslina::~Roslina() {

}