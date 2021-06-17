#include <iostream>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <cmath>
#include "gra.hh"

using namespace std;


//Funkcja inicjalicuje tablicę do gry
void Start( char tab[ROZMIAR][ROZMIAR])  
{

    for (int i = 0 ; i < ROZMIAR ; i++)
    {
        for (int j = 0 ; j < ROZMIAR ; j++)
        {
            tab[i][j] = ' ';  //Wypełnienie tablicy pustymi polami
        }
    }
}

//Funkcja wyświetla Planszę do gry w zależności od Wymiaru
void Plansza(char tab[ROZMIAR][ROZMIAR]) 
{

    for (int i = 0 ; i < ROZMIAR ; i++)
    {
        cout << "\n |";
        for (int j = 0 ; j < ROZMIAR ; j++)
        {
            cout << setw(2) << tab[i][j] << setw(2) << " |"; 
        }

        cout << endl;

    }
    cout << endl;
}

//Funckja pokazuje kto wygrał
void Wygrany(int Tura)
{
    if (Tura == Bot)
    {
        cout << "Bot cię pokonał" << endl;
    }
    else
    {
        cout << "Wygrałeś z Botem" << endl;
    }
}

//Funckja sprawdza wygraną w wierszach
//Kolejne 4 poniższe funkcję wraz z KoniecGry() sprawdzają się tylko w przypadku 3x3 
bool WygranaWiersz(char tab[ROZMIAR][ROZMIAR])
{

    for (int i = 0 ; i < ROZMIAR ; i++)
    {
        if( tab[i][0] == tab[i][1] && tab[i][1] == tab[i][2] && tab[i][0] != ' ' )
        {
            return (true); //Funkcja zwraca wartość true gdy wartości w wierszach to te same znaki
        }
        
    }

    return(false);
}

// //Funckja sprawdza wygraną w kolumnach 
bool WygranaKol(char tab[ROZMIAR][ROZMIAR]) 
{

    for (int i = 0 ; i < ROZMIAR ; i++)
    {
        if( tab[0][i] == tab[1][i] && tab[1][i] == tab[2][i] && tab[0][i] != ' ' )
        {
            return (true); //Funkcja zwraca wartość true gdy wartości w kolumnach to te same znaki
        }
        
    }
    return(false);

}

// //Funckja sprawdza wygraną na przkątnych 
bool WygranaPrzek(char tab[ROZMIAR][ROZMIAR])
{
    if (tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2] && tab[0][0] != ' ')
    {
        return(true);
    }
    if (tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0] && tab[0][2] != ' ')
    {
        return(true); //Funkcja zwraca wartość true gdy wartości w diagonalach to te same znaki
    }
    
    return(false);
}

//Funkcja zwraca wartośc true gdy nastapił koniec gry (ktoś wygrał)
bool KoniecGry(char tab[ROZMIAR][ROZMIAR])
{
    return(WygranaKol(tab) || WygranaPrzek(tab) || WygranaWiersz(tab));
} 

//Inny sposób sprawdzania Wygranej
//Znajduję on zastosowanie dla dowolnego Rozmiaru planszy
//W tej funkcji znajdują się warunki zwycięstwa dla wierszy oraz kolumn
bool Zwyciestwo(char tab[ROZMIAR][ROZMIAR])
{
    //Wiersze
    for (int i = 0 ; i < ROZMIAR ; i++ ) 
    {
        int licznik = 0;
        for (int j = 0 ; j < ROZMIAR ; j++)
        {
            if(tab[i][j] == 'O')
            {
                licznik++;
            }
        }

        if(licznik == ROZMIAR)
        {
            return(true);
        }
    }

    for (int i = 0 ; i < ROZMIAR ; i++ ) 
    {
        int licznik = 0;
        for (int j = 0 ; j < ROZMIAR ; j++)
        {
            if(tab[i][j] == 'X')
            {
                licznik++;
            }
        }

        if(licznik == ROZMIAR)
        {
            return(true);
        }
    }

    //Kolumny
    for (int i = 0 ; i < ROZMIAR ; i++ ) 
    {
        int licznik = 0;
        for (int j = 0 ; j < ROZMIAR ; j++)
        {
            if(tab[j][i] == 'O')
            {
                licznik++;
            }
        }

        if(licznik == ROZMIAR)
        {
            return(true);
        }
    }

    for (int i = 0 ; i < ROZMIAR ; i++ ) 
    {
        int licznik = 0;
        for (int j = 0 ; j < ROZMIAR ; j++)
        {
            if(tab[j][i] == 'X')
            {
                licznik++;
            }
        }

        if(licznik == ROZMIAR)
        {
            return(true);
        }
    }

    return(false); 
}


//Funckja sprawdza czy partia została wygrana na prawej przekątnej
bool PrawyDiagonal(char tab[ROZMIAR][ROZMIAR])
{

    int licznik = 0;
    int licznik1 = 0;
    for (int i = 1 ; i < ROZMIAR ; i++)
    {
        if(tab[ROZMIAR - i][i - 1] != tab[ROZMIAR - i - 1][i])
        {
            licznik++;
        } 
        
    }
    if (licznik == 0 &&  (tab[ROZMIAR - 1][0] == 'O' || tab[ROZMIAR - 1][0] == 'X' ))
    {
        return(true);
    }

return(false);


 }

//Funkcja sprwdza  czy partia została wygrana na lewej przekątnej
bool LewyDiagonal(char tab[ROZMIAR][ROZMIAR])
{
    int licznik = 0;
    int licznik1 = 0;
    for (int i = 0 ; i < ROZMIAR ; i++)
    {
        if(tab[i][i] == 'O')
        {
            licznik++;
        }
    }
    if (licznik == ROZMIAR)
    {
        return(true);
    }

    for(int j = 0 ; j < ROZMIAR ; j++)
    {
        if(tab[j][j] == 'X')
        {
            licznik1++;
        }
    }
    if(licznik1 == ROZMIAR)
    {
        return(true);
    }

    return(false);

}

//Funkcja sprawdza wszystkie opcje zwycięstwa i zwraca wartość true gdy
//któraś została spełniona
bool Koniec(char tab[ROZMIAR][ROZMIAR])
{
    return(Zwyciestwo(tab) || LewyDiagonal(tab) || PrawyDiagonal(tab));
}

//Algorytm Minimax z cięciami alfa beta
int MiniMax( char tab[ROZMIAR][ROZMIAR] , int glebokosc , bool isMax , int alfa , int beta)
{
    int score = 0;
    int bestscore = 0;
    int Min = -999;
    int Max = 999;


    if (Koniec(tab) == true)
    {
        if (isMax == true)
        {
            return -1;
        }
        if (isMax == false)
        {
            return 1;
        }
    }
    else
    {
        if(glebokosc < ROZMIAR*ROZMIAR)
        {
    
            if (isMax == true)
            {
                bestscore = Min;
                for (int i = 0 ; i < ROZMIAR ; i++)
                {
                    for (int j = 0 ; j < ROZMIAR ; j++)
                    {
                        if(tab[i][j] == ' ')
                        {
                            tab[i][j] = Komp;
                            score = MiniMax(tab, glebokosc + 1 , false , alfa , beta);
                            tab[i][j] = ' ';
                            bestscore = max(bestscore , score);
                            alfa = max(alfa , bestscore);
                            if(beta <= alfa)
                            {
                                break;
                            }
                        }
                    }
                }
                return bestscore;
            }
            else
            {
                bestscore = Max;
                for (int i = 0 ; i < ROZMIAR ; i++)
                {
                    for (int j = 0; j < ROZMIAR ; j++)
                    {
                        if (tab[i][j] == ' ')
                        {
                            tab[i][j] = Czlowiek;
                            score = MiniMax(tab , glebokosc + 1 , true , alfa , beta);
                            tab[i][j] = ' ';
                            bestscore = min(bestscore , score);
                            beta = min(beta , bestscore);
                            if (beta <= alfa)
                            {
                                break;
                            }
                        }
                    }
                }
                return bestscore;
            }
        }
        else
        {
            return 0;
        }
    }
}

//Funckja wybierająca najlepszy ruch na podstawwie Algorytmu minimax
int Ruch(char tab[ROZMIAR][ROZMIAR] , int wykonajruch , int alfa , int beta)
{
    int x = -1;
    int y = -1;
    int score;
    int BestScore = -999;

    for (int i = 0 ; i < ROZMIAR ; i++)
    {
        for (int j = 0 ; j < ROZMIAR ; j++)
        {
            if (tab[i][j] == ' ')
            {
                tab[i][j] = Komp;
                score = MiniMax(tab , wykonajruch + 1 , false , alfa , beta );
                tab[i][j] = ' ';
                alfa = max(alfa , BestScore);
                if(beta <= alfa)
                {
                    break;
                }
                if (score > BestScore)
                {
                    BestScore = score ;
                    x = i;
                    y = j;
                }

            }
        }
    }
    return x*ROZMIAR+y;
}

//Funckaj Graj dotyczy stawiania ruchów przez bota i człowieka. 
void Graj(int Tura)
{
    char tab[ROZMIAR][ROZMIAR];
    int index = 0 , x = 0 , y = 0;
    int Min = -999;
    int Max = 999;

    Start(tab);

    //Gra się toczy dopóki ktoś wygra bądź będzie remis
    while(Koniec(tab) == false && index != ROZMIAR*ROZMIAR) //Koniec Gry
    {
        int k;
        if(Tura == Bot)
        {
            k = Ruch(tab , index , Min , Max);
            x = k / ROZMIAR;
            y = k % ROZMIAR;
            tab[x][y] = Komp;
            cout << "Komputer postawił:    " <<   Komp   <<  "      W komórce:   "  <<  k+1   << endl;
            Plansza(tab);
            index ++;
            Tura = Man;
        }
        else if (Tura == Man)
        {
            cout << "Wybierz gdzie chcesz postawić znak" << endl;
            cin >> k;
            k--;
            x = k / ROZMIAR;
            y = k % ROZMIAR;
            if (tab[x][y] == ' ' && k < ROZMIAR*ROZMIAR && k >=0)
            {
                tab[x][y] = Czlowiek;
                cout << "Postawiłeś:    " <<   Czlowiek   <<   "        W komórce:    "   <<   k+1   << endl;
                Plansza(tab);
                index ++;
                Tura = Bot;
            }
            else if (tab[x][y] != ' ' && k < ROZMIAR*ROZMIAR && k>=0)
            {
                cout << "Wybrałeś zajęte pole , wybierz inne" <<  endl;
            }
            else if (k < 0 || k > ROZMIAR*ROZMIAR)
            {
                cout << "Wybrałeś złą pozycje" << endl;
            }        
        }
    }
    //Sprawdzanie remisu
    if (Koniec(tab) == false && index == ROZMIAR*ROZMIAR) //Koniec Gry
    {
        cout << "Mamy Remis :-)" << endl;
    }
    else
    {
        if (Tura == Bot) 
        {
            Tura = Man;
        }
        else if (Tura == Man)
        {
            Tura = Bot;
        }

        Wygrany(Tura);
    }
}

