#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <windows.h>
#include <winbase.h>
#include "Uzytkownik.h"
#include "Post.h"
#include "Komentarz.h"

using namespace std;

void Komentarz::zapisKomentarza(vector<Komentarz> wszystkieKomentarze, vector<Post> wszystkiePosty, Uzytkownik zalogowany)
{
	int numerPosta;
	string str_numerPosta;
	string dodanie;
	bool znalezionyPost = false;

	cout << endl << "Ktory post chcialbys skomentowac?";
	cin >> numerPosta;

	str_numerPosta = to_string(numerPosta);

	numerPosta = numerPosta - 1;

	system("cls");

	cout << "Uzytkownik " << wszystkiePosty[numerPosta].imie << " " << wszystkiePosty[numerPosta].nazwisko << endl;
	cout << wszystkiePosty[numerPosta].trescPosta << endl << "--------------------------------------------------" << endl << endl;
	
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
		system("cls");
		cout << "Uzytkownik " << wszystkiePosty[numerPosta - 1].imie << " " << wszystkiePosty[numerPosta - 1].nazwisko << endl;
		cout << wszystkiePosty[numerPosta - 1].trescPosta << endl << endl;
		cout << "===SEKCJA KOMENTARZY===" << endl << endl;
		cout << wszystkieKomentarze[numerPosta - 1].trescKomentarza;
		//tutaj dodac ocene posta
	}
	else
	{
		cout << endl << "Post nie nie ma jeszcze komentarzy" << endl << endl;
	}

	numerPosta = numerPosta - 1;

	cout << "Napisz co o tym myslisz o poscie " << wszystkiePosty[numerPosta].imie << "?" << endl << "Jezeli chcesz zakonczyc wpisywanie komentarza napisz '>' po czym wcisnij enter" << endl << endl;
	getline(cin, trescKomentarza, '>');
	cout << "Czy na pewno chcesz dodac komentarz ? (tak/nie): " << endl;
	cin >> dodanie;

	numerPosta += 1;

	if (dodanie == "tak")
	{
		ofstream plik("Komentarze.txt", ios_base::app);
		plik << numerPosta << "~" << zalogowany.imie << " " << zalogowany.nazwisko << " napisal: " << trescKomentarza <<  endl <<"---------------------------"<< endl << "~";
		
		cout << endl << "Twoj komentarz zostal pomyslnie dodany!";
	}
	else
	{
		cout << "Wroc jesli, bedziesz chcial skomentowac!";
	}

}

void Komentarz::odczytKomentarzy(vector<Post> wszystkiePosty, vector<Komentarz>& wszystkieKomentarze)
{
	wszystkieKomentarze.clear();

	Komentarz tymczasowy;
	string linia, nrPosta;
	fstream plik;
	int licznik = 1, liczbaKom = 0;
	bool pushuj = false;

	plik.open("Komentarze.txt", ios::in);

	while (getline(plik, linia, '~'))
	{
		liczbaKom += 1;
	}

	plik.close();

	for (int i = 0; i < liczbaKom/2; i++)
	{
		plik.open("Komentarze.txt", ios::in);

		while (getline(plik, linia, '~'))
		{
			if (linia == wszystkiePosty[i].numerPosta)
			{
				tymczasowy.numerPosta = linia;
				pushuj = true;
			}
			if (licznik % 2 == 0 && pushuj == true)
			{
				tymczasowy.trescKomentarza += linia;
				pushuj = false;
			}
			licznik++;
		}

		if (tymczasowy.trescKomentarza.length() != 0)
		{
			wszystkieKomentarze.push_back(tymczasowy);
		}

		tymczasowy.trescKomentarza = "";
		tymczasowy.numerPosta = "";
		plik.close();
	}
}

void Komentarz::pokazKomentarze(vector<Komentarz> wszystkieKomentarze, vector<Post> wszystkiePosty)
{
	string nrPosta;
	bool znalezionyPost = false;

	cout << "Wybierz posta ktorego komentarze chcialbys wyswietlic ";
	cin >> nrPosta;
	
	for (int i = 0; i < (int)wszystkieKomentarze.size(); i++)
	{
		if (wszystkieKomentarze[i].numerPosta == nrPosta)
		{
			znalezionyPost = true;
		}
	}
	
	int nrP = stoi(nrPosta);

	if (znalezionyPost) 
	{
		system("cls");
		cout << "Uzytkownik " << wszystkiePosty[nrP-1].imie << " " << wszystkiePosty[nrP-1].nazwisko << endl;
		cout << wszystkiePosty[nrP-1].trescPosta << endl << endl;
		cout << "===SEKCJA KOMENTARZY===" << endl << endl;
		cout << wszystkieKomentarze[nrP-1].trescKomentarza;
		//tutaj dodac ocene posta
	}
	else
	{
		cout << endl << "Post nie nie ma jeszcze komentarzy" << endl<<endl;
	}
	
}