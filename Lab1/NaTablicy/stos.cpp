/*#include <iostream>
#include <cstdlib>
#include "stos.hh"

using namespace std;

template <typename Object>
Stos<Object>::Stos(int x)
{
    size = x;
    top = 0;
    tab = new Object[x];

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
Object& Stos<Object>::Top()
{
    if (empty()) 
    {
        cerr << "Stos jest teraz pusty" << endl;
    }
        return tab[top-1];
}

template <typename Object>
void Stos<Object>::push(int element)
{
    if (top >= size)
    {
        cerr << "Stos jest przepełniony" << endl;
    }
    else 
    {
        tab[top++] = element;
    }
}

template <typename Object>
Object Stos<Object>::pop()
{
    if (empty())
    {
        cout << "Stos jest pusty" << endl;
    }
    
    return tab[top--];
    
}

template <typename Object>
void Stos<Object>::Size()
{
    //cout << "Aktualny Rozmiar Stosu to :" << size << endl;
    for (int i=0 ; i<size ; i++ )
    {
        cout << tab[i] << endl;
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

*/