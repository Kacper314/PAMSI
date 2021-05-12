#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include "sortowania.hh"


using namespace std;

int main() {

    int ROZMIAR;
    cin >> ROZMIAR;

    Film *sort;
    sort = new (nothrow) Film [ROZMIAR];
    
    // string *tytul;
    // tytul = new string [ROZMIAR];


    // int *ocena;
    // ocena = new int [ROZMIAR];

    // int *porzadkowa;
    // porzadkowa = new int [ROZMIAR];

    
// Tablice pomocnicze to sortowania przez scalanie
//     int *pomocnicza;
//     pomocnicza = new int [ROZMIAR];

//     string *pomocnicza1;
//     pomocnicza1 = new string [ROZMIAR];

    clock_t start , stop;                    //Zmienne potrzebne to pomiaru czasu sortowania
    double czas;

    fstream plik;
    plik.open("/home/kacper/Pulpit/Lab2_Pamsi12/rezultat.txt" , ios::in);   //Otwearcie pliku

    if(plik.good()==false) {                    //Funkcja sprawdza czy poprawnie wczytano plik
        cout << "Plik nie istnieje" << endl;
        exit(0);
    }
    string linia;
    int numer=0;
    srand(time(NULL));

    
    while(!plik.eof())           //Dopóki kolejna linia w pliku nie będzie pusta
    {
        getline(plik , linia , ';');
        sort[numer].porzadkowa = atof(linia.c_str());

        getline(plik,linia,';');                //Pobieranie lini do znaku ;
        sort[numer].tytul = linia;
        
        getline(plik,linia);                    //Pobieranie lini od znaku ; do końca
        sort[numer].wynik = atof(linia.c_str());
        
        numer++;
    }
    
    plik.close();

    start = clock();                                                //Wywolywanie funkcji
    //quicksort(sort , 0 , numer - 1 );
    scalanie(sort , pomocnicza , pomocnicza1 ,0, numer -1);
    //kubelkowe( sort , numer , 0 , 11);
    //Shell(sort , numer);
    stop = clock();

    fstream plik2;
    plik2.open("/home/kacper/Pulpit/Lab2_Pamsi12/wynik.txt" , ios::out);         //Zapis posortowanych danych do pliku


    cout << "Ilość tytułów :  " << numer << endl;       //Wyświetlanie zawartości tablic

    for (int i=0 ; i<numer ; i++) {
        plik2 << sort[i].porzadkowa << " ; " << sort[i].tytul << " ; "  << sort[i].wynik << endl;
    }
    
    
    plik2.close();

    
    czas = (double)(stop-start)/CLOCKS_PER_SEC;
    cout << "czas sortowania : " << czas << "s" << endl;
   


    return 0;
}
