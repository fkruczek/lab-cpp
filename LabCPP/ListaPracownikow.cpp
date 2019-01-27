#define _CRT_SECURE_NO_WARNINGS 
#include "ListaPracownikow.h"
#include <iostream>
#include <fstream>

ListaPracownikow::ListaPracownikow()
{
	//inicjujemy odpowiednie pola skladowe
	m_pPoczatek = nullptr;
	m_nLiczbaPracownikow = 0;
}


ListaPracownikow::~ListaPracownikow()
{
}

void ListaPracownikow::Dodaj(const Pracownik &p)
{
	Pracownik *kopia = nullptr;
	kopia = p.KopiaObiektu();
	if (m_nLiczbaPracownikow == 0)
	{
		m_pPoczatek = kopia;
		m_nLiczbaPracownikow++;
	}
	else if (m_nLiczbaPracownikow == 1 && kopia->Porownaj(*m_pPoczatek) < 0) {
		kopia->m_pNastepny = m_pPoczatek;
		m_pPoczatek = kopia;
	}
	else
	{
		Pracownik *x = m_pPoczatek;
		while (x != nullptr)
		{
			if (kopia->Porownaj(*x) > 0)
			{
				if (x->m_pNastepny != nullptr && kopia->Porownaj(*x->m_pNastepny) > 0)
				{
					x = x->m_pNastepny;
					continue;
				}
				else
				{
					kopia->m_pNastepny = x->m_pNastepny;
					x->m_pNastepny = kopia;
					m_nLiczbaPracownikow++;
					break;
				}
			}
			else { x = x->m_pNastepny; }
		}
	}
}


void ListaPracownikow::Usun(const Pracownik& wzorzec)
{
		if (m_nLiczbaPracownikow == 0)
			std::cout << "LISTA JEST PUSTA" << std::endl;
		else
		{
			Pracownik *x = m_pPoczatek;
			if (wzorzec.Porownaj(*x) == 0)
			{
				m_pPoczatek = x->m_pNastepny;
				m_nLiczbaPracownikow--;
				delete x;
				std::cout << "Usunieto" << std::endl;
			}
			else
			{
				while (x->m_pNastepny != nullptr)
				{
					if (wzorzec.Porownaj(*x->m_pNastepny) == 0)
					{
						Pracownik *tmp = x->m_pNastepny->m_pNastepny;
						delete x->m_pNastepny;
						x->m_pNastepny = tmp;
						m_nLiczbaPracownikow--;
						std::cout << "Usunieto" << std::endl;
						break;
					}
					else { x = x->m_pNastepny; }
				}
			}
		}
	}

void ListaPracownikow::WypiszPracownikow() const
{
	if (m_pPoczatek == nullptr)
		std::cout << "LISTA JEST PUSTA" << std::endl;
	else {
		Pracownik *tmp = m_pPoczatek;
		while (tmp != nullptr) 
		{
			tmp->Wypisz();
			tmp = tmp->m_pNastepny;
		}
	}
}

const Pracownik * ListaPracownikow::Szukaj(const char * nazwisko, const char * imie) const
{
	Pracownik *x = m_pPoczatek;
	Napis nazw, im;

	nazw.Ustaw(nazwisko);
	im.Ustaw(imie);

	while (x != nullptr) {
		if (nazw.SprawdzNapis(x->Nazwisko()) == 0 && im.SprawdzNapis(x->Imie()) == 0) return x;
		else x = x->m_pNastepny;
	}
	return x;
}

void ListaPracownikow::Zapisz()
{
	std::fstream plik;
	Pracownik *x = new Pracownik(*m_pPoczatek);
	plik.open("dane.txt", std::ios::out);
	if (plik.good())
	{
		while (x != nullptr)
		{
			plik << *x;
			x = x->m_pNastepny;
		}
		plik.close();
	}
}

void ListaPracownikow::Wczytaj()
{
	std::ifstream plik;
	Pracownik *p;
	plik.open("danein.txt", std::ios::in);
	if (plik.good())
	{
		while (!plik.eof())
		{
			p = new Pracownik;
			plik >> *p;
			this->Dodaj(*p);
			delete p;
		}
		plik.close();
	}
}

void ListaPracownikow::Wypisz() const
{
	if (m_nLiczbaPracownikow == 0)
		std::cout << "LISTA JEST PUSTA" << std::endl;
	else
	{
		Pracownik *x = m_pPoczatek;
		while (x != nullptr)
		{
			x->WypiszDane();
			x = x->m_pNastepny;
		}
	}
}