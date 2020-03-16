#pragma once
#include <ostream>
class Evidenta
{
private:
	char* nume;
	int pret;
	int data;
public:
	Evidenta();
	Evidenta(char*, int, int);
	Evidenta(const Evidenta&);
	~Evidenta();

	char* get_nume();
	int get_pret();
	int get_data();

	void set_nume(char*);
	void set_pret(int);
	void set_data(int);


	Evidenta& operator =(const Evidenta&);
	bool operator==(const Evidenta&);
	friend std::ostream& operator << (std::ostream&, const Evidenta&);
};