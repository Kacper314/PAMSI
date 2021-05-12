#ifndef SORTOWANIA_HH
#define SORTOWANIA_HH

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct Film
{
    string tytul;
    int wynik;
    float porzadkowa;
};


    void quicksort(Film *tab, int lewy , int prawy);
   
    
    void scalanie (Film *tab , int *tab1 , string *pom , int pierwszy , int ostatni);
   
    void kubelkowe(Film *tablica , int N , int Min , int Max);

   
    void scal(Film *tablica , int *tab1 , string *pom ,int pierwszy , int ostatni);
    void Shell(Film *tab , int a);


#endif