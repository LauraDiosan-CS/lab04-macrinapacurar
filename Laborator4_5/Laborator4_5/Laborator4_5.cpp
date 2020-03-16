#include <iostream>
#include "Repo.h"
#include "test.h"
using namespace std;

void print_menu()
{
    cout << "1.Adaugare" << endl;
    cout << "2.Afisare" << endl;
    cout << "0.Exit" << endl;
}

int main()
{
    test();
    int  data, pret;
    char nume[20];
    Repo repo;
    int optiune = 1;
    while (optiune)
    {
        cout << "Alege o optiune " << endl;
        print_menu();
        cout << "Optiunea: ";
        cin >> optiune;
        if (optiune == 1) {
            cout << "Numele: ";
            cin >> nume;
            cout << "Data: ";
            cin >> data;
            cout << "Pretul: ";
            cin >> pret;
            cout << endl;
            Evidenta ev(nume, data, pret);
            repo.add(ev);
        }
        if (optiune == 2) 
        {
            for (int i = 0; i < repo.get_size(); i++)
                cout << repo.get_all()[i] << endl;
        }
    }
    return 0;
}