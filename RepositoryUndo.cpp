#include "RepositoryUndo.h"

RepositoryUndo::RepositoryUndo()
{
	this->len = 0;
}

void RepositoryUndo::adaugare_undo(Undo undo)
{
	this->ev[this->len++] = undo;
}

void RepositoryUndo::reducere_lungime()
{
	if (this->len > 0)
		this->len--;
}

Undo RepositoryUndo::ultimul_element()
{
	if (this->len > 0)
		return this->ev[this->len - 1];
	else
		return this->ev[0];
}

Undo* RepositoryUndo::elementele_vectorului()
{
	return this->ev;
}

RepositoryUndo::~RepositoryUndo()
{
	this->len = 0;
}