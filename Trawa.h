#pragma once
#include <iostream>
#include <string>
#include "Naglowki.h"

class Trawa : public Roslina {
public:
	Trawa();
	Trawa(int y, int x, Swiat* swiat);
	~Trawa();
};