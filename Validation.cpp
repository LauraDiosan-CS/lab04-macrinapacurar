#include "Validation.h"
#include <iostream>
using namespace std;

void print_menu()
{

    cout << "1.Adaugare" << endl;
    cout << "2.Afisare" << endl;
    cout << "3.Update" << endl;
    cout << "4.Stergere" << endl;
    cout << "5.Undo" << endl;
    cout << "6.Afișarea tuturor produselor care au reajuns astăzi pe stoc" << endl;
    cout << "7.Reducerea cu 10% a prețurilor produselor " << endl;
    cout << "0.Exit" << endl;
}


void conversie(char* data1, int& ziua, int& luna, int& an)
{
    int i = 0;
    while (data1[i] != '.')
    {

        ziua = ziua * 10 + (data1[i] - '0');
        i++;
    }
    i++;
    while (data1[i] != '.')
    {

        luna = luna * 10 + (data1[i] - '0');
        i++;
    }
    i++;
    while (data1[i] != '.' and i < strlen(data1))
    {

        an = an * 10 + (data1[i] - '0');
        i++;
    }

}
bool verificare(char* data1, char* data2)
{
    int ziua1 = 0, luna1 = 0, an1 = 0;
    int ziua2 = 0, luna2 = 0, an2 = 0;
    conversie(data1, ziua1, luna1, an1);
    conversie(data2, ziua2, luna2, an2);
    if (an1 > an2)
        return true;
    else {
        if (an1 == an2)
        {
            if (luna1 > luna2)
            {
                return true;
            }
            else {
                if (luna1 == luna2)
                {
                    if (ziua1 > ziua2)
                    {
                        return true;
                    }
                    else
                        return false;
                }
                else
                    return false;
            }
        }
        else
            return false;
    }
}







bool date(char* string)
{

    int list[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int nrok = 0, nrzile, nrluni, i;
    int nran = 0;

    if ('9' >= string[0] and string[0] >= '0' and '9' >= string[1] and string[1] >= '0' and string[2] == '.' and string[5] == '.') {
        nrzile = (string[0] - '0') * 10 + (string[1] - '0');
        nrluni = (string[3] - '0') * 10 + (string[4] - '0');
    }
    else
        return false;

    i = 6;

    while (i < strlen(string)) 
    {
        if (string[i] == '.')
            return false;
        nran = nran * 10 + (string[i] - '0');
        i = i + 1;
    }

    if (0 < nrluni and nrluni <= 12 and list[nrluni] >= nrzile and nrzile > 0 and (nran % 4 == 0 or nran % 400 == 0))
        nrok = nrok + 1;
    else
        if (0 < nrluni and nrluni <= 12 and list[nrluni] > nrzile and nrzile > 0)
            nrok = nrok + 1;
    if (nrok == 1)
        return true;
    else
        return false;
}