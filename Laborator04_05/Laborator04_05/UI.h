#pragma once
#include "Service.h"
class UI
{

private:

	Service service;
	void adaugare();
	void afisare();
	void update();
	void stergere();

public:

	void run();
};