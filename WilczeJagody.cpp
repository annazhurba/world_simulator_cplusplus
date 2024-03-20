#pragma once
#include <iostream>
#include <string>
#include "Naglowki.h"

WilczeJagody::WilczeJagody() {

}
WilczeJagody::WilczeJagody(int y, int x, Swiat* swiat) {
	this->setY(y);
	this->setX(x);
	this->setSila(99);
	this->setInicjatywa(0);
	this->setWiek(0);
	this->setGatunek("WilczeJagody");
	this->setRodzaj("Roslina");
	this->setZnaczek('j');
	this->setSwiat(swiat);
}

void WilczeJagody::kolizja(int opp_y, int opp_x, Zwierze* napastnik) {
	this->getSwiat()->getMapa().mapa[this->getY()][this->getX()] = this->getSwiat()->pustosc;
	this->getSwiat()->getMapa().mapa[napastnik->getY()][napastnik->getX()] = this->getSwiat()->pustosc;
	napastnik->setZyje(false);
	this->getSwiat()->setEvents(this->getSwiat()->getEvents() + napastnik->getGatunek() + " zjada " + this->getGatunek() + " i umiera\n");
	napastnik = NULL;
}

WilczeJagody::~WilczeJagody() {

}