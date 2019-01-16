#pragma once
#ifndef _ListaPracownikow_H_
#define _ListaPracownikow_H_

#include "Pracownik.h"
#include "Kierownik.h"

class ListaPracownikow
{
private:
	Pracownik* m_pPoczatek;
	int m_nLiczbaPracownikow;
public:
	ListaPracownikow();
	~ListaPracownikow();

	void Dodaj(const Pracownik & p);

	void Usun(const Pracownik & wzorzec);

	void WypiszPracownikow() const;

	const Pracownik* Szukaj(const char* nazwisko, const char* imie) const;
	void Wypisz() const;
	void Zapisz();
	void Wczytaj();
};

#endif