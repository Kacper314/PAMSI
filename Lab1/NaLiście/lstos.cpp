/*
#include "lstos.hh"
#include <iostream>

using namespace std;

template <typename Object>
lstos::lstos()
{
    o = 0;
    LS = NULL;
}

lstos::~lstos()
{
    while(!empty()){
    pop();
    }
}

void lstos::size()
{
    cout << "Liczba elementów na stosie wynosi :" << o << endl;
  
}

int lstos::Top()
{
    if(empty())
    {
        cout << "Stos jest pusty" << endl;
    }
    return LS->dana;

   
}

bool lstos::empty()
{
    return o == 0;
}

void lstos::Push(int x)
{
    elstos * nowy = new elstos;
    nowy -> dana = x;
    nowy -> nastepny = LS;
    LS = nowy;
    o = o + 1;
}

void lstos::pop()
{
    if(LS == NULL){ 
        cout << "Stos jest pusty" << endl;
    }
     
    elstos * pom = LS;
    LS = LS->nastepny;
    delete pom;
    o = o - 1;
}

void lstos::Wypisz()
{
    
    elstos *tmp = LS;
    cout << "Elementy Stosu" << endl;
    while (tmp != NULL) {
        cout << tmp->dana << endl; 
        tmp = tmp->nastepny;
    }
    
}

*/