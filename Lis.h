#pragma once
#include <iostream>
#include <string>
#include "Naglowki.h"

class Lis : public Zwierze {
public:
	Lis();
	Lis(int y, int x, Swiat* swiat);
	void akcja() override;
	~Lis();
};