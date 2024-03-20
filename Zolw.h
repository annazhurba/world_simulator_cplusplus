#pragma once
#include <iostream>
#include "Naglowki.h"

class Zolw : public Zwierze {
public:
	Zolw();
	Zolw(int y, int x, Swiat* swiat);
	void akcja() override;
	void kolizja(int opp_y, int opp_x, Zwierze* napastnik) override;
	~Zolw();
};