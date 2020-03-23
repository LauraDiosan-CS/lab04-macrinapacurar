#pragma once
#include "Repository.h"
class Service 
{
private:

	Repo repo;

public:
	void adaugare_service(char*, char*, int);
	void update(char*, char*, int);
	void delete_ev(char*);
	int get_len();
	Evidenta* get_all();
	void set_len(int);
};