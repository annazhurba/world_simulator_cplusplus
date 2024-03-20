#pragma once
#include <iostream>
#include <string>
#include "Naglowki.h"

Owca::Owca() {

}

Owca::Owca(int y, int x, Swiat* swiat) {
	this->setY(y);
	this->setX(x);
	this->setSila(4);
	this->setInicjatywa(4);
	this->setWiek(0);
	this->setGatunek("Owca");
	this->setRodzaj("Zwierze");
	this->setZnaczek('O');
	this->setSwiat(swiat);
}

Owca::~Owca() {

}