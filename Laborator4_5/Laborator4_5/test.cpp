#include "Repo.h"
#include "test.h"
#include <cassert>
void test()
{
	char* nume1 = new char[12];
	char* nume2 = new char[12];
	char* nume3 = new char[12];

	strcpy_s(nume1, sizeof "Dana", "Dana");
	Evidenta s1(nume1, 1, 45);

	strcpy_s(nume2, sizeof "Alex", "Alex");
	Evidenta s2(nume2, 2, 8);

	strcpy_s(nume3, sizeof "Mona", "Mona");
	Evidenta s3(nume3, 4, 19);

	Repo repo;
	Evidenta ev[3];
	ev[0] = s1;
	ev[1] = s2;
	ev[2] = s3;

	repo.add(s1);
	repo.add(s2);
	repo.add(s3);

	for (int i = 0; i < repo.get_size(); i++)
	{
		assert(repo.get_all()[i] == ev[i]);
	}

}