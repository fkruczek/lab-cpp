#include "Kierownik.h"

Kierownik::Kierownik(const char* nd, int licz) :Pracownik()
{
	m_NazwaDzialu.Ustaw(nd);
	m_nLiczbaPracownikow = licz;
}

Kierownik::Kierownik(const Kierownik & wzor)
{
	m_Imie = wzor.m_Imie;
	m_Nazwisko = wzor.m_Nazwisko;
	m_DataUrodzenia = wzor.m_DataUrodzenia;
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
		m_Imie = wzor.m_Imie;
		m_Nazwisko = wzor.m_Nazwisko;
		m_DataUrodzenia = wzor.m_DataUrodzenia;
		m_NazwaDzialu = wzor.m_NazwaDzialu;
		m_nLiczbaPracownikow = wzor.m_nLiczbaPracownikow;
	}
	return *this;
}

bool Kierownik::operator==(const Kierownik & wzor) const
{
	if (this->Porownaj(wzor) == 0 && m_NazwaDzialu.SprawdzNapis(wzor.m_NazwaDzialu.Zwroc()) && m_nLiczbaPracownikow == wzor.m_nLiczbaPracownikow)
		return true;
	else
		return false;
}

void Kierownik::WypiszDane()
{
	std::cout << *this;
}

Kierownik * Kierownik::KopiaObiektu()
{
	Kierownik *kopia;
	kopia = new Kierownik();
	kopia = this;
	return kopia;
}

std::ostream & operator<<(std::ostream & wy, const Kierownik & p)
{
	p.Wypisz();
	return wy << p.m_NazwaDzialu << "Liczba pracownikow: " << p.m_nLiczbaPracownikow;
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