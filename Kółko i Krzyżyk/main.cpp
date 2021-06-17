#include "gra.hh"
#include <iostream>

using namespace std;

int main()
{
    cout << " Aktualny Rozmiar Planszy:    " << ROZMIAR << endl;
    char znak = 'y';
  
    do
    {
        char wybor;
        cout << "Czy chcesz zacząć (y/n)" << endl;
        cin >> wybor;

        if(wybor == 'n')
        {
            Graj(Bot);
        }
        else if (wybor == 'y')
        {
            Graj(Man);
        }
        else
        {
            cout << "Zły Wybór"<< endl;
        }

        cout << "Czy chcesz zakończyć (y/n)" << endl;
        cin >> znak;

    }while (znak == 'n');
    return 0;

}