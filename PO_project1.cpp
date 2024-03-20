#pragma once
#include <iostream>
#include <string>
#include "Naglowki.h"

int main()
{
	int n, m;
	cout << "Podaj rozmiar mapy swiata" << endl;
	cin >> n >> m;
	Swiat swiat(n,m);
	swiat.rysujSwiat();
	int key;

	while (swiat.getKoniec() == false) {
		key = 0;
		if (_kbhit()) {
			key = _getch();
			if (key == KEY_UP || key == KEY_DOWN || key == KEY_RIGHT || key == KEY_LEFT || key == NEW_TURA || key == SUPERPOWER) {
				swiat.setKey(key);
				swiat.wykonajTure();
			}
		}
	}
	return 0;
}