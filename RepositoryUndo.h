#pragma once
#include "Undo.h"

class RepositoryUndo
{

private:

	Undo ev[101];
	int len;

public:

	RepositoryUndo();
	void adaugare_undo(Undo);
	void reducere_lungime();
	Undo ultimul_element();
	Undo* elementele_vectorului();
	~RepositoryUndo();

};
