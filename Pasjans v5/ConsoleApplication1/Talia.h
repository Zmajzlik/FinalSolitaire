#ifndef TALIA_H
#define TALIA_H
#include"stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <cstdio>
#include "Karta.h"
#include "Talia.h"

using namespace std;


class Talia
{

private:
	Karta karty[52];
	Karta poleGry[16][13];
	Karta kartyPosortowane[52];
public:
	Talia(Karta karta[], Karta pustaKarta);
	void tasuj();
	void wypisz();
	void pole();
	void odkrywaj();
	string przenies(int z, int na);
};

Talia::Talia(Karta karta[], Karta pustaKarta) {
	for (int i = 0; i<52; i++) {
		karty[i] = karta[i];
	}
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			poleGry[i][j] = pustaKarta;
		}
	}
}

void Talia::tasuj()
{
	int temp[52];

	srand(time(NULL));

	for (int i = 0; i<52; i++) {
		temp[i] = 0;
	}
	//temp[indeks] == 0 nie ma karty, == 1 juz jest karta
	for (int i = 0; i<52; i++) {
		int miejsce = rand() % 52;
		while (temp[miejsce] == 1) {
			miejsce = rand() % 52;
		}
		this->kartyPosortowane[miejsce] = this->karty[i];
		temp[miejsce] = 1;
	}


}

void Talia::pole()
{
	int licznik = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			this->poleGry[i][j] = kartyPosortowane[licznik];
			licznik++;
		}
	}
}

void Talia::wypisz() {
	int licznik = 0;
	for (int i = 0; i < 13; i++) {
		if (i <= 8) {
			cout << "  " << i + 1 << "   ";
		}
		else {
			cout << "  " << i + 1 << "  ";
		}

	}
	cout << endl;
	for (int i = 0; i<16; i++) {
		for (int j = 0; j<13; j++) {
			this->poleGry[i][j].wypisz();
			cout << "  ";
			licznik++;
		}
		cout << "\n";
	}


}

void Talia::odkrywaj()
{
	for (int i = 15; i >= 1; i--) {
		for (int j = 12; j >= 0; j--) {
			if (poleGry[i][j].getFigura() == "" && poleGry[i - 1][j].getStatus() == false)
			{
				this->poleGry[i - 1][j].setStatus(true);
			}
		}
	}
}

string Talia::przenies(int z, int na) {
	if (z < 1 || z > 13 || na < 1 || na > 13) {
		return "Podales zle parametry\n";
	}
	else {
		int i = 0, j = 0, iStart = 0;
		while (poleGry[iStart][z - 1].getStatus() == false) {
			iStart++;
		}
		while (poleGry[i][z - 1].getFigura() != "") {
			i++;
		}
		while (poleGry[j][na - 1].getFigura() != "") {
			j++;
		}
		cout << i << " " << iStart;
		if (i - 1 < 0) {
			return "Nie ma tu kart\n";
		}
		else {
			if (
				((poleGry[iStart][z - 1].getKolor() == 4 && poleGry[j - 1][na - 1].getKolor() == 4) ||
					(poleGry[iStart][z - 1].getKolor() != 4 && poleGry[j - 1][na - 1].getKolor() != 4)) &&
				((poleGry[iStart][z - 1].getFigura() == "2" && poleGry[j - 1][na - 1].getFigura() == "A") ||
					(poleGry[iStart][z - 1].getFigura() == "3" && poleGry[j - 1][na - 1].getFigura() == "2") ||
					(poleGry[iStart][z - 1].getFigura() == "4" && poleGry[j - 1][na - 1].getFigura() == "3") ||
					(poleGry[iStart][z - 1].getFigura() == "5" && poleGry[j - 1][na - 1].getFigura() == "4") ||
					(poleGry[iStart][z - 1].getFigura() == "6" && poleGry[j - 1][na - 1].getFigura() == "5") ||
					(poleGry[iStart][z - 1].getFigura() == "7" && poleGry[j - 1][na - 1].getFigura() == "6") ||
					(poleGry[iStart][z - 1].getFigura() == "8" && poleGry[j - 1][na - 1].getFigura() == "7") ||
					(poleGry[iStart][z - 1].getFigura() == "9" && poleGry[j - 1][na - 1].getFigura() == "8") ||
					(poleGry[iStart][z - 1].getFigura() == "10" && poleGry[j - 1][na - 1].getFigura() == "9") ||
					(poleGry[iStart][z - 1].getFigura() == "J" && poleGry[j - 1][na - 1].getFigura() == "10") ||
					(poleGry[iStart][z - 1].getFigura() == "D" && poleGry[j - 1][na - 1].getFigura() == "J") ||
					(poleGry[iStart][z - 1].getFigura() == "K" && poleGry[j - 1][na - 1].getFigura() == "D") ||
					(poleGry[iStart][z - 1].getFigura() == "A" && poleGry[j - 1][na - 1].getFigura() == "K"))
				) {
				for (int x = iStart; x < i; x++) {
					Karta k = poleGry[x][z - 1];
					poleGry[x][z - 1] = Karta();
					poleGry[j++][na - 1] = k;
				}
				return "Przesunieto karty\n";
			}
			else
			{
				return "Nie mozna przesunac karty wbrew zasad!\n";
			}
		}
	}
}
#endif
