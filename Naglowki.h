#pragma once
#include <conio.h>
#include <string>
#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Roslina.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
#include "Czlowiek.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define NEW_TURA 52
#define SUPERPOWER 51

using namespace std;

//left 30
//down 31
//up 17
//right 32

//left 75
//right 77
//up 72
//down 80

enum Kierunek {
	LEWO,
	PRAWO,
	GORA,
	DOL,
	L_G,
	L_D,
	P_G,
	P_D
};