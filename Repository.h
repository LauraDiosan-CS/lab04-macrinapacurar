#pragma once
#include "Evidenta.h"
class Repository
{

private: 

	Evidenta ev[101];
	int len;

public:

	Repository();
	int get_len();
	Evidenta* get_all();
	void insert(Evidenta);
	void update(Evidenta ev);
	void delete_ev(int);
	~Repository();

};

