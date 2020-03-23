#pragma once
#include <ostream>
class Evidenta
{

private:

	char* nume;
	char* data;
	int pret;

public:

	Evidenta();
	Evidenta(char*, char*, int);
	Evidenta(const Evidenta&);
	~Evidenta();

	char* getNume();
	void setNume(char*);

	char* getData();
	void setData(char*);

	int getPret();
	void setPret(int);


	Evidenta& operator =(const Evidenta&);
	bool operator==(const Evidenta&);
	friend std::ostream& operator << (std::ostream&, const Evidenta&);
}; 
