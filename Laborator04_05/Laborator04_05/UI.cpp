#include "UI.h"
#include "Teste.h"
#include "Validation.h"
#include <iostream>
#include <string>
using namespace std;


void UI::adaugare() 
{
    char* nume = new char[0];
    char* data = new char[0];
    int pret;

    cout << "Dati un nume produs: ";
    nume = new char[20];
    cin >> nume;
    data = new char[20];
    int ok = 1;
    while (ok == 1) {

        cout << "Dati o data: ";
        cin >> data;
        if (date(data))
            ok = 0;
        else
            cout << "Data invalida! ";
    }
    cout << "Dati un pret: ";
    cin >> pret;
    cout << endl;
    this->service.adaugare_service(nume,data,pret);
}
void UI::afisare()
{
    int n = this->service.get_len();
    Evidenta* ev = this->service.get_all();
    for (int i = 0; i < n; i++)
        cout << ev[i] << endl;
}

void UI::update() 
{
    char* nume = new char[0];
    char* data = new char[0];
    int pret;

    cout << "Dati un nume: ";
    nume = new char[20];
    data = new char[20];
    cin >> nume;
    int ok = 1;
    while (ok == 1) 
    {
        cout << "Dati o data noua: ";
        cin >> data;
        if (date(data))
            ok = 0;
        else
            cout << "Data invalida! ";
    }
    cout << "Dati un pret nou: ";
    cin >> pret;
    cout << endl;
    this->service.update(nume, data, pret);
}
void UI::stergere()
{
    cout << "Dti un nume: ";
    char* nume =new char[20];
    cin >> nume;
    this->service.delete_ev(nume);
    
}

void UI::run() 
{
    bool go = true;
    string optiune;
    do {
        cout << endl << "Alegeti o optiune " << endl;
        print_menu();
        cout << "Optiunea ta este: ";
        cin >> optiune;
        if (optiune.size() == 1)
        {
         if (optiune[0] == '1')
         {
         this->adaugare();
         }
         else
         if (optiune[0] == '2')
         {
         this->afisare();
         }
         else
         if (optiune[0] == '3') 
         {
         this->update();
         }
         else
         if (optiune[0] == '4') 
         {
          this->stergere();
         }
         else
         if (optiune[0] == '0') 
         {
          go = false;
         }
         else
         cout << endl << "Optiune invalida!" << endl;
        }
     else
        cout << endl << "Optiune invalida!" << endl;
    } while (go);
}