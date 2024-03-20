#pragma once
#include <iostream>
#include <string>
#include "Naglowki.h"

class Organizm;
class Zwierze;
class Roslina;
class Czlowiek;

Swiat::Swiat() {

}

Swiat::Swiat(int n, int m) {
	srand(time(NULL));
	this->setN(n);
	this->setM(m);
	this->setLicznikTur(1);
	this->setKey(0);

	this->mapa.mapa = new char*[n];
	for (int i = 0; i < this->mapa.n; i++) {
		this->mapa.mapa[i] = new char[this->mapa.m];
		for (int j = 0; j < this->mapa.m; j++) {
			this->mapa.mapa[i][j] = this->pustosc;
		}
	}

	zwierzeta = new Zwierze*[n * m];
	for (int i = 0; i < n * m; i++) {
		zwierzeta[i] = NULL;
	}

	rosliny = new Roslina * [n * m];
	for (int i = 0; i < n * m; i++) {
		rosliny[i] = NULL;
	}

	Wilk* wilk1 = new Wilk(1, 2, this);
	this->mapa.mapa[1][2] = wilk1->getZnaczek();
	zwierzeta[0] = wilk1;
	Wilk* wilk2 = new Wilk(1, 3, this);
	zwierzeta[1] = wilk2;
	this->mapa.mapa[1][3] = wilk2->getZnaczek();

	Wilk* wilk3 = new Wilk(0, 3, this);
	zwierzeta[1] = wilk3;
	this->mapa.mapa[0][3] = wilk3->getZnaczek();

	Owca* owca1 = new Owca(4, 3, this);
	this->mapa.mapa[4][3] = owca1->getZnaczek();
	zwierzeta[2] = owca1;
	Owca* owca2 = new Owca(1, 5, this);
	this->mapa.mapa[1][5] = owca2->getZnaczek();
	zwierzeta[3] = owca2;
	
	Lis* lis1 = new Lis(3, 5, this);
	this->mapa.mapa[3][5] = lis1->getZnaczek();
	zwierzeta[4] = lis1;
	Lis* lis2 = new Lis(6, 0, this);
	this->mapa.mapa[6][0] = lis2->getZnaczek();
	zwierzeta[5] = lis2;

	Zolw* zolw1 = new Zolw(7, 6, this);
	this->mapa.mapa[7][6] = zolw1->getZnaczek();
	zwierzeta[6] = zolw1;
	Zolw* zolw2 = new Zolw(7, 7, this);
	this->mapa.mapa[7][7] = zolw2->getZnaczek();
	zwierzeta[7] = zolw2;

	Antylopa* antylopa1 = new Antylopa(1, 7, this);
	this->mapa.mapa[1][7] = antylopa1->getZnaczek();
	zwierzeta[8] = antylopa1;
	Antylopa* antylopa2 = new Antylopa(0, 9, this);
	this->mapa.mapa[0][9] = antylopa2->getZnaczek();
	zwierzeta[9] = antylopa2;

	Czlowiek* czlowiek = new Czlowiek(9, 4, this);
	zwierzeta[12] = czlowiek;
	this->mapa.mapa[9][4] = czlowiek->getZnaczek();

	Trawa* trawa = new Trawa(7, 3, this);
	rosliny[0] = trawa;
	this->mapa.mapa[7][3] = trawa->getZnaczek();

	Mlecz* mlecz = new Mlecz(9, 9, this);
	rosliny[1] = mlecz;
	this->mapa.mapa[9][9] = mlecz->getZnaczek();

	Guarana* guarana1 = new Guarana(5, 5, this);
	rosliny[2] = guarana1;
	this->mapa.mapa[5][5] = guarana1->getZnaczek();
	Guarana* guarana2 = new Guarana(9, 5, this);
	rosliny[3] = guarana2;
	this->mapa.mapa[9][5] = guarana2->getZnaczek();

	WilczeJagody* wj = new WilczeJagody(8, 8, this);
	rosliny[4] = wj;
	this->mapa.mapa[8][8] = wj->getZnaczek();

	BarszczSosnowskiego* bs = new BarszczSosnowskiego(3, 8, this);
	rosliny[5] = bs;
	this->mapa.mapa[3][8] = bs->getZnaczek();


	//dodaj organizmy
}

int Swiat::getN() const {
	return this->mapa.n;
}

int Swiat::getM() const {
	return this->mapa.m;
}

int Swiat::getLicznikTur() const {
	return this->licznik_tur;
}

int Swiat::getKey() const {
	return this->key;
}

bool Swiat::getKoniec() const {
	return this->koniec;
}

Swiat::Mapa Swiat::getMapa() const {
	return this->mapa;
}

string Swiat::getEvents() const {
	return this->events;
}

Zwierze** Swiat::getZwierzeta() const {
	return this->zwierzeta;
}

Roslina** Swiat::getRosliny() const{
	return this->rosliny;
}

void Swiat::setN(int n) {
	this->mapa.n = n;
}

void Swiat::setM(int m) {
	this->mapa.m = m;
}

void Swiat::setLicznikTur(int liczba) {
	this->licznik_tur = liczba;
}

void Swiat::setKey(int key) {
	this->key = key;
}

void Swiat::setKoniec(bool koniec) {
	this->koniec = koniec;
}

void Swiat::setMapa(Mapa mapa) {
	this->mapa = mapa;
}

void Swiat::setEvents(string events) {
	this->events = events;
}

void Swiat::setZwierzeta(Zwierze** zwierzeta) {
	this->zwierzeta = zwierzeta;
}

void Swiat::setRosliny(Roslina** rosliny) {
	this->rosliny = rosliny;
}

void Swiat::rysujSwiat() {
	system("cls");
	cout << "Wirtualny Swiat" << endl;
	cout << "Autor: Anna Zhurba" << endl;
	cout << "Indeks: 192038" << endl;
	cout << "Tura numer " << this->licznik_tur << endl << endl;
	for (int i = 0; i < this->getMapa().n; i++) {
		for (int j = 0; j < this->getMapa().m; j++) {
			cout << this->mapa.mapa[i][j];
		}
		cout << endl;
	}
	cout << this->events << endl;
}

void Swiat::sortujZwierzeta() {
	//sortowanie
	for (int i = 0; i < this->getN()*this->getM() - 1; i++) {
		for (int j = 0; j < this->getN() * this->getM() - i - 1; j++) {
			if (this->getZwierzeta()[j] != NULL) {
				for (int k = j + 1; k < this->getN() * this->getM(); k++) {
					if (this->getZwierzeta()[k] != NULL) {
						if (this->getZwierzeta()[j]->getInicjatywa() < this->getZwierzeta()[k]->getInicjatywa()) {
							swap(this->getZwierzeta()[j], this->getZwierzeta()[k]);
							break;
						}
					}
				}
			}
			/*else {
				for (int k = j + 1; k < this->getN() * this->getM(); k++) {
					this->getZwierzeta()[k - 1] = this->getZwierzeta()[k];
				}
				this->getZwierzeta()[this->getN() * this->getM() - 1] = NULL;
			}*/
		}
	}
	for (int i = 0; i < this->getN() * this->getM() - 1; i++) {
		for (int j = 0; j < this->getN() * this->getM() - i - 1; j++) {
			if (this->getZwierzeta()[j] != NULL) {
				for (int k = j + 1; k < this->getN() * this->getM(); k++) {
					if (this->getZwierzeta()[k] != NULL) {
						if (this->getZwierzeta()[j]->getInicjatywa() == this->getZwierzeta()[k]->getInicjatywa()) {
							if (this->getZwierzeta()[j]->getWiek() < this->getZwierzeta()[k]->getWiek()) {
								swap(this->getZwierzeta()[j], this->getZwierzeta()[k]);
								break;
							}

						}
					}
				}
			}
		}
	}
	/*for (int i = 0; i < this->getN()*this->getM(); i++) {
		if (this->getZwierzeta()[i] != NULL) {
			cout << this->getZwierzeta()[i]->getGatunek() << endl;
		}
	}*/
}

void Swiat::sortujRosliny() {
	for (int i = 0; i < this->getN() * this->getM() - 1; i++) {
		for (int j = 0; j < this->getN() * this->getM() - i - 1; j++) {
			if (this->getRosliny()[j] != NULL) {
				for (int k = j + 1; k < this->getN() * this->getM(); k++) {
					if (this->getRosliny()[k] != NULL) {
						if (this->getRosliny()[j]->getInicjatywa() == this->getRosliny()[k]->getInicjatywa()) {
							if (this->getRosliny()[j]->getWiek() < this->getRosliny()[k]->getWiek()) {
								swap(this->getRosliny()[j], this->getRosliny()[k]);
							}
						}
						break;
					}
				}
			}
			/*else {
				for (int k = j + 1; k < this->getN() * this->getM(); k++) {
					this->getRosliny()[k - 1] = this->getRosliny()[k];
				}
				this->getRosliny()[this->getN() * this->getM() - 1] = NULL;
			}*/
		}
	}
}

void Swiat::wykonajTure() {
	this->setLicznikTur(this->getLicznikTur() + 1);
	for (int i = 0; i < this->getN() * this->getM(); i++) {
		if (this->zwierzeta[i] != NULL && this->zwierzeta[i]->getZyje() == true) {
			this->zwierzeta[i]->setWiek(this->zwierzeta[i]->getWiek() + 1);
		}
	}
	this->setEvents("");
	//sortowanie organizmow!!!!
	this->sortujZwierzeta();
	this->sortujRosliny();
	for (int i = 0; i < this->getN()*this->getM(); i++) {
		if (this->zwierzeta[i] != NULL && this->zwierzeta[i]->getZyje() == true) {
			this->zwierzeta[i]->akcja();
		}
	}
	for (int i = 0; i < this->getN() * this->getM(); i++) {
		if (this->rosliny[i] != NULL && this->rosliny[i]->getZyje() == true) {
			this->rosliny[i]->akcja();
		}
	}
	this->rysujSwiat();
}

Swiat::~Swiat() {
	
}