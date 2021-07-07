#include "Teste.h"
#include "Repository.h"
#include "Service.h"
#include <cassert>


void teste_repository()
{
	char* produs1 = new char[20];
	char* data1 = new char[20];

	char* produs2 = new char[20];
	char* data2 = new char[20];

	char* produs3 = new char[20];
	char* data3 = new char[20];

	strcpy_s(data1, sizeof "17.03.2000", "17.03.2000");
	strcpy_s(produs1, sizeof "Ciocolata", "Ciocolata");
	Evidenta p1(produs1, data1, 23);

	strcpy_s(data2, sizeof "15.02.2000", "15.02.2000");
	strcpy_s(produs2, sizeof "Lapte", "Lapte");
	Evidenta p2(produs2, data2, 14);

	strcpy_s(data3, sizeof "25.03.2000", "25.03.2000");
	strcpy_s(produs3, sizeof "Chipsuri", "Chipsuri");
	Evidenta p3(produs3, data3, 44);

	Repository repository;
	char* nume = new char[20];
	Evidenta ev[2];
	ev[0] = p1;
	ev[1] = p2;


	repository.insert(p1);
	repository.insert(p2);
	assert(repository.get_len() == 2);
	for (int i = 0; i < repository.get_len(); i++)
	{
		assert(repository.get_all()[i] == ev[i]);
	}


	repository.update(p3);
	assert(repository.get_len() == 2);
	for (int i = 0; i < repository.get_len(); i++) {
		assert(repository.get_all()[i] == ev[i]);
	}
	Service service;


	Evidenta ev1[1];
	ev1[0] = p2;
	nume = new char[1 + strlen("Ciocolata")];
	strcpy_s(nume, 1 + strlen("Ciocolata"), "Ciocolata");
	repository.delete_ev(0);
	for (int i = 0; i < repository.get_len(); i++) {
		assert(repository.get_all()[i] == ev1[i]);
	}


}
void teste_service()
{
	char* produs1 = new char[20];
	char* data1 = new char[20];

	char* produs2 = new char[20];
	char* data2 = new char[20];

	char* produs3 = new char[20];
	char* data3 = new char[20];
	Service service;

	strcpy_s(produs1, sizeof "Ciocolata", "Ciocolata");
	strcpy_s(data1, sizeof "17.03.2000", "17.03.2000");
	service.adaugare_service(produs1, data1, 24);

	strcpy_s(produs2, sizeof "Lapte", "Lapte");
	strcpy_s(data2, sizeof "15.02.2000", "15.02.2000");
	service.adaugare_service(produs2, data2, 11);


	Evidenta p1(produs1, data1, 24);
	Evidenta p2(produs2, data2, 4);

	char* nume = new char[20];
	strcpy_s(produs3, sizeof "Chipsuri", "Chipsuri");
	strcpy_s(data2, sizeof "18.02.2000", "18.02.2000");

	Evidenta ev[2];
	ev[0] = service.get_all()[0];
	ev[1] = service.get_all()[1];
	assert(service.get_len() == 2);
	for (int i = 0; i < service.get_len(); i++)
	{
		assert(service.get_all()[i] == ev[i]);
	}

	Undo undo[2];
	undo[0] = Undo(4, p1);
	undo[1] = Undo(4, p2);

	for (int i = 0; i < service.get_len(); i++) 
	{

		assert(undo[i] == service.get_undo()[i]);
	}
    service.undo_ev();

	for (int i = 0; i < service.get_len(); i++) 
	{

	    assert(undo[i] == service.get_undo()[i]);
	}


	service.update(produs3, data3, 8);
	ev[0] = service.get_all()[0];
	ev[1] = service.get_all()[1];
	for (int i = 0; i < service.get_len(); i++) {
		assert(service.get_all()[i] == ev[i]);
	}

	Evidenta ev1[1];
	ev1[0] = service.get_all()[1];
	nume = new char[1 + strlen("Ciocolata")];
	strcpy_s(nume, 1 + strlen("Ciocolata"), "Ciocolata");
	service.delete_ev(nume, 1);
	for (int i = 0; i < service.get_len(); i++) {
		assert(service.get_all()[i] == ev1[i]);
	}

}











void teste()
{
	teste_repository();
}