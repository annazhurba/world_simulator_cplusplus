#pragma once
#include <iostream>
#include <string>
#include "Naglowki.h"

class Wilk : public Zwierze {
public:
	Wilk();
	Wilk(int y, int x, Swiat* swiat);
	~Wilk();
};