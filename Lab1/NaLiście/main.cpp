#include "lstos.hh"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std ;

int main()
{
   /* 
    clock_t start = clock();     //Funkcja sprawdzająca czas wykonania 
    lstos<double> S;                //Operacji dodawania do stosu
    for (double j=0 ; j<=1000;j++)
    {
        S.Push(j);
    }
    cout << "czas wykonywania : " << (clock() - start)/(double) CLOCKS_PER_SEC << endl;
}
   */
   
   

    lstos<double> S;    //Inicjacja Listy
    int wybor;

    cout << "Menu Stosu" << endl;
    cout << "1. Push - dodaje element na Stos" << endl;
    cout << "2. Pop - zdejmuje element ze stosu" << endl;
    cout << "3. Top - wskazuje górny element stosu" << endl;
    cout << "4. Wypisz - wyświetla zawartość stosu" << endl;
    cout << "5. All - zdejmuje wszystkie elementy" << endl;
    cout << "6. size - Wyświetla rozmiar tablicy" << endl;
    cout << "7. Koniec Programu" << endl;
    

   do
   {
    cout << "Wprowadź swój wybór :" << endl;
    cin >> wybor;
    switch (wybor)
    {
        case 1: 
        double z;
        cout << "Wprowadź wartość którą chcesz dodać do stosu" << endl;
        cin >> z;
        S.Push(z);
        break;

        case 2: 
        S.pop();
        break;

        case 3:
        cout << "Element na szczycie to :" << S.Top() << endl; 
        break;

        case 4:
        cout << "Zawartość stosu" << endl;
        S.Wypisz();
        break;

        case 5:
        S.All();
        break;

        case 6:
        S.size();
        break;
        
        case 7:
        cout << " koniec :)" << endl;
        break;
        
    }
   
   }while (wybor!=7);
   
}

