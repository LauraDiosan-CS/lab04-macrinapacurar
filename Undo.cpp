#include "Undo.h"


Undo::Undo()
{
	this->index = 0;
}


Undo::Undo(int index, Evidenta ev)
{
	this->index = index;
	this->ev = ev;
}


Undo::Undo(const Undo& obj)
{
	this->index = obj.index;
	this->ev = obj.ev;
}


int Undo::get_index()
{
	return this->index;
}

void Undo::set_index(int new_index)
{
	this->index = new_index;
}

Evidenta Undo::get_ev()
{
	return this->ev;

}

Undo& Undo:: operator =(const Undo& undo)
{
	this->index = undo.index;
	this->ev = undo.ev;
	return *this;
}

bool Undo:: operator==(const Undo& undo)
{
	return this->index == undo.index and this->ev == undo.ev;
}

Undo::~Undo()
{
	this->index = 0;
}
