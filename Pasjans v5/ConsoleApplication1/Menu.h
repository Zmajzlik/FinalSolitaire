#ifndef MENU_H
#define MENU_H
#include"stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <cstdio>
#include "Playgame.h"

using namespace std;
void zasadyGry()
{
	system("cls");
	cout << "########################################" << endl;
	cout << "	ZASADY GRY " << endl;
	cout << "########################################" << endl;
	cout << "1.Gre zaczynamy od ulozenia wszystkich kart Kier w kolejnosci zaczynajac od dowolnego numeru(mozemy zaczac nawet od 8/9 itd).";
	cout << "\n2.Pozostale karty moga byc ukladane niezaleznie od koloru lecz z zachowaniem kolejnosci.";
		cout << "\n3.Puste pola moga byc wypelnione lub zbudowane z kart za wyjatkiem Kier'ow";
		cout << "\n W naszej grze aby przemieszczac karty musimy wpisywac numer kolumny w ktorej dana karta sie znajduje,\n a nastepnie podac numer kolumny do ktorej chcemy ja przesunac\n";
}
void autorzy()
{
	cout << "Autorzy:" << endl;
	cout << "\n \t Kamil Kowalczyk";
	cout << "\n \t Artur Ulfig \n";
}
void menu() {
	char w;
	system("cls");
	cout << "########################################" << endl;
	cout << "	DIAMOND MINES SOLITAIRE" << endl;
	cout << "########################################" << endl;
	cout << "1. Rozpocznij gre" << endl;
	cout << "2. Zasady gry i sterowanie" << endl;
	cout << "3. Autorzy" << endl;
	cout << "4. Wyjscie" << endl;
	cout << "Wybor: ";
	cin >> w;
	switch (w) 
	{
	case '1': 
		playGame();
		break;
	case '2': 
	{
		zasadyGry();
		break;
	}
	case '3': 
	{
		autorzy();
		break;
	}
	case '4':
		exit(0);
		break;
	}
}
#endif