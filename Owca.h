#pragma once
#include <iostream>
#include <string>
#include "Naglowki.h"

class Owca : public Zwierze {
public:
	Owca();
	Owca(int y, int x, Swiat* swiat);
	~Owca();
};