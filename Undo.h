#pragma once
#include "Evidenta.h"

class Undo
{

private:

	Evidenta ev;
	int index;

public:

	Undo();
	Undo(int, Evidenta);
	Undo(const Undo&);
	int get_index();
	void set_index(int);
	Evidenta get_ev();
	Undo& operator =(const Undo&);
	bool operator==(const Undo&);
	~Undo();

};
