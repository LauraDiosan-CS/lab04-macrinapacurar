#include "Validation.h"
#include <iostream>
using namespace std;

void print_menu()
{
    cout << "0.Exit" << endl;
    cout << "1.Adaugare" << endl;
    cout << "2.Afisare" << endl;
    cout << "3.Update" << endl;
    cout << "4.Stergere" << endl;
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

    while (i < strlen(string)) {
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