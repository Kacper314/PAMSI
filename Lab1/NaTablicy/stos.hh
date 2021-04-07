#ifndef STOS_HH
#define STOS_HH

#include <iostream>

using namespace std;

template <typename Object>
class Stos
{
private:
    int size;       //Rozmiar Stosu
    int top;        //Pierwszy element na stosie
    int l=0;        //Liczba elementów na stosie
    Object *tab;    //Tablice do przechowywania danych
    Object *nowa;   //Zmienna pomocnicza
public:
    Stos(int x);                    //Konstruktor
    ~Stos();                        //Destruktor
    void push(Object &element);     //Metoda dodająca element na stos
    Object pop();                   //Metoda zdejmujaca element ze stosu
    void Size();                    //Metoda wypisuje elementy ze stosu
    bool empty() const;             //Metoda sptawdzająca czy stos jest pusty
    Object Top();                  //Metoda wskazująca szczyt stosu
    void All();                     //Zdejmuje wszystkie elementy ze stosu
    void Rozm();                    //Wyswietla rozmiar Tablicy
    void Powieksz();                //Metoda zdejmuje wszystkie elementy ze stosu za pomocą funkcji pop
};

template <typename Object>
Stos<Object>::Stos(int x)
{
    size = x;
    top = 0;
    tab = new Object[x];        //Alokowanie Pamięci

}

template <typename Object>
Stos<Object>::~Stos()
{
    delete [] tab;              
}

template <typename Object>
bool Stos<Object>::empty()  const
{
    return top == 0;
}

template <typename Object>
Object Stos<Object>::Top()
{

    if (empty()) 
    {
        cerr << "Stos jest teraz pusty" << endl;
        return 0;
    }
    else
    {
        return tab[top-1];
    }
    
  
}

template <typename Object>
void Stos<Object>::push(Object &element)
{
    if (top == size)
    {
        Powieksz(); //Gdy rozmiar tablicy jest za mały żeby umieścić 
    }               //Kolejny element to się powieksza
    else 
    {
        tab[top++] = element;
        l = l + 1;
        
    }
}

template <typename Object>
Object Stos<Object>::pop()
{
    if (empty())
    {
        cout << "Stos jest pusty" << endl;
    }
    
    l = l - 1;
    return tab[top--];
   
}

template <typename Object>
void Stos<Object>::Size()
{
    //cout << "Aktualny Rozmiar Stosu to :" << size << endl;
    for (int i=l ; i>0 ; i-- )
    {
        cout << tab[i-1] << endl;
    }
    if (size == 0)
    {
        cout << "Stos jest pusty" << endl;
    }
}

template <typename Object>
void Stos<Object>::All()
{
    if (empty())
    {
        cout << "Stos jest pusty" << endl;
    }
    else
    {
        while(!empty())
        pop();
        
    }
}

template <typename Object>
void Stos<Object>::Rozm()
{
    cout << "Rozmiar tablicy to" << size << endl;
}


template <typename Object>
void Stos<Object>::Powieksz()
{
    Object *nowa = new Object[size + 10];        //nowa tablica jest o 10 el. większa

    for(int i=0;i<size;++i)
    {
        nowa[i] = tab[i];   //kopiujemy starą tablicę do nowej
    }   

    delete []tab;      //sUsunięcie starej tablicy

    tab = nowa;        //Tab zaczyna pokazywać na nowo stworzoną tablice
    size += 10;        //O ile zwiększamy Rozmiar
    cout<<"Powiększono Tablice"<<endl;
}

#endif
