#include "sortowania.hh"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>

using namespace std;


void quicksort(Film *tab , int lewy , int prawy)
{
     int x = tab[(lewy+prawy)/2].wynik;   //Wyznaczanie środka
     int i , j , a;                 // Po podzielniu tutaj przypisujemy
     i = lewy;                      //  odpowiednie wartości tablic 
     j = prawy;

     do {
         while(tab[i].wynik < x) i++;
         while(tab[j].wynik > x) j--;
         if (i<=j)
         {
            a = tab[i].wynik;
            tab[i].wynik = tab[j].wynik;
            tab[j].wynik = a;
            swap(tab[i].tytul,tab[j].tytul);
            i++;
            j--;
         }
     }while(i<=j);

     if(j > lewy)
     {
         quicksort(tab ,  lewy , j);
     }
     if(i < prawy)
     {
         quicksort(tab , i , prawy);
     }
}



void scal(Film *tablica , int *tab1 , string *pom ,int pierwszy , int ostatni)
{
    
    int i , j ;
    int s = (pierwszy + ostatni)/2;              
    i = pierwszy;
    j = s + 1;

    for (int i = pierwszy ; i<= ostatni ; i++)
    {
        tab1[i] = tablica[i].wynik;
        pom[i] = tablica[i].tytul; 
    }

    for(int k = pierwszy ; k<= ostatni ; k++)
    {
        if(i <= s) {
            if (j <= ostatni) {
                if(tab1[j] < tab1[i])
                {
                    tablica[k].wynik = tab1[j];
                    tablica[k].tytul = pom[j];
                    j++;
                }
                else 
                {
                    tablica[k].wynik = tab1[i];
                    tablica[k].tytul = pom[i];
                    i++;
                    
                }
            }else 
            {
                tablica[k].wynik = tab1[i];
                tablica[k].tytul = pom[i];
                i++;
                
            }
        }else {
            tablica[k].wynik = tab1[j];
            tablica[k].tytul = pom[j];
            j++;
            
        }
        
    }
    
    
}


void scalanie (Film *tab , int *tab1 , string *pom , int pierwszy , int ostatni)
{
    if (pierwszy < ostatni)  {
    int s = (pierwszy + ostatni) / 2;
    scalanie(tab , tab1 ,  pom ,pierwszy , s);
    scalanie(tab , tab1 , pom ,s+1 , ostatni);
    scal(tab , tab1 , pom ,pierwszy , ostatni);
    }
}


void kubelkowe(Film *tablica , int N , int Min , int Max)
{
    Film *pom = new (nothrow) Film[Max - Min + 1];
    Film *nowa = new (nothrow) Film[Max  - Min + 1]; 
    
    //Wstawianie początkowych wartości
    //Wyzerowanie
    for (int x = Min ; x < Max ; x++)
    {
        pom[x - Min].wynik = 0;
                
    }

    //Zliczanie ilości powtórzeń elementów
    for (int x = 0 ; x < N ; x++)
    {
        pom[tablica[x].wynik - Min].wynik++;
        
    }

    //Zapisywanie elementów w tablicy
    int y = 0;
    for (int x = 0 ; x < Max ; x++)
    {
        while(pom[x - Min].wynik--)
        {
            tablica[y].wynik = x;
            //swap(tablica[y].tytul,tablica[x].tytul);
            y++;
            
        }
        swap(tablica[x].tytul,tablica[Max].tytul);
        
    }
}

void Shell(Film *tab , int a)
{
    int s = a / 2 ;
    while(s >= 1)
    {
        for (int i = s ; i < a ; i++)
        {
            Film tmp = tab[i];
            int j;
            for ( j = i ; j>=s && tab[j - s].wynik > tmp.wynik; j -= s)
                tab[j] = tab[j - s];
                tab[j] = tmp;
        }
        s /= 2;
    }
}


// int main ()
// {
//     int ile;
//     clock_t start,stop;
//     double czas;
//     cout << "ile liczb w tablicy";
//     cin>>ile;

//     //Dynamiczna alokacja tablicy

//     int *tablica1;
//     tablica1 = new int [ile];

//     // int *pom;                /* Tablica pomocnicza do sortowania przez scalanie */
//     // pom = new int [ile];

//     srand(time(NULL));


//     for(int i=0 ; i<ile ; i++)
//     {
//         tablica1[i] = rand()%100000+1;
//         cout << tablica1[i] << " ";
//     }
//     cout<<endl;
//     cout << "Rozpoczyna się sortowanie" << endl;

//     start = clock();

//     //quicksort(tablica1,0,ile -1);
//     //scalanie(tablica1,pom,0,ile-1);
//     kubelkowe(tablica1 ,  ile , 0 , 100000);

//     stop = clock ();
//     czas = (double)(stop-start)/CLOCKS_PER_SEC;
//     cout << "po posortowaniu" << endl;
//     for(int i=0 ; i<ile ; i++)
//     {
        
//         cout << tablica1[i] << " ";
//     }
//     cout << endl << "Czas sortowania" << endl <<czas << "s" << endl;
//     delete [] tablica1;
//     return 0;
// }

