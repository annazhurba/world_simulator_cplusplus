#pragma once
#include <iostream>
#include <string>
#include "Naglowki.h"

class Swiat;

int Organizm::getY() const{
	return this->y;
}

int Organizm::getX() const{
	return this->x;
}

int Organizm::getSila() const{
	return this->sila;
}

int Organizm::getInicjatywa() const{
	return this->inicjatywa;
}

int Organizm::getWiek() const{
	return this->wiek;
}

string Organizm::getGatunek() const{
	return this->gatunek;
}

string Organizm::getRodzaj() const{
	return this->rodzaj;
}

char Organizm::getZnaczek() const{
	return this->znaczek;
}

Swiat* Organizm::getSwiat() const{
	return this->swiat;
}

bool Organizm::getZyje() const {
	return this->zyje;
}

void Organizm::setY(int y) {
	this->y = y;
}

void Organizm::setX(int x) {
	this->x = x;
}

void Organizm::setSila(int sila) {
	this->sila = sila;
}

void Organizm::setInicjatywa(int inic) {
	this->inicjatywa = inic;
}

void Organizm::setWiek(int wiek) {
	this->wiek = wiek;
}

void Organizm::setGatunek(string gatunek) {
	this->gatunek = gatunek;
}

void Organizm::setRodzaj(string rodzaj) {
	this->rodzaj = rodzaj;
}

void Organizm::setZnaczek(char znaczek) {
	this->znaczek = znaczek;
}

void Organizm::setSwiat(Swiat* swiat) {
	this->swiat = swiat;
}

void Organizm::setZyje(bool zyje) {
	this->zyje = zyje;
}

Organizm::~Organizm() {
	
}