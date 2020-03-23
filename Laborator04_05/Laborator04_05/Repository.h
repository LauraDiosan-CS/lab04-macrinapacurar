#pragma once
#include "Evidenta.h"
class Repo 
{

private:
	Evidenta ev[101];
	int len;

public:

	Repo();
	void insert(Evidenta);
	void update(Evidenta ev);
	void delete_ev(char*);
	int get_len();
	Evidenta* get_all();
	void set_len(int);
	~Repo();
};
