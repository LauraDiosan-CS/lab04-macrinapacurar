#include "Service.h"

void Service::adaugare_service(char* nume, char* data, int pret) 
{
	Evidenta ev(nume, data, pret);
	repo.insert(ev);
}
void Service::update(char* nume, char* data, int pret)
{
	Evidenta ev(nume, data, pret);
	this->repo.update(ev);
}
Evidenta* Service::get_all() 
{
	return this->repo.get_all();
}
int Service::get_len() 
{
	return this->repo.get_len();
}
void Service::set_len(int new_len)
{
	this->repo.set_len(new_len);
}

void Service::delete_ev(char* nume) {
	this->repo.delete_ev(nume);
}