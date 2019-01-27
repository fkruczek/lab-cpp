#include "Data.h"


Data::Data()
{
}

Data::Data(int d, int m, int r)
{
	int m_nDzien = d;
	int m_nMiesiac = m;
	int m_nRok = r;
}

Data::Data(const Data & nowa)
{
	m_nDzien = nowa.m_nDzien;
	m_nMiesiac = nowa.m_nMiesiac;
	m_nRok = nowa.m_nRok;
}


Data::~Data()
{
}


void Data::Ustaw(int d, int m, int r)
{
	m_nDzien = d;
	m_nMiesiac = m;
	m_nRok = r;
	Data::Koryguj();
}

int Data::Dzien() const
{
	return m_nDzien;
}

int Data::Miesiac() const
{
	return m_nMiesiac;
}

int Data::Rok() const
{
	return m_nRok;
}

void Data::Wypisz() const
{
	std::cout << m_nDzien << "-" << m_nMiesiac << "-" << m_nRok;
}

void Data::Wpisz()
{
	int dzien, miesiac, rok;
	std::cout << "Podaj dzien: " << std::endl;
	std::cin >> dzien;
	std::cout << "Podaj miesiac: " << std::endl;
	std::cin >> miesiac; 
	std::cout << "Podaj rok: " << std::endl;
	std::cin >> rok;
	Ustaw(dzien, miesiac, rok);
}

void Data::Koryguj()
{
	int dni_lutego;
	if (m_nRok < 1900)
		m_nRok = 1900;
	else if (m_nRok > 2019) 
		m_nRok = 2019;
	if ((m_nRok % 4 == 0 && m_nRok % 100 != 0) || m_nRok % 400 == 0)  //warunek na rok przestepny
		dni_lutego = 29;
	else dni_lutego = 28;
	if (m_nMiesiac < 1)
		m_nMiesiac = 1;
	else if (m_nMiesiac > 12) 
		m_nMiesiac = 12;
	switch (m_nMiesiac)
	{
	case 1:	case 3:	case 5:	case 7:	case 8:	case 10: case 12:
		if (m_nDzien > 31) m_nDzien = 31;
		if (m_nDzien < 1) m_nDzien = 1;
		break;
	case 4:	case 6:	case 9:	case 11:
		if (m_nDzien > 30) m_nDzien = 30;
		if (m_nDzien < 1) m_nDzien = 1;
		break;
	case 2:
		if (m_nDzien > dni_lutego)	m_nDzien = dni_lutego;
		if (m_nDzien < 1) m_nDzien = 1;
		break;
	default:
		break;
	}
}

int Data::Porownaj(const Data & wzor) const
{
	if (this->m_nDzien == wzor.m_nDzien && this->m_nMiesiac == wzor.m_nMiesiac && this->m_nRok == wzor.m_nRok)
		return 0;
	else
	{
		if (wzor.m_nRok > this->m_nRok)
			return 1;
		else if (wzor.m_nRok == this->m_nRok && wzor.m_nMiesiac > this->m_nMiesiac)
			return 1;
		else if (this->m_nDzien < wzor.m_nDzien && this->m_nMiesiac == wzor.m_nMiesiac && this->m_nRok == wzor.m_nRok)
			return 1;
		else
			return -1;
	}
}

std::ostream & operator<<(std::ostream & wy, const Data & d)
{
	return wy << d.m_nDzien << "-" << d.m_nMiesiac << "-" << d.m_nRok << std::endl;
}

std::istream & operator >> (std::istream & we, Data & d)
{
	if (&we == &std::cin) {
		std::cout << "Podaj dzien: ";
		we >> d.m_nDzien;
		std::cout << "Podaj miesiac: ";
		we >> d.m_nMiesiac;
		std::cout << "Podaj rok: ";
		we >> d.m_nRok;
		d.Koryguj();
		return we;
	}
	else {
		char c;
		we >> d.m_nDzien;
		we >> c;
		we >> d.m_nMiesiac;
		we >> c;
		we >> d.m_nRok;
		d.Koryguj();
		return we;
	}
}
