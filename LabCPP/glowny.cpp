//L04 Fryderyk Kruczek
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstring>
#include "Data.h"
#include "Pracownik.h"
#include "Napis.h"
#include "ListaPracownikow.h"
#include "Kierownik.h"
void WyswietlMenu();
int main()
{
	bool czyWyjsc = false;
	char wybor;
	Pracownik *osoba;
	Kierownik *kiero;
	const Pracownik *o;
	ListaPracownikow Pracownicy;
	while (!czyWyjsc)
	{
		WyswietlMenu();
		std::cin >> wybor;
		switch (wybor)
		{
			case 'd':
				std::cout << "p - pracownik \nk - kierownik" << std::endl;
				std::cin >> wybor;
				if (wybor == 'p') {
					std::cout << "Dane pracownika do dodania:" << std::endl;
					osoba = new Pracownik;
					std::cin >> *osoba;
					Pracownicy.Dodaj(*osoba);
					delete osoba;
				}
				else {
					std::cout << "Dane kierownika do dodania:" << std::endl;
					kiero = new Kierownik;
					std::cin >> *kiero;
					Pracownicy.Dodaj(*kiero);
					delete kiero;
				}
				break;
			case 'u':
				std::cout << "Dane pracownika do usuniecia:" << std::endl;
				osoba = new Pracownik;
				std::cin >> *osoba;
				Pracownicy.Usun(*osoba);
				delete osoba;
				break;
			case 'w':
				std::cout << "Lista pracownikow: " << std::endl;
				Pracownicy.Wypisz();
				break;
			case 's':
				std::cout << "Dane pracownika do wyszukania:" << std::endl;
				osoba = new Pracownik;
				std::cin >> *osoba;
				o = Pracownicy.Szukaj(osoba->Nazwisko(), osoba->Imie());
				if (o != nullptr) { std::cout << "Znaleziono pracownika." << std::endl; }
				else { std::cout << "Nie znaleziono pracownika" << std::endl; }
				delete osoba;
				break;
			case 'z':
				Pracownicy.Zapisz();
				break;
			case 'o':
				Pracownicy.Wczytaj();
				break;
			case 'q':
				czyWyjsc = true;
				break;
			default:
				std::cout << std::endl << "" << std::endl;
				break;
		}
		std::cout << "Koniec";
		std::getchar();
		std::getchar();
	}
	return 0;
}

void WyswietlMenu() 
{
	system("cls");
	std::cout << "MENU GLOWNE:"
		<< std::endl << "d - dodaj pracownika"
		<< std::endl << "u - usun pracownika"
		<< std::endl << "w - wyswietl liste pracownikow"
		<< std::endl << "s - szukaj pracownika"
		<< std::endl << "z - zapis do pliku"
		<< std::endl << "o - wczytaj z pliku"
		<< std::endl << "q - wyjscie"
		<< std::endl << "Wybor: ";
}