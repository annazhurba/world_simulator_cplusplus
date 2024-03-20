#pragma once
#include <iostream>
#include <string>
#include "Naglowki.h"

class BarszczSosnowskiego : public Roslina {
public:
	BarszczSosnowskiego();
	BarszczSosnowskiego(int y, int x, Swiat* swiat);
	void akcja() override;
	void kolizja(int opp_y, int opp_x, Zwierze* napastnik) override;
	~BarszczSosnowskiego();
};