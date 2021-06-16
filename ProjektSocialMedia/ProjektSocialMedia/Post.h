#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include "Uzytkownik.h"


class Post :public Uzytkownik
{
public:

	string trescPosta;
	string numerPosta;

	void zapisPosta(vector<Post> wszystkiePosty, Uzytkownik zalogowany);
	void odczytPostow(vector<Uzytkownik> wszyscyUzytkownicy, vector<Post> &wszystkiePosty); //zawsze po zapisiePosta
	void wyswietlPosty(vector<Post> wszystkiePosty);
};