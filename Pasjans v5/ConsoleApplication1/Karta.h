#pragma once
#include"stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <cstdio>

using namespace std;

class Karta
{
private:

	string figura;
	int kolor;
	bool status;

public:
	Karta();
	Karta(string fig, int kol, bool st);
	void wypisz();
	void setStatus(bool b);
	bool getStatus();
	string getFigura();
	int getKolor();
};


Karta::Karta() {
	figura = "";
}

Karta::Karta(string fig, int kol, bool st) {
	figura = fig;
	kolor = kol;
	status = st;
}

void Karta::setStatus(bool b) {
	this->status = b;
}

bool Karta::getStatus() {
	return status;
}

string Karta::getFigura() {
	return figura;
}

int Karta::getKolor() {
	return kolor;
}

void Karta::wypisz()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (figura == "") {
		cout << "    ";
	}
	else if (status == true) {
		if (kolor == 3) SetConsoleTextAttribute(hOut, BACKGROUND_RED); //karo
		else if (kolor == 4) SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_INTENSITY);// kier
		else if (kolor == 5)SetConsoleTextAttribute(hOut, BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED); //trefl
		else SetConsoleTextAttribute(hOut, BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY); //pik
		if (figura == "10")
		{
			cout << " " << figura;
			printf("%c", kolor);
		}
		else
		{
			cout << " " << figura;
			printf("%c", kolor);
			cout << " ";
		}
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
	else {
		SetConsoleTextAttribute(hOut, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
		cout << " XX ";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
}