#pragma once
#include <iostream>
#include <string>
#include "Naglowki.h"

Wilk::Wilk() {

}

Wilk::Wilk(int y, int x, Swiat* swiat) {
	this->setY(y);
	this->setX(x);
	this->setSila(9);
	this->setInicjatywa(5);
	this->setWiek(0);
	this->setGatunek("Wilk");
	this->setRodzaj("Zwierze");
	this->setZnaczek('W');
	this->setSwiat(swiat);
}

Wilk::~Wilk() {
	
}