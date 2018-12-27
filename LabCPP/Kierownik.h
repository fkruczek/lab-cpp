#pragma once
#include "Pracownik.h"
class Kierownik :
	public Pracownik
{
private:
	Napis m_NazwaDzialu;
	int m_nLiczbaPracownikow;
public:
	Kierownik(const char* nd = "", int licz = 0);
	Kierownik(const Kierownik & wzor);
	~Kierownik();
	Kierownik & operator=(const Kierownik & wzor);
	bool operator==(const Kierownik & wzor) const;
	virtual void WypiszDane();
	virtual Kierownik* KopiaObiektu();
	friend std::ostream & operator <<(std::ostream &wy, const Kierownik &p);
	friend std::istream & operator >>(std::istream &we, Kierownik &p);
};

