#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <cstdio>
#include "Karta.h"
#include "Talia.h"

using namespace std;

int z, na;
void instrukcjeGry() {
	cout << "Ktora karte przeniesc? ";
	cin >> z;
	cout << "Gdzie? ";
	cin >> na;
	cout << z << " " << na << " " << endl;
}

void playGame()
{
	string figura[13] = { "A","2","3","4","5","6","7","8","9","10","J","D","K" };
	int kolor[4] = { 3, 4, 5, 6 };
	Karta karty[52];
	int licznik = 0;
	for (int i = 0; i<13; i++)
	{
		for (int j = 0; j<4; j++)
		{
			Karta karta(figura[i], kolor[j], false);
			karty[licznik] = karta;
			licznik++;
		}
	}
	Karta pustaKarta = Karta();
	Talia talia(karty, pustaKarta);
	talia.tasuj();
	talia.pole();
	string komunikat = "";
	while (1) {
		talia.odkrywaj();
		talia.wypisz();
		cout << komunikat << endl;
		instrukcjeGry();
		komunikat = talia.przenies(z, na);
		system("cls");
	}

}
