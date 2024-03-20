#pragma once
#include <iostream>
#include "Naglowki.h"

Guarana::Guarana() {

}

Guarana::Guarana(int y, int x, Swiat* swiat) {
	this->setY(y);
	this->setX(x);
	this->setSila(0);
	this->setInicjatywa(0);
	this->setWiek(0);
	this->setGatunek("Guarana");
	this->setRodzaj("Roslina");
	this->setZnaczek('g');
	this->setSwiat(swiat);
}

void Guarana::kolizja(int opp_y, int opp_x, Zwierze* napastnik) {
	napastnik->setSila(napastnik->getSila() + 3);
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

Guarana::~Guarana() {

}