#include <cstring>
#include "Evidenta.h"

Evidenta::Evidenta()
{
	this->nume = NULL;
	this->data = 0;
	this->pret = 0;
	
}
Evidenta::Evidenta(char* nume,int data, int pret)
{
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, 1 + strlen(nume), nume);
	this->data = data;
	this->pret = pret;
}
Evidenta::Evidenta(const Evidenta& ev)
{
	this->nume = new char[strlen(ev.nume) + 1];
	strcpy_s(this->nume, 1 + strlen(ev.nume), ev.nume);
	this->data = ev.data;
	this->pret = ev.pret;
}
Evidenta::~Evidenta() {
}
int Evidenta::get_data()
{
	return this->data;
}
int Evidenta::get_pret()
{
	return this->pret;
}
char* Evidenta::get_nume()
{
	return this->nume;
}

void Evidenta::set_data(int dataNoua)
{
	this->data = dataNoua;
}
void Evidenta::set_nume(char* numeNou)
{
	this->nume = new char[strlen(numeNou) + 1];
	strcpy_s(this->nume, 1 + strlen(numeNou), numeNou);
}
void Evidenta::set_pret(int pretNou)
{
	this->pret = pretNou;
}
Evidenta& Evidenta:: operator =(const Evidenta& ev)
{
	this->set_data(ev.data);
	this->set_pret(ev.pret);
	this->set_nume(ev.nume);
	return *this;
}
bool Evidenta:: operator==(const Evidenta& s) {
	return strcmp(this->nume, s.nume) == 0 and this->pret == s.pret and this->data == s.data;
}
std::ostream& operator <<(std::ostream& os, const Evidenta& ev)
{
	os << std::endl << "Numele: " << ev.nume << " Data: " << ev.data << " Pretul: " << ev.pret << std::endl;
	return os;
}