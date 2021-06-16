#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Uzytkownik
{
	string login, haslo;

public:

	string imie, nazwisko;

	void Wczytywanie(vector<Uzytkownik>& wszyscyUzytkownicy); //wczytywanie wszystkich zarejestrowanych uzytkownikow 
	void Rejestracja(vector<Uzytkownik>& wszyscyUzytkownicy); //rejestrowanie nowego uzytkownika i zapis jego danych
	void Logowanie(vector<Uzytkownik> wszyscyUzytkownicy); //logowanie do istniejacego konta
};