#include "stos.hh"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std ;

int main()
{
   /* 
    clock_t start = clock();  //Funkcja sprawdzająca czas wykonania
    Stos<double> S(1000);     //Operacji dodawania do stosu
    double j;
    for (j=1 ; j<=1000;j++)
    {
        S.push(j);
    }
    cout << "czas wykonywania : " << (clock()- start)/(double) CLOCKS_PER_SEC << endl;
}
 */   
    cout << "Wpisz Wielkość tablicy elementów" << endl;
    cout << "-------------------------------------- " << endl;
    int y;
    cin >> y;
    Stos<double> S(y);    //Inicjacja Stosu
    int wybor;

    cout << "Menu Stosu" << endl;
    cout << "1. Push - dodaje element na Stos" << endl;
    cout << "2. Pop - zdejmuje element ze stosu" << endl;
    cout << "3. Top - wskazuje górny element stosu" << endl;
    cout << "4. Size - wyświetla zawartość stosu" << endl;
    cout << "5. All zdejmuje wszystkie elementy" << endl;
    cout << "6. Rozm Wyświetla rozmiar tablicy" << endl;
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
        S.push(z);
        break;

        case 2: 
        S.pop();
        break;

        case 3:
        cout << "Element na szczycie to :" << S.Top() << endl; 
        break;

        case 4:
        cout << "Zawartość stosu" << endl;
        S.Size();
        break;

        case 5:
        S.All();
        break;

        case 6:
        S.Rozm();
        break;
        
        case 7:
        cout << " koniec :)" << endl;
        break;
        
    }
   
   }while (wybor!=7);
   
   
   
   
}
  
