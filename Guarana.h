#pragma once
#include <iostream>
#include <string>
#include "Naglowki.h"

class Guarana : public Roslina {
public:
	Guarana();
	Guarana(int y, int x, Swiat* swiat);
	void kolizja(int opp_y, int opp_x, Zwierze* napastnik) override;
	~Guarana();
};