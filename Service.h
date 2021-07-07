#pragma once
#include "Repository.h"
#include "RepositoryUndo.h"
class Service
{

private:

	Repository repository;
	RepositoryUndo repositoryUndo;

public:

	Service()
	{
	}
	Evidenta* get_all();
	int get_len();
	void adaugare_service(char*, char*, int);
	void update(char*, char*, int);
	void delete_ev(char*, int);
	void procent_reducere(char*);
	Evidenta* produsele_dupa_data(char*, int&);
	void undo_ev();
	void add_undo(char*, Evidenta);
	void reducere_ev(char*);
	Undo* get_undo();
	~Service()
	{
	}

};
