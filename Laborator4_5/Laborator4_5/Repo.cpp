#include "Repo.h"

Repo::Repo()
{
	this->size = 0;
}
Repo::~Repo()
{
	this->size = 0;
}
void Repo::add(Evidenta ev)
{
	this->elem[this->size++] = ev;
}
Evidenta* Repo::get_all()
{
	return this->elem;
}
int Repo::get_size()
{
	return this->size;
}