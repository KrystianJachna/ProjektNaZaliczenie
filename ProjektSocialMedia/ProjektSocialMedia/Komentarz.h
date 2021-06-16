#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include "Uzytkownik.h"
#include "Post.h"

class Komentarz :public Post
{
public:

	string trescKomentarza;

	void zapisKomentarza(vector<Komentarz> wszystkieKomentarze, vector<Post> wszystkiePosty, Uzytkownik zalogowany); //po zapisie zawsze odczyt
	void odczytKomentarzy(vector<Post> wszystkiePosty, vector<Komentarz> &wszystkieKomentarze);
	void pokazKomentarze(vector<Komentarz> wszystkieKomentarze, vector<Post> wszystkiePosty);

	
};
