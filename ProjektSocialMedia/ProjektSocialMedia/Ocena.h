#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include "Uzytkownik.h"
#include "Post.h"
#include "Komentarz.h"

using namespace std;

class Ocena :public Post
{
public:

	int pozytywnaOcena, negatywnaOcena;

	void odczytOcen(vector<Post> wszystkiePosty, vector<Ocena> &wszystkieOceny);
	void dodanieOceny(vector<Ocena>& wszystkieOceny, vector<Komentarz> wszystkieKomentarze, vector<Post> &wszystkiePosty);
};
