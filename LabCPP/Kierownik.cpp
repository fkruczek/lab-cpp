#include "Kierownik.h"

Kierownik::Kierownik(const char *im , const char *naz, int dzien, int miesiac, int rok, const char* nd, int licz) 
	: Pracownik(im, naz, dzien, miesiac, rok)
{
	m_NazwaDzialu.Ustaw(nd);
	m_nLiczbaPracownikow = licz;
}

Kierownik::Kierownik(const Kierownik & wzor) : Pracownik(wzor)
{
	m_NazwaDzialu = wzor.m_NazwaDzialu;
	m_nLiczbaPracownikow = wzor.m_nLiczbaPracownikow;
}

Kierownik::~Kierownik()
{
}

Kierownik & Kierownik::operator=(const Kierownik & wzor)
{
	if (&wzor != this)
	{
		(Pracownik&)*this = wzor;
		this->Pracownik::operator=(wzor);
		m_NazwaDzialu = wzor.m_NazwaDzialu;
		m_nLiczbaPracownikow = wzor.m_nLiczbaPracownikow;
	}
	return *this;
}

bool Kierownik::operator==(const Kierownik & wzor) const
{
	if (this->Porownaj(wzor) == 0 &&
		m_NazwaDzialu.SprawdzNapis(wzor.m_NazwaDzialu.Zwroc()) &&
		m_nLiczbaPracownikow == wzor.m_nLiczbaPracownikow)
		return true;
	else
		return false;
}

void Kierownik::WypiszDane()
{
	std::cout << *this;
}

Kierownik * Kierownik::KopiaObiektu()  const
{
	return new Kierownik(*this);
}

std::ostream & operator<<(std::ostream & wy, const Kierownik & p)
{
	p.Wypisz();
	wy << " Dzial: " << p.m_NazwaDzialu << " Liczba pracownikow: " << p.m_nLiczbaPracownikow << std::endl;
	return wy;
}

std::istream & operator>>(std::istream & we, Kierownik & p)
{
	p.Wpisz();
	std::cout << "Podaj nazwe dzialu: ";
	we >> p.m_NazwaDzialu;
	std::cout << "Podaj liczbe pracownikow: ";
	we >> p.m_nLiczbaPracownikow;
	return we;
}