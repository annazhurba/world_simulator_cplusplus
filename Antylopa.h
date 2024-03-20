#pragma once
#include <iostream>
#include <string>
#include "Naglowki.h"

class Antylopa : public Zwierze {
public:
    Antylopa();
	Antylopa(int y, int x, Swiat* swiat);
	void akcja() override;
	void kolizja(int opp_y, int opp_x, Zwierze* napastnik) override;
	~Antylopa();
};