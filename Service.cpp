#include "Service.h"
#include "Validation.h"
#include "RepositoryUndo.h"

Evidenta* Service::get_all()
{
	return this->repository.get_all();
}

int Service::get_len()
{
	return this->repository.get_len();
}

void Service::adaugare_service(char* nume, char* data, int pret)
{
	Evidenta ev(nume, data, pret);
	Undo undo(4, ev);
	repositoryUndo.adaugare_undo(undo);
	repository.insert(ev);
}

void Service::update(char* nume, char* data, int pret)
{
	Evidenta produs_curent(nume, data, pret);
	Evidenta* ev = this->repository.get_all();
	Undo undo;
	for (int i = 0; i < this->repository.get_len(); i++)
		if (strcmp(nume, ev[i].getNume()) == 0)
		{
			undo = Undo(3, ev[i]);
			i = this->repository.get_len();
		}
	this->repositoryUndo.adaugare_undo(undo);
	this->repository.update(produs_curent);

}

void Service::delete_ev(char* nume, int contor)
{
	Evidenta* ev = this->repository.get_all();
	for (int i = 0; i < this->repository.get_len(); i++)
		if (strcmp(nume, ev[i].getNume()) == 0)
		{
			if (contor == 1)
			{
				Undo undo(1, ev[i]);
				repositoryUndo.adaugare_undo(undo);
			}
			this->repository.delete_ev(i);
		}
}

void Service::procent_reducere(char* data)
{

	Evidenta* ev = this->get_all();
	int n = this->get_len();
	for (int i = 0; i < n; i++)
	{
		if (verificare(data, ev[i].getData()))
		{
			double pret = ev[i].getPret();
			ev[i].setPret((pret * 100) / 90);
		}
	}
}

Evidenta* Service::produsele_dupa_data(char* data, int& n)
{

	Evidenta* vector = new Evidenta[101];
	Evidenta* ev = this->repository.get_all();
	for (int i = 0; i < this->repository.get_len(); i++)
	{

		if (strcmp(data, ev[i].getData()) == 0)
		{
			vector[n++] = ev[i];
		}
	}
	return vector;
}
void Service::undo_ev() {


	Undo undo_ultim_element = repositoryUndo.ultimul_element();
	if (undo_ultim_element.get_index() == 1)
	{
		this->repository.insert(undo_ultim_element.get_ev());
		repositoryUndo.reducere_lungime();
	}
	if (undo_ultim_element.get_index() == 3)
	{
		this->repository.update(undo_ultim_element.get_ev());
		repositoryUndo.reducere_lungime();
	}
	if (undo_ultim_element.get_index() == 4)
	{
		this->delete_ev(undo_ultim_element.get_ev().getNume(), 0);
		repositoryUndo.reducere_lungime();
	}

	if (undo_ultim_element.get_index() == 7)
	{
		this->procent_reducere(undo_ultim_element.get_ev().getData());
		repositoryUndo.reducere_lungime();
	}
}
void Service::add_undo(char* data, Evidenta ev)
{

	Evidenta ev1(ev.getNume(), data, ev.getPret());
	Undo undo(7, ev1);
	repositoryUndo.adaugare_undo(undo);
}

void Service::reducere_ev(char* data)
{
	Evidenta* ev = this->get_all();
	int g = 1;
	for (int i = 0; i < this->get_len(); i++) {
		if (verificare(data, ev[i].getData()))
		{

			if (g == 1)
			{
				this->add_undo(data, ev[i]);
				g = 0;
			}
			double pret = ev[i].getPret();
			ev[i].setPret(pret - ((1.0 / 10) * pret));
		}
	}
}

Undo* Service::get_undo()
{
	return this->repositoryUndo.elementele_vectorului();
}