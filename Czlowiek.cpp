#pragma once
#include <iostream>
#include "Naglowki.h"

Czlowiek::Czlowiek() {

}

Czlowiek::Czlowiek(int y, int x, Swiat* swiat) {
	this->setY(y);
	this->setX(x);
	this->setSila(5);
	this->setInicjatywa(4);
	this->setWiek(0);
	this->setGatunek("Czlowiek");
	this->setRodzaj("Zwierze");
	this->setSuperpowerTury(0);
	this->setZnaczek('C');
	this->setSwiat(swiat);
}

int Czlowiek::getSuperpowerTury() {
	return this->superpower_tury;
}

void Czlowiek::setSuperpowerTury(int liczba) {
	this->superpower_tury = liczba;
}

void Czlowiek::akcja() {
	if (this->getSuperpowerTury() > 0 && this->getSuperpowerTury() <= 5) {
		this->setSuperpowerTury(this->getSuperpowerTury() + 1);
		this->getSwiat()->setEvents(this->getSwiat()->getEvents() + "Specjalna umiejetnosc Czlowieka jest aktywna\n");
	}
	else if (this->getSuperpowerTury() > 5 && this->getSuperpowerTury() <= 10) {
		this->setSuperpowerTury(this->getSuperpowerTury() + 1);
	}
	else if (this->getSuperpowerTury() > 10){
		this->setSuperpowerTury(0);
	}
	int kier = -1;
	int key = this->getSwiat()->getKey();
	int curr_x = this->getX();
	int curr_y = this->getY();
	if (key != 0) {
		switch (key) {
		case KEY_UP:
			kier = GORA;
			break;
		case KEY_DOWN:
			kier = DOL;
			break;
		case KEY_LEFT:
			kier = LEWO;
			break;
		case KEY_RIGHT:
			kier = PRAWO;
			break;
		case SUPERPOWER:
			if (this->getSuperpowerTury() == 0) {
				this->setSuperpowerTury(1);
				this->getSwiat()->setEvents(this->getSwiat()->getEvents() + "Specjalna umiejetnosc Czlowieka zostala aktywowana!\n");
			}
			else if (this->getSuperpowerTury() > 0 && this->getSuperpowerTury() <= 5) {
				this->getSwiat()->setEvents(this->getSwiat()->getEvents() + "Specjalna umiejetnosc Czlowieka jest aktywna\n");
			}
			else if (this->getSuperpowerTury() > 5 && this->getSuperpowerTury() <= 10){
				this->getSwiat()->setEvents(this->getSwiat()->getEvents() + "Specjalna umiejetnosc Czlowieka jest niedostepna. Sprobuj pozniej.\n");
			}
			else {
				return;
			}
			return;
		default:
			return;
		}
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
			return;
		}
	}
}

void Czlowiek::kolizja(int opp_y, int opp_x, Zwierze* napastnik) {
	if (this->getSuperpowerTury() == 0) {
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
			this->getSwiat()->setKoniec(true);
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
	else if (this->getSuperpowerTury() > 0 && this->getSuperpowerTury() <= 5) {
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
		if (curr_y + i >= 0 && curr_y + i < this->getSwiat()->getN() && curr_x + j >= 0 && curr_x + j < this->getSwiat()->getM()){
			if (this->getSwiat()->getMapa().mapa[curr_y + i][curr_x + j] == this->getSwiat()->pustosc) {
				napastnik->setX(curr_x + j);
				napastnik->setY(curr_y + i);
				this->getSwiat()->getMapa().mapa[curr_y][curr_x] = this->getZnaczek();
				this->getSwiat()->getMapa().mapa[curr_y + i][curr_x + j] = napastnik->getZnaczek();
			}
			else {
				for (int iter = 0; iter < this->getSwiat()->getN() * this->getSwiat()->getM(); iter++) {
					if (this->getSwiat()->getZwierzeta()[iter] != NULL) {
						if (this->getSwiat()->getZwierzeta()[iter]->getX() == curr_x + j && this->getSwiat()->getZwierzeta()[iter]->getY() == curr_y + i) {
							this->getSwiat()->getZwierzeta()[iter]->kolizja(curr_y + i, curr_x + j, napastnik);
							return;
						}
					}
					if (this->getSwiat()->getRosliny()[iter] != NULL) {
						if (this->getSwiat()->getRosliny()[iter]->getX() == curr_x + j && this->getSwiat()->getRosliny()[iter]->getY() == curr_y + i) {
							this->getSwiat()->getRosliny()[iter]->kolizja(curr_y + i, curr_x + j, napastnik);
							return;
						}
					}
				}
			}
		}
		else {
			this->getSwiat()->getMapa().mapa[curr_y][curr_x] = this->getZnaczek();
			napastnik = NULL;
		}
		this->getSwiat()->setEvents(this->getSwiat()->getEvents() + this->getGatunek() + " odpiera atak " + napastnik->getGatunek() + " korzystajac ze specjalnej umiejetnosci\n");
		return;
	}
	else if (this->getSuperpowerTury() > 5 && this->getSuperpowerTury() <= 10) {
		if (this->getSila() > napastnik->getSila()) {
			this->getSwiat()->setEvents(this->getSwiat()->getEvents() + this->getGatunek() + " zabija " + napastnik->getGatunek() + "\n");
			this->getSwiat()->getMapa().mapa[napastnik->getY()][napastnik->getX()] = this->getSwiat()->pustosc;
			napastnik->setZyje(false);
			napastnik = NULL;
		}
		else if (this->getSila() <= napastnik->getSila()) {
			this->getSwiat()->setEvents(this->getSwiat()->getEvents() + napastnik->getGatunek() + " zabija " + this->getGatunek() + "\n");
			this->getSwiat()->getMapa().mapa[opp_y][opp_x] = this->getSwiat()->pustosc;
			this->setZyje(false);
			this->getSwiat()->setKoniec(true);
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
	} else if (this->getSuperpowerTury() > 10) {
		this->setSuperpowerTury(0);
		return;
	}
}

Czlowiek::~Czlowiek() {

}