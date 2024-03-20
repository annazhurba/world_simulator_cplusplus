#pragma once
#include <iostream>
#include <string>
#include "Naglowki.h"

class Roslina : public Organizm {
public:
	virtual void akcja() override;
	virtual void kolizja(int opp_y, int opp_x, Zwierze* napastnik) override;
	~Roslina();
};