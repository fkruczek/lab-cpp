#define _CRT_SECURE_NO_WARNINGS 
#include "Napis.h"
#include <iostream>
#include <cstring>

Napis::Napis(const char * nap)
{
	m_nDl = strlen(nap);
	m_pszNapis = new char[m_nDl + 1];
	strcpy(m_pszNapis, nap);
}

Napis::Napis(const Napis & wzor)
{
	m_nDl = wzor.m_nDl;
	m_pszNapis = new char[m_nDl + 1];
	strcpy(m_pszNapis, wzor.m_pszNapis);
}

Napis::~Napis()
{
	delete[] m_pszNapis;
}

Napis & Napis::operator=(const Napis & wzor)
{
	if (&wzor != this)
	{
		m_nDl = wzor.m_nDl;
		delete[] m_pszNapis;
		m_pszNapis = new char[m_nDl + 1];
		strcpy(m_pszNapis, wzor.m_pszNapis);
	}
	return *this;
}

bool Napis::operator==(const Napis & wzor) const
{
	if (this->SprawdzNapis(wzor.m_pszNapis)) {
		return true;
	}
	return false;
}

const char * Napis::Zwroc() const
{
	return m_pszNapis;
}

void Napis::Ustaw(const char * nowy_napis)
{
	delete[] m_pszNapis;
	m_nDl = strlen(nowy_napis);
	m_pszNapis = new char[m_nDl + 1];
	strcpy(m_pszNapis, nowy_napis);
}

void Napis::Wypisz() const
{
	std::cout << Zwroc();
}

void Napis::Wpisz()
{
	std::cout << "Podaj ciag znakow: " << std::endl;
	std::cin >> m_pszNapis;
}

int Napis::SprawdzNapis(const char * por_napis) const
{
	int a = strcmp(m_pszNapis, por_napis);
	return a;
}

std::ostream & operator<<(std::ostream & wy, const Napis & p)
{
	return wy << p.m_pszNapis;
}

std::istream & operator >> (std::istream & we, Napis & p)
{
	char bufor[40];
	we >> bufor;
	p.Ustaw(bufor);
	return we;
}
