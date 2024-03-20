#pragma once
#include <iostream>
#include <string>
#include "Naglowki.h"

class Mlecz : public Roslina {
public:
	Mlecz();
	Mlecz(int y, int x, Swiat* swiat);
	void akcja() override;
	~Mlecz();
};