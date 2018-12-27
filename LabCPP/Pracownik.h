#pragma once
#ifndef _Pracownik_H_
#define _Pracownik_H_

#include "Napis.h"
#include "Data.h"

class Pracownik
{
private:
	Napis m_Imie;
	Napis m_Nazwisko;
	Data m_DataUrodzenia;
	const int m_nIDZatrudnienia;
	int ID; //dorobic id
public:
	Pracownik(const char *im = "", const char *naz= "", int dzien = 1, int miesiac = 1, int rok = 2000);
	Pracownik(const Pracownik & wzor);
	~Pracownik();

	Pracownik & operator=(const Pracownik & wzor);
	bool operator ==(const Pracownik &wzor) const;
	friend std::ostream & operator<<(std::ostream &wy, const Pracownik &p);
	friend std::istream & operator>>(std::istream &we, Pracownik &p);

	Pracownik* m_pNastepny;

	//metody informacyjne

	const char *Imie() const;
	const char *Nazwisko() const;

	//metody ustawiajace
	void Imie(const char *nowe_imie);
	void Nazwisko(const char *nowe_nazwisko);
	void DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok);

	//metody wyprowadzajace (w postaci: imie nazwisko dzien-miesiac-rok)
	void Wypisz() const;

	//metoda wprowadzajaca dane z cin
	void Wpisz();

	/*
		metoda porownujaca wartosc z przekazywanym wzorcem
		zwraca 0 gdy ==
		zwraca > 0 gdy m_Imie/m_Nazwisko > por_imie/por_nazwisko
	*/
	int SprawdzImie(const char *por_imie) const;
	int SprawdzNazwisko(const char *por_nazwisko) const;

	int Porownaj(const Pracownik& wzorzec) const;

	friend class Kierownik;
	virtual void WypiszDane();
	virtual Pracownik * KopiaObiektu();
};


#endif
