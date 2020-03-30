#include "Evidenta.h"
#include <cstring>

Evidenta::Evidenta()
{
	this->nume = NULL;
	this->data = NULL;
	this->pret = 0;

}
Evidenta::Evidenta(char* nume, char* data, double pret)
{

	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, 1 + strlen(nume), nume);
	this->data = new char[strlen(data) + 1];
	strcpy_s(this->data, 1 + strlen(data), data);
	this->pret = pret;
}

Evidenta::Evidenta(const Evidenta& ev)
{

	this->nume = new char[strlen(ev.nume) + 1];
	strcpy_s(this->nume, 1 + strlen(ev.nume), ev.nume);
	this->data = new char[strlen(ev.data) + 1];
	strcpy_s(this->data, 1 + strlen(ev.data), ev.data);
	this->pret = ev.pret;
}


char* Evidenta::getNume()
{
	return this->nume;
}

void Evidenta::setNume(char* numeNou)
{
	if (this->nume)
	{
		delete[] this->nume;
		this->nume = NULL;
	}
	this->nume = new char[strlen(numeNou) + 1];
	strcpy_s(this->nume, 1 + strlen(numeNou), numeNou);
}

char* Evidenta::getData()
{
	return this->data;
}
void Evidenta::setData(char* dataNoua)
{
	if (this->data)
	{
		delete[] this->data;
		this->data = NULL;
	}
	this->data = new char[strlen(dataNoua) + 1];
	strcpy_s(this->data, 1 + strlen(dataNoua), dataNoua);
}

double Evidenta::getPret()
{
	return this->pret;
}
void Evidenta::setPret(double pretNou)
{
	this->pret = pretNou;
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

Evidenta::~Evidenta()
{
	if (this->nume)
	{
		delete[] this->nume;
		this->nume = NULL;
	}

	if (this->data)
	{
		delete[] this->data;
		this->data = NULL;
	}

}