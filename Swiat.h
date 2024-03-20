#pragma once
#include <iostream>
#include <string>
#include "Naglowki.h"

using namespace std;

class Organizm;
class Zwierze;
class Roslina;

class Swiat {
private:
	struct Mapa {
		int n;
		int m;
		char** mapa;
	};
	Mapa mapa;
	Zwierze** zwierzeta;
	Roslina** rosliny;
	string events;

	int licznik_tur;
	int key;
	bool koniec = false;

public:

	const char pustosc = '.';

	Swiat();
	Swiat(int n, int m);
	int getN() const;
	int getM() const;
	int getLicznikTur() const;
	int getKey() const;
	bool getKoniec() const;
	Mapa getMapa() const;
	string getEvents() const;
	Zwierze** getZwierzeta() const;
	Roslina** getRosliny() const;
	void setN(int n);
	void setM(int m);
	void setLicznikTur(int liczba);
	void setKey(int key);
	void setKoniec(bool koniec);
	void setMapa(Mapa mapa);
	void setEvents(string events);
	void setZwierzeta(Zwierze** zwierzeta);
	void setRosliny(Roslina** rosliny);
	void rysujSwiat();
	void sortujZwierzeta();
	void sortujRosliny();
	void wykonajTure();
	~Swiat();

};