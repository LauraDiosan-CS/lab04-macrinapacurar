#include "Repository.h"
#include <cstring>

Repo::Repo()
{
	this->len = 0;
}

Repo::~Repo() 
{
	this->len = 0;
}

void Repo::insert(Evidenta newEv) 
{
	this->ev[this->len++] = newEv;
}

int Repo::get_len()
{
	return this->len;
}

Evidenta* Repo::get_all()
{
	return this->ev;
}

void Repo::set_len(int new_len)
{
	this->len = new_len;
}

void Repo::update(Evidenta ev)
{
	int n = this->get_len();
	Evidenta* aux = this->get_all();

	for (int i = 0; i < n; i++)
	{
		if (strcmp(ev.getNume(), aux[i].getNume()) == 0) 
		{
			aux[i] = ev;
		}
	}
}
void Repo::delete_ev (char* nume) {

	for (int i = 0; i < this->len; i++) {
		if (strcmp(nume, this->ev[i].getNume()) == 0) {
			while (i < this->len) {
				if (i + 1 < this->len)
					this->ev[i] = this->ev[i + 1];
				i++;
			}
			this->len--;
		}
	}
}
