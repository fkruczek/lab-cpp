//L04 Fryderyk Kruczek
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstring>
#include "Data.h"
#include "Pracownik.h"
#include "Napis.h"
#include "ListaPracownikow.h"

void wyswietlMenu();

int main()
{
	Pracownik pierwszy, drugi;
	ListaPracownikow pracownicy;

	pierwszy.Imie("Zndrzej");
	pierwszy.Nazwisko("Zaran");

	drugi.Imie("adam");
	drugi.Nazwisko("Auda");

	pracownicy.Dodaj(pierwszy);

	pracownicy.Dodaj(drugi);

	pracownicy.WypiszPracownikow();

	std::cout << "Wypisano" << std::endl;
	std::cin.get();
	std::cin.get();

	pracownicy.Usun(pierwszy);
	std::cout << "Usunieto" << std::endl;
	std::cin.get();
	std::cin.get();

   pracownicy.WypiszPracownikow();
	std::cout << "Wypisano" << std::endl;
	std::cin.get();
	std::cin.get();

//	pracownicy.Szukaj("nowak", "adam")->Wypisz();
	return 0;
}

void wyswietlMenu()
{
	std::cout << "Menu : ";
}
