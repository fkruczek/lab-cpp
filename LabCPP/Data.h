#pragma once
#ifndef _Data_H_
#define _Data_H_

#include <iostream>


class Data
{
private:
	int m_nDzien;
	int m_nMiesiac;
	int m_nRok;
public:
	Data();
	Data(int d, int m, int r);
	~Data();
	void Ustaw(int d, int m, int r);

	//zwracaja wartosci poszczegolnych pol skladowych
	int Dzien() const;
	int Miesiac() const;
	int Rok() const;

	//wypisuje np 29-11-2018
	void Wypisz() const;

	//wprowadza z cin
	void Wpisz();

	//metoda korygujaca niepoprawna date (metode ta nalezy uzyc w metodzie ustaw) (29-2-2018 -> 28-2-2018)
	void Koryguj();

	//porownuje pola skladowe klasy z przekazywanym wzorcem (zwraca 0 gdy identyczne, 1 gdy wzorzec pozniejszy, -1 gdy wczesniejszy od daty wskazywanej przez this
	int Porownaj(const Data & wzor) const;

	friend std::ostream & operator<<(std::ostream & wy, const Data &d);
	friend std::istream & operator>>(std::istream & we, Data &d);
};

#endif