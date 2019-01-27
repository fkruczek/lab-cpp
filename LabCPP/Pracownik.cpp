#define _CRT_SECURE_NO_WARNINGS z
#include "Pracownik.h"
#include <iostream>
#include <cstring>
int Pracownik::m_ID = 1000;
Pracownik::Pracownik(const char * im, const char * naz, int dzien, int miesiac, int rok) :
	m_Imie(im),
	m_Nazwisko(naz),
	m_DataUrodzenia(dzien, miesiac, rok),
	m_nIDZatrudnienia(++m_ID)
{
	//m_Imie.Ustaw(im);
	//m_pNastepny = nullptr;
	//m_Nazwisko.Ustaw(naz);
	//m_DataUrodzenia.Ustaw(dzien, miesiac, rok);
}

Pracownik::Pracownik(const Pracownik & wzor) :
	m_Imie(wzor.m_Imie),
	m_Nazwisko(wzor.m_Nazwisko),
	m_DataUrodzenia(wzor.m_DataUrodzenia),
	m_nIDZatrudnienia(wzor.m_nIDZatrudnienia)
{
	//m_pNastepny = wzor.m_pNastepny;
	//m_Imie = wzor.m_Imie;
	//m_Nazwisko = wzor.m_Nazwisko;
	//m_DataUrodzenia = wzor.m_DataUrodzenia;
}

Pracownik::~Pracownik()
{
}

Pracownik & Pracownik::operator=(const Pracownik & wzor)
{
	if (this != &wzor) {
		m_Imie = wzor.m_Imie;
		m_Nazwisko = wzor.m_Nazwisko;
		m_DataUrodzenia = wzor.m_DataUrodzenia;
		//m_nIDZatrudnienia = wzor.m_nIDZatrudnienia;
		m_pNastepny = wzor.m_pNastepny;
	}
	return *this;
}

bool Pracownik::operator==(const Pracownik & wzor) const
{
	if (this->Porownaj(wzor) == 0)
		return true;
	else
		return false;
}

const char * Pracownik::Imie() const
{
	return m_Imie.Zwroc();
}

const char * Pracownik::Nazwisko() const
{
	return m_Nazwisko.Zwroc();
}

void Pracownik::Imie(const char * nowe_imie)
{
	m_Imie.Ustaw(nowe_imie);
}

void Pracownik::Nazwisko(const char * nowe_nazwisko)
{
	m_Nazwisko.Ustaw(nowe_nazwisko);
}

void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
	m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}

void Pracownik::Wypisz() const
{
	std::cout << m_nIDZatrudnienia << " " << m_Imie.Zwroc() << " " << m_Nazwisko.Zwroc() << " ";
	m_DataUrodzenia.Wypisz();
}

void Pracownik::Wpisz()
{
	char nowe_imie[20];
	char nowe_nazwisko[25];
	std::cout << "Podaj imie: " << std::endl;
	(std::cin >> nowe_imie).get();
	Imie(nowe_imie);
	std::cout << "Podaj nazwisko: " << std::endl;
	(std::cin >> nowe_nazwisko).get();
	Nazwisko(nowe_nazwisko);
	std::cout << "Podaj date" << std::endl;
	m_DataUrodzenia.Wpisz();
}

int Pracownik::SprawdzImie(const char * por_imie) const
{
	return m_Imie.SprawdzNapis(por_imie);
}

int Pracownik::SprawdzNazwisko(const char * por_nazwisko) const
{
	return m_Nazwisko.SprawdzNapis(por_nazwisko);
}

int Pracownik::Porownaj(const Pracownik & wzorzec) const
{
	int sprNazw = this->SprawdzNazwisko(wzorzec.m_Nazwisko.Zwroc());
	int sprImie = this->SprawdzImie(wzorzec.m_Imie.Zwroc());
	int sprDate = this->m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia);

	if (sprNazw == 0 && sprImie == 0 && sprDate == 0) return 0;
	else if (sprNazw != 0) return sprNazw;
	else if (sprImie != 0) return sprImie;
	else return sprDate;
}

void Pracownik::WypiszDane()
{
	std::cout << *this;
}

Pracownik * Pracownik::KopiaObiektu() const
{
	return new Pracownik(*this);
}

std::ostream & operator<<(std::ostream & wy, const Pracownik & p)
{
	return wy << p.m_nIDZatrudnienia << " " << p.m_Imie << " " << p.m_Nazwisko << " " << p.m_DataUrodzenia;
}

std::istream & operator >> (std::istream & we, Pracownik & p)
{
	if (&we == &std::cin)
	{
		std::cout << "Podaj Imie: ";
		we >> p.m_Imie;
		std::cout << "Podaj nazwisko: ";
		we >> p.m_Nazwisko;
		std::cout << "Podaj date" << std::endl;
		we >> p.m_DataUrodzenia;
		return we;
	}
	else
	{
		we >> p.m_Imie;
		we >> p.m_Nazwisko;
		we >> p.m_DataUrodzenia;
		//ID z pliku rowniez dodaje automatycznie
		return we;
	}
}
