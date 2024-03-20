#pragma once
#include <iostream>
#include <string>
#include "Naglowki.h"

Trawa::Trawa() {

}

Trawa::Trawa(int y, int x, Swiat* swiat) {
	this->setY(y);
	this->setX(x);
	this->setSila(0);
	this->setInicjatywa(0);
	this->setWiek(0);
	this->setGatunek("Trawa");
	this->setRodzaj("Roslina");
	this->setZnaczek('t');
	this->setSwiat(swiat);
}

Trawa::~Trawa() {

}