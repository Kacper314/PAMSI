#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
//#define ROZMAIR 150000              //Definicja Rozmiaru Tablicy

using namespace std;

int main() {

    cout << "Wpisz wielkość : " << endl;
    int ROZMIAR;
    cin >> ROZMIAR;
    
    string *tytul;
    tytul = new string [ROZMIAR];


    float *ocena;
    ocena = new float [ROZMIAR];

    float *porzadkowa;
    porzadkowa = new float [ROZMIAR];

    clock_t start , stop;
    double czas;

    fstream plik;
    plik.open("/home/kacper/Pulpit/Lab2_Pamsi12/spis.txt" , ios::in);   //Otwearcie pliku

    if(plik.good()==false) {                    //Funkcja sprawdza czy poprawnie wczytano plik
        cout << "Plik nie istnieje" << endl;
        exit(0);
    }
    string linia;
    int numer=0;
    srand(time(NULL));

    start = clock();
    while(!plik.eof())           //Dopóki kolejna linia w pliku nie będzie pusta
    {
        getline(plik , linia , ';');
        porzadkowa[numer] = atof(linia.c_str());

        getline(plik,linia,';');                //Pobieranie lini do znaku ;
        tytul[numer] = linia;
        
        getline(plik,linia);                    //Pobieranie lini od znaku ; do końca
        ocena[numer] = atof(linia.c_str());
        if(ocena[numer]=='\0') {
            numer--;
            
        }
        numer++;
    }
    
    plik.close();

    fstream plik2;
    plik2.open("/home/kacper/Pulpit/Lab2_Pamsi12/rezultat.txt" , ios::out);


    cout << "Ilość tytułów :  " << numer << endl;       //Wyświetlanie zawartości tablic

    for (int i=0 ; i<numer ; i++) {
        plik2 << porzadkowa[i] << " ; " << tytul[i] << " ; "  << ocena[i] << endl;
    }
    
    plik2.close();

    stop = clock();
    czas = (double)(stop-start)/CLOCKS_PER_SEC;
    cout << "czas sortowania : " << czas << "s" << endl;
    
    return 0;
}