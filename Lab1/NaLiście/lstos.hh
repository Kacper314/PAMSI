#ifndef LSTOS_HH
#define LSTOS_HH

#include <iostream>

using namespace std;

template <typename Object>
class lstos
{
private:
    struct elstos   //Struktura elementu na liście
    {
        double dana;
        elstos *nastepny;
    };

    double o ;          // Przechowuje liczbe elementów na stosie
    elstos *LS;         // Lista przechowująca stos
    
public:
    lstos();              // Konstruktor
    ~lstos();             // Destruktor
    void size();          // Liczba elementów na liście
    Object Top();         // Zwrócenie szczytu stosu , ostatniego elementu na liscie
    void Push(int x);     // Metoda Dodaje element do stosu
    void pop();           // Metdoa zdejmuje element ze stosu
    bool empty();         // Metoda sprawdza czy stos jest pusty
    void Wypisz();        // Metoda wypisująca całą zawartość stosu
    void All();           // Metoda usuwa wszystkie elementy ze stosu
};

template <typename Object>
lstos<Object>::lstos()
{
    o = 0;
    LS = NULL;
}

template <typename Object>
lstos<Object>::~lstos()
{
    while(!empty()){
    pop();
    }
}

template <typename Object>
void lstos<Object>::size()
{
    cout << "Liczba elementów na stosie wynosi :" << o << endl;
  
}

template <typename Object>
Object lstos<Object>::Top()
{
    if(empty())
    {
        cout << "Stos jest pusty" << endl;
    }
    else
    {
    return LS->dana;
    }
return 0;
   
}

template <typename Object>
bool lstos<Object>::empty()
{
    return o == 0;
}

template <typename Object>
void lstos<Object>::Push(int x)
{
    elstos * nowy = new elstos;
    nowy -> dana = x;
    nowy -> nastepny = LS;
    LS = nowy;
    o = o + 1;
}

template <typename Object>
void lstos<Object>::pop()
{
    if(LS == NULL){ 
        cout << "Stos jest pusty" << endl;
    }
     
    elstos * pom = LS;
    LS = LS->nastepny;
    delete pom;
    o = o - 1;
}

template <typename Object>
void lstos<Object>::Wypisz()
{
    
    elstos *tmp = LS;
    cout << "Elementy Stosu" << endl;
    while (tmp != NULL) {
        cout << tmp->dana << endl; 
        tmp = tmp->nastepny;
    }
    
}

template <typename Object>
void lstos<Object>::All()
{
    if(empty())
    {
        cout << "Lista jest pusta" << endl;
    }
    else
    {
        while(!empty())
        pop();     
    }
}

#endif
