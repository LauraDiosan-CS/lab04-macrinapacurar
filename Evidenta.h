#pragma once
#include <ostream>
class Evidenta
{

private:

	char* nume;
	char* data;
	double pret;

public:

	Evidenta();
	Evidenta(char*, char*, double);
	Evidenta(const Evidenta&);

	char* getNume();
	void setNume(char*);

	char* getData();
	void setData(char*);

	double getPret();
	void setPret(double);

	Evidenta& operator =(const Evidenta&);
	bool operator==(const Evidenta&);
	friend std::ostream& operator << (std::ostream&, const Evidenta&);

	~Evidenta();

};
