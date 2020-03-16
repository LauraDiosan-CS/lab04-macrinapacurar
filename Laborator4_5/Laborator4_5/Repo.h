#pragma once
#include "Evidenta.h"
class Repo
{
private:
	Evidenta elem[101];
	int size;
public:
	Repo();
	~Repo();
	Evidenta* get_all();
	void add(Evidenta);
	int get_size();
};