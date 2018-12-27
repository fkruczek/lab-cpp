#define _CRT_SECURE_NO_WARNINGS 
#include "ListaPracownikow.h"
#include <iostream>

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
	kopia = new Pracownik(p);
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
		{
			std::cout << "Lista pusta. Nie ma co usuwac" << std::endl;
		}
		else
		{
			Pracownik *x = m_pPoczatek;
			if (wzorzec.Porownaj(*x) == 0)
			{
				m_pPoczatek = x->m_pNastepny;
				m_nLiczbaPracownikow--;
				delete x;
			}
			else
			{
				while (x->m_pNastepny != nullptr)
				{
					if (wzorzec.Porownaj(*x->m_pNastepny) == 0)
					{
						Pracownik *tmp = x->m_pNastepny->m_pNastepny;
						delete x->m_pNastepny->m_pNastepny;
						x->m_pNastepny = tmp;
						m_nLiczbaPracownikow--;
						break;
					}
					else { x = x->m_pNastepny; }
				}
			}
		}
	}

void ListaPracownikow::WypiszPracownikow() const
{
	if (m_pPoczatek == nullptr) std::cout << "Lista jest pusta. " << std::endl;
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
