#include "Repository.h"

Repository::Repository()
{
	this->len = 0;
}


int Repository::get_len()
{
	return this->len;
}

Evidenta* Repository::get_all()
{
	return this->ev;
}

void Repository::insert(Evidenta newEv)
{
	this->ev[this->len++] = newEv;
}

void Repository::update(Evidenta ev)
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
void Repository::delete_ev(int i)
{
	while (i < this->len)
	{
		if (i + 1 < this->len)
			this->ev[i] = this->ev[i + 1];
		i++;
	}
	this->len--;

}

Repository::~Repository()
{
	this->len = 0;
}
