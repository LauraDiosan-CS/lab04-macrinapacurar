#include "Teste.h"
#include "Repository.h"
#include <cassert>
void teste() 
{
	char* produs1 = new char[20];
	char* data1 = new char[20];

	char* produs2 = new char[20];
	char* data2 = new char[20];
    
	char* produs3 = new char[20];
	char* data3 = new char[20];
	
	strcpy_s(data1, sizeof "17.03.2000", "17.03.2000");
	strcpy_s(produs1, sizeof "Ciocolata", "Ciocolata");
	Evidenta s1(produs1, data1, 23);

	strcpy_s(produs2, sizeof "Lapte", "Lapte");
	Evidenta s2(produs2, data2, 14);

	strcpy_s(produs3, sizeof "Chipsuri", "Chipsuri");
	Evidenta s3(produs3, data3, 44);

	Repo repo;
	Evidenta ev[3];
	ev[0] = s1;
	ev[1] = s2;
	repo.insert(s1);
	repo.insert(s2);
	assert(repo.get_len() == 2);
	for (int i = 0; i < repo.get_len(); i++) 
	{
		assert(repo.get_all()[i] == ev[i]);
	}
	repo.update(s3);
	assert(repo.get_len() == 2);
	for (int i = 0; i < repo.get_len(); i++) {
		assert(repo.get_all()[i] == ev[i]);
	}
	Evidenta ev1[1];
	ev1[0] = s2;
	produs1 = new char[1 + strlen("Ciocolata")];
	strcpy_s(produs1, 1 + strlen("Ciocolata"), "Ciocolata");
	repo.delete_ev(produs1);
	for (int i = 0; i < repo.get_len(); i++) {
		assert(repo.get_all()[i] == ev1[i]);
	}


}