#pragma once
#include <iostream>
#include <string>
#include "Naglowki.h"

class WilczeJagody : public Roslina {
public:
	WilczeJagody();
	WilczeJagody(int y, int x, Swiat* swiat);
	void kolizja(int opp_y, int opp_x, Zwierze* napastnik) override;
	~WilczeJagody();
};