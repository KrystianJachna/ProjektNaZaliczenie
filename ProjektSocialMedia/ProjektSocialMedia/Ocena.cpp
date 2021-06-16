#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <windows.h>
#include <winbase.h>
#include "Uzytkownik.h"
#include "Post.h"
#include "Komentarz.h"
#include "Ocena.h"

using namespace std;

void Ocena::odczytOcen(vector<Post> wszystkiePosty, vector<Ocena>& wszystkieOceny)
{
	string linia;
	Ocena tymczasowa;
	fstream plik;
	int licznik = 1, nrPosta = 0;

	for (int i = 0; i < (int)wszystkiePosty.size(); i++)
	{
		tymczasowa.numerPosta = to_string(i);
		tymczasowa.pozytywnaOcena = 0;
		tymczasowa.negatywnaOcena = 0;
		wszystkieOceny.push_back(tymczasowa);
	}

	plik.open("Oceny.txt", ios::in);

	while (getline(plik, linia, '~'))
	{
		if (licznik == 1)
		{
			tymczasowa.pozytywnaOcena = stoi(linia);
		}
		if (licznik == 2)
		{
			tymczasowa.negatywnaOcena = stoi(linia);
			licznik = 0;
			wszystkieOceny[nrPosta].pozytywnaOcena = tymczasowa.pozytywnaOcena;
			wszystkieOceny[nrPosta].negatywnaOcena = tymczasowa.negatywnaOcena;
			nrPosta++;

		}
		licznik++;
	}
}

void Ocena::dodanieOceny(vector<Ocena>& wszystkieOceny, vector<Komentarz> wszystkieKomentarze, vector<Post>& wszystkiePosty)
{
	int numerPosta;
	string str_numerPosta;
	string dodanie, ocena;
	bool znalezionyPost = false;
	ofstream plik;

	cout << endl << "Ktory post chcialbys ocenic?";
	cin >> numerPosta;

	str_numerPosta = to_string(numerPosta);

	numerPosta = numerPosta - 1;

	system("cls");

	cout << "Uzytkownik " << wszystkiePosty[numerPosta].imie << " " << wszystkiePosty[numerPosta].nazwisko << endl;
	cout << wszystkiePosty[numerPosta].trescPosta << endl;
	cout << "--------------------[+" << to_string(wszystkieOceny[numerPosta].pozytywnaOcena) << "|-" << to_string(wszystkieOceny[numerPosta].negatywnaOcena) << "]--------------------" << endl << endl;

	for (int i = 0; i < (int)wszystkieKomentarze.size(); i++)
	{
		if (wszystkieKomentarze[i].numerPosta == str_numerPosta)
		{
			znalezionyPost = true;
		}
	}
	numerPosta = numerPosta + 1;

	if (znalezionyPost)
	{
		cout << "===SEKCJA KOMENTARZY===" << endl << endl;
		cout << wszystkieKomentarze[numerPosta - 1].trescKomentarza;
	}
	else
	{
		cout << endl << "Post nie nie ma jeszcze komentarzy" << endl << endl;
	}

	numerPosta = numerPosta - 1;
	cout << "Ocen post wpisujac [+/-]: ";
	cin >> ocena;

	if (ocena == "+")
	{
		wszystkieOceny[numerPosta].pozytywnaOcena += 1;
	}
	if (ocena == "-")
	{
		wszystkieOceny[numerPosta].negatywnaOcena += 1;
	}

	plik.open("Oceny.txt");

	for (int i = 0; i < wszystkieOceny.size(); i++)
	{
		plik << wszystkieOceny[i].pozytywnaOcena << "~" << wszystkieOceny[i].negatywnaOcena << "~";
	}

	plik.close();
}

