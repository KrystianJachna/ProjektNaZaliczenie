#include <iostream>
#include <vector>
#include <string>
#include "Uzytkownik.h"
#include "Post.h"
#include "Komentarz.h"
#include "Ocena.h"

using namespace std;

vector<Uzytkownik> wszyscyUzytkownicy;
vector<Post> wszystkiePosty;
vector<Komentarz> wszystkieKomentarze;
vector<Ocena> wszystkieOceny;

int main()
{
	string siema;
	Komentarz test;
	Uzytkownik zalogowany;
	Ocena test2;

	zalogowany.Wczytywanie(wszyscyUzytkownicy);
	zalogowany.Logowanie(wszyscyUzytkownicy);


	Post nowyPost;
	nowyPost.odczytPostow(wszyscyUzytkownicy, wszystkiePosty);
	//nowyPost.zapisPosta(wszystkiePosty, zalogowany);
	test2.odczytOcen(wszystkiePosty, wszystkieOceny);
	nowyPost.wyswietlPosty(wszystkiePosty);
	//test.zapisKomentarza(wszystkiePosty, zalogowany);
	test.odczytKomentarzy(wszystkiePosty, wszystkieKomentarze);
	//test.pokazKomentarze(wszystkieKomentarze, wszystkiePosty);
	//test2.odczytOcen(wszystkiePosty, wszystkieOceny);
	test2.dodanieOceny(wszystkieOceny, wszystkieKomentarze, wszystkiePosty);
	cin >> siema;



	//cout << endl <<wszystkiePosty[1].numerPosta << endl;
	//cout << wszystkiePosty[1].imie << endl;
	//cout << wszystkiePosty[1].nazwisko << endl;
	//cout << wszystkiePosty[1].trescPosta << endl;

	//nowyPost.wyswietlPosty(wszystkiePosty);
	//test.zapisKomentarza(wszystkiePosty, zalogowany);
	//test.odczytKomentarzy(wszystkiePosty, wszystkieKomentarze);
	//test.pokazKomentarze(wszystkieKomentarze, wszystkiePosty);
	//cin >> siema;
	//nowyPost.zapisPosta(wszystkiePosty, zalogowany);
	//






	/*Uzytkownik uzytkownik;
	uzytkownik.Wczytywanie(wszyscyUzytkownicy);
	uzytkownik.Rejestracja(wszyscyUzytkownicy);*/













	/*Uzytkownik uzytkownik;
	wszyscyUzytkownicy = uzytkownik.Wczytywanie();
	wszyscyUzytkownicy.push_back(uzytkownik.Rejestracja(wszyscyUzytkownicy));
	wszyscyUzytkownicy = uzytkownik.Wczytywanie();
	uzytkownik.Logowanie(wszyscyUzytkownicy);*/
	return 0;
}