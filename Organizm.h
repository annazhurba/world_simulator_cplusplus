#pragma once
#include <iostream>
#include <string>
#include "Naglowki.h"

class Swiat;

class Organizm {
private:
	string gatunek;
	string rodzaj;
	int sila;
	int inicjatywa;
	int wiek;
	int x, y;
	char znaczek;
	Swiat* swiat;
	bool zyje = true;
public:
	int getY() const;
	int getX() const;
	int getSila() const;
	int getInicjatywa() const;
	int getWiek() const;
	string getGatunek() const;
	string getRodzaj() const;
	char getZnaczek() const;
	Swiat* getSwiat() const;
	bool getZyje() const;
	void setY(int y);
	void setX(int x);
	void setSila(int sila);
	void setInicjatywa(int inic);
	void setWiek(int wiek);
	void setGatunek(string gatunek);
	void setRodzaj(string rodzaj);
	void setZnaczek(char znaczek);
	void setSwiat(Swiat* swiat);
	void setZyje(bool zyje);
	virtual void akcja() = 0;
	virtual void kolizja(int opp_y, int opp_x, Zwierze* napastnik) = 0;
	
    ~Organizm();
};