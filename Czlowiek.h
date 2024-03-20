#pragma once
#include <iostream>
#include <string>
#include "Naglowki.h"

class Czlowiek : public Zwierze {
private:
	int superpower_tury;
public:
	Czlowiek();
	Czlowiek(int y, int x, Swiat* swiat);
	int getSuperpowerTury();
	void setSuperpowerTury(int liczba);
	void akcja() override;
	void kolizja(int opp_y, int opp_x, Zwierze* napastnik) override;

	~Czlowiek();
};