#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <windows.h>
#include <winbase.h>
#include "Uzytkownik.h"
#include "Post.h"

using namespace std;

void Post::zapisPosta(vector<Post> wszystkiePosty, Uzytkownik zalogowany)
{
	system("cls");

	SYSTEMTIME st;
	GetSystemTime(&st);

	string trescPosta;
	string dodanie;
	
	int numerPosta = wszystkiePosty.size() + 1;

	cout << "O czym myslisz, " << zalogowany.imie << "?" << endl << "Jezeli chcesz zakonczyc wpisywanie posta napisz '>' po czym wcisnij enter" << endl << endl;
	getline(cin, trescPosta, '>');
	cout << "Czy na pewno chcesz umiescic post na swojej tablicy? (tak/nie): " << endl;
	cin >> dodanie;

	if (dodanie == "tak")
	{
		ofstream plik("Posty.txt", ios_base::app);
		plik << numerPosta << "~" << zalogowany.imie << "~" << zalogowany.nazwisko << "~";
		if (st.wDay < 10 && st.wMonth>10)
		{
			plik << "Post z [0" << st.wDay << ", " << st.wMonth << ", " << st.wYear << "r godz. " << st.wHour << ":" << st.wMinute << "]" << endl;
		}
		if (st.wMonth < 10 && st.wDay >10)
		{
			plik << "Post z [" << st.wDay << ", 0" << st.wMonth << ", " << st.wYear << "r godz. " << st.wHour << ":" << st.wMinute << "]" << endl;
		}
		if (st.wMonth < 10 && st.wDay < 10)
		{
			plik << "Post z [0" << st.wDay << ", 0" << st.wMonth << ", " << st.wYear << "r godz. " << st.wHour << ":" << st.wMinute << "]" << endl;
		}
		if (st.wMonth > 10 && st.wDay > 10)
		{
			plik << "Post z [" << st.wDay << ", " << st.wMonth << ", " << st.wYear << "r godz. " << st.wHour << ":" << st.wMinute << "]" << endl;
		}
		plik << trescPosta << "~";
		cout << endl << "Twoj post zostal dodany na twoja tablice!";
		plik.close();
	}
	else
	{
		cout << "Wroc jesli, zmienisz zdanie!";
	}
}

void Post::odczytPostow(vector<Uzytkownik> wszyscyUzytkownicy, vector<Post> &wszystkiePosty)
{
	wszystkiePosty.clear();

	Post pojedynczyPost;
	string linia;
	fstream plik;
	int licznik = 1, nrUzytkownika = 0;
	plik.open("Posty.txt", ios::in);

	if (plik.good() == false)
	{
		cout << "Nie udalo sie zaladowac postow!";
		exit(0);
	}
	while (getline(plik, linia, '~'))
	{
		if (licznik == 1)
		{
			pojedynczyPost.numerPosta = linia;
		}
		if (licznik == 2)
		{
			for (int i = 0; i < (int)wszyscyUzytkownicy.size(); i++)
			{
				if (wszyscyUzytkownicy[i].imie == linia)
				{
					nrUzytkownika = i;
					pojedynczyPost.imie = wszyscyUzytkownicy[i].imie;
				}
			}
		}
		if (licznik == 3)
		{
			pojedynczyPost.nazwisko = linia;
		}
		if (licznik == 4)
		{
			pojedynczyPost.trescPosta = linia;

			if (wszyscyUzytkownicy[nrUzytkownika].nazwisko == pojedynczyPost.nazwisko)
			{
				wszystkiePosty.push_back(pojedynczyPost);

			}
			licznik = 0;
			nrUzytkownika = 0;
			pojedynczyPost.imie = "";
			pojedynczyPost.nazwisko = "";
			pojedynczyPost.trescPosta = "";
		}
		licznik++;
	}
	plik.close();
}

void Post::wyswietlPosty(vector<Post> wszystkiePosty)
{
	cout << "Tablica postow wszystkich uzytkownikow" << endl << endl;

	for (int i = 0; i < wszystkiePosty.size(); i++)
	{
		cout << wszystkiePosty[i].numerPosta << ". Uzytkownik " << wszystkiePosty[i].imie << " " << wszystkiePosty[i].nazwisko << endl;
		cout << wszystkiePosty[i].trescPosta << endl << "--------------------------------------------------" << endl << endl;
		//tutaj gdzies trzeba dodac ocene
	}
}


