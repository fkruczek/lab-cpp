#pragma once
#include <iostream>
class Napis
{
private:
	char *m_pszNapis;
	int m_nDl;
public:
	Napis(const char *nap = "");
	Napis(const Napis & wzor);
	~Napis();
	
	Napis & operator=(const Napis & wzor);
	bool operator==(const Napis & wzor) const;
	//zwraca pole skladowe klasy
	const char *Zwroc() const;

	//ustawia pole m_pszNapis na podstawie przekazanego argumentu
	void Ustaw(const char *nowy_napis);

	//wyprowadza zawartosc pola skladowego do cout
	void Wypisz() const;

	//wprowadza z cin do pola skladowego klasy
	void Wpisz();

	/*
	porownuje wartosc pola skladowego z przekazywanym wzorcem
	zwraca 0(zero) gdy pole skladowe klasy (m_pszNapis) jest identyczne z podanym wzorcem (por_napis)
	zwraca wartosc wieksza od zera gdy m_pszNapis>por_napis
	mniejsza od zera gdy..
	*/
	int SprawdzNapis(const char* por_napis) const;
	

	friend std::ostream & operator << (std::ostream & wy, const Napis & p);
	friend std::istream & operator >> (std::istream & we, Napis & p);

};

