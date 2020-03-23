#include "Evidenta.h"
#include <cstring>

Evidenta::Evidenta()
{
	this->nume = NULL;
	this->data = NULL;
	this->pret = 0;

}
Evidenta::Evidenta(char* nume, char* data, int pret) {

	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, 1 + strlen(nume), nume);
	this->data = new char[strlen(data) + 1];
	strcpy_s(this->data, 1 + strlen(data), data);
	this->pret = pret;
}

Evidenta::Evidenta(const Evidenta& ev) {

	this->nume = new char[strlen(ev.nume) + 1];
	strcpy_s(this->nume, 1 + strlen(ev.nume), ev.nume);
	this->data = new char[strlen(ev.data) + 1];
	strcpy_s(this->data, 1 + strlen(ev.data), ev.data);
	this->pret = ev.pret;
}

Evidenta::~Evidenta()
{

	if (this->data) 
	{

		delete[] this->data;
		this->data = NULL;
		delete[] this->nume;
		this->nume = NULL;
	}
}

char* Evidenta::getNume() 
{
	return this->nume;
}

void Evidenta::setNume(char* numeNou)
{
	this->nume = new char[strlen(numeNou) + 1];
	strcpy_s(this->nume, 1 + strlen(numeNou), numeNou);
}

int Evidenta::getPret() 
{
	return this->pret;
}
void Evidenta::setPret(int pretNou)
{
	this->pret = pretNou;
}

char* Evidenta::getData() 
{
	return this->data;
}
void Evidenta::setData(char* dataNoua) 
{
	this->data = new char[strlen(dataNoua) + 1];
	strcpy_s(this->data, 1 + strlen(dataNoua), dataNoua);
}


Evidenta& Evidenta:: operator =(const Evidenta& ev)
{
	this->setNume(ev.nume);
	this->setData(ev.data);
	this->setPret(ev.pret);
	return *this;
}

bool Evidenta:: operator==(const Evidenta& ev) 
{
	return strcmp(this->data, ev.data) == 0 and this->pret == ev.pret and strcmp(this->nume, ev.nume) == 0;
}

std::ostream& operator <<(std::ostream& os, const Evidenta& ev)
{
	os << std::endl << "Nume: " << ev.nume << " Data: " << ev.data << " Pret: " << ev.pret << std::endl;
	return os;
}