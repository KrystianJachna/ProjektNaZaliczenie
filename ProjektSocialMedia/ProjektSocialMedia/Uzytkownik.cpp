#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Uzytkownik.h"

using namespace std;

void Uzytkownik::Wczytywanie(vector<Uzytkownik>& wszyscyUzytkownicy)
{
	fstream plik;
	plik.open("danelogowania.txt", ios::in);

	if (plik.good() == false)
	{
		cout << "Nie udalo sie zaladowac danych!";
		exit(0);
	}

	int aktualnyNr = 1;
	string linia;
	Uzytkownik odczytany;

	while (getline(plik, linia))
	{

		if (aktualnyNr == 1)
		{
			odczytany.imie = linia;

		}
		if (aktualnyNr == 2)
		{
			odczytany.nazwisko = linia;
		}
		if (aktualnyNr == 3)
		{
			odczytany.login = linia;
		}
		if (aktualnyNr == 4)
		{

			odczytany.haslo = linia;
			wszyscyUzytkownicy.push_back(odczytany);
			aktualnyNr = 0;
		}
		aktualnyNr++;
	}

	plik.close();
}

void Uzytkownik::Rejestracja(vector<Uzytkownik>& wszyscyUzytkownicy)
{
	Uzytkownik nowy;
	bool niepowtarzalnyLogin = true;
	bool dlugoscHasla = true;

	system("cls");

	cout << "REJESTRACJA" << endl << "Witaj w procesie rejestracji, podaj nam kilka danych o sobie, abysmy mogli Cie lepiej poznac" << endl;
	cout << "Imie: ";
	cin >> nowy.imie;
	cout << "Nazwisko: ";
	cin >> nowy.nazwisko;
	if (wszyscyUzytkownicy.size() != 0)
	{
		while (niepowtarzalnyLogin)
		{
			cout << "Login: ";
			cin >> nowy.login;
			for (int i = 0; i < (int)wszyscyUzytkownicy.size(); i++)
			{
				if (wszyscyUzytkownicy[i].login == nowy.login)
				{
					cout << "Podany login jest zajety, prosze podac inny" << endl << "Login: ";
					cin >> nowy.login;
					i = 0;
				}
				else
				{
					niepowtarzalnyLogin = false;
				}
			}
		}
	}
	else
	{
		cout << "Login: ";
		cin >> nowy.login;
	}

	while (dlugoscHasla)
	{
		cout << "Haslo: ";
		cin >> nowy.haslo;

		if (nowy.haslo.length() < 4)
		{
			cout << "Haslo powinno miec conajmniej 4 znaki" << endl;;
		}
		else
		{
			dlugoscHasla = false;
		}
	}


	imie = nowy.imie;
	nazwisko = nowy.nazwisko;

	cout << "Zarejestrowano jako " << imie << " " << nazwisko;

	wszyscyUzytkownicy.push_back(nowy);
	ofstream plik("danelogowania.txt", ios_base::app);
	plik << endl << nowy.imie << endl << nowy.nazwisko << endl << nowy.login << endl << nowy.haslo;
	plik.close();
}

void Uzytkownik::Logowanie(vector<Uzytkownik> wszyscyUzytkownicy)
{
	string login, haslo;
	bool zgodnosc = true;
	int nrUzytkownika;

	system("cls");

	cout << "LOGOWANIE" << endl << "Aby sie zalogowac podaj odpowiednie dane" << endl;

	while (zgodnosc)
	{
		cout << "Login: ";
		cin >> login;

		for (int i = 0; i < (int)wszyscyUzytkownicy.size(); i++)
		{
			if (login == wszyscyUzytkownicy[i].login)
			{
				nrUzytkownika = i;
				zgodnosc = false;
			}
		}

		if (zgodnosc == true)
		{
			cout << "Podany login jest nieprawidlowy, prosze sprobowac ponownie!" << endl;
		}
	}

	zgodnosc = true;

	while (zgodnosc)
	{
		cout << "Haslo: ";
		cin >> haslo;

		if (haslo == wszyscyUzytkownicy[nrUzytkownika].haslo)
		{
			zgodnosc = false;
			cout << "Udalo Ci sie zalogowac!" << endl;
			cout << "Zalogowano jako " << wszyscyUzytkownicy[nrUzytkownika].imie << " " << wszyscyUzytkownicy[nrUzytkownika].nazwisko << endl;
			imie = wszyscyUzytkownicy[nrUzytkownika].imie;
			nazwisko = wszyscyUzytkownicy[nrUzytkownika].nazwisko;
		}
		else
		{
			cout << "Podane haslo jest nieprawidlowe, sprobuj ponownie!" << endl;
		}
	}

}
