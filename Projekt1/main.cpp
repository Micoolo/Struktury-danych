#include <iostream>
#include "arraylist.cpp"
#include <chrono>
#include "linkedList.cpp"
#include "LinkedList_tail.cpp"

void menuTablica()
{
    Tablica tablica;
    bool exit = false;
    int opcja;
    do 
    {
        std::cout << std::endl << "----------TABLICA----------" << std::endl;
        std::cout << "-------WYBIERZ OPCJE-------" << std::endl;
        std::cout << "1) Generuj dane w tablicy / Wyczysc i wygeneruj " << std::endl;
        std::cout << "2) Dodaj element" << std::endl;
        std::cout << "3) Usun element " << std::endl;
        std::cout << "4) Wyswietl rozmiar i pojemnosc tablicy" << std::endl;
        std::cout << "5) Wyswietl zawartosc tablicy" << std::endl;
        std::cout << "6) Znajdz element w tablicy" << std::endl;
        std::cout << "7) Wyczysc tablice" << std::endl;
        std::cout << "8) Zakoncz program" << std::endl;
        std::cin >> opcja;

        switch(opcja)
        {
            case 1:
                int IleLiczb;
                std::cout << "Podaj ile liczb chcesz wygenerowac i dodac do tablicy: ";
                std::cin >> IleLiczb;
                tablica.generuj(IleLiczb);
                break;
            case 2:
                int dodaj;
                int liczba;
                std::cout << "Wybierz gdzie chcesz dodac element" << std::endl;
                std::cout << "1) Na koncu " << std::endl;
                std::cout << "2) Na poczatku " << std::endl;
                std::cout << "3) Losowo" << std::endl;
                std::cout << "4) Wroc do menu" << std::endl;
                std::cin >> dodaj;
                std::cout << "Podaj liczbe, ktora chcesz dodac: ";
                std::cin >> liczba;             
                switch(dodaj)
                {
                    case 1:
                        tablica.dodaj_na_koncu(liczba);
                        break;
                    case 2:
                        tablica.dodaj_na_poczatku(liczba);
                        break;
                    case 3:
                        tablica.dodaj_losowo(liczba);
                        break;
                    case 4:

                        break;
                }
                break;
            case 3:
                int usun;
                std::cout << "Wybierz ktory element chcesz usunac" << std::endl;
                std::cout << "1) Ostatni " << std::endl;
                std::cout << "2) Pierwszy " << std::endl;
                std::cout << "3) Losowy" << std::endl;
                std::cout << "4) Wroc do menu" << std::endl;
                std::cin >> usun;
                switch(usun)
                {
                    case 1:
                        tablica.usun_ostatni();
                        break;
                    case 2:
                        tablica.usun_pierwszy();
                        break;
                    case 3:
                        tablica.usun_losowy();
                        break;
                    case 4:

                        break;
                }
                break;
            case 4:
                std::cout << "Rozmiar tablicy: " << tablica.rozmiar() << std::endl;
                std::cout << "Pojemnosc tablicy: " << tablica.pojemnosc() << std::endl;
                break;
            case 5:
                tablica.wyswietl();
                break;
            case 6:
                tablica.znajdz();
                break;
            case 7:
                tablica.reset();
                break;
            case 8:
                exit = true;
                break;

        }
    } while (!exit);
    

    



}

void menuLista()
{
    linkedList lista;
    bool exit = false;
    int opcja;
    do 
    {
        std::cout << std::endl << "----------LISTA----------" << std::endl;
        std::cout << "-------WYBIERZ OPCJE-------" << std::endl;
        std::cout << "1) Generuj dane w liscie / Wyczysc i wygeneruj " << std::endl;
        std::cout << "2) Dodaj element" << std::endl;
        std::cout << "3) Usun element " << std::endl;
        std::cout << "4) Wyswietl rozmiar i pojemnosc listy" << std::endl;
        std::cout << "5) Wyswietl zawartosc listy" << std::endl;
        std::cout << "6) Znajdz element w liscie" << std::endl;
        std::cout << "7) Wyczysc liste" << std::endl;
        std::cout << "8) Zakoncz program" << std::endl;
        std::cin >> opcja;

        switch(opcja)
        {
            case 1:
                int IleLiczb;
                std::cout << "Podaj ile liczb chcesz wygenerowac i dodac do listy: ";
                std::cin >> IleLiczb;
                lista.randomList(IleLiczb);
                break;
            case 2:
                int dodaj;
                int liczba;
                std::cout << "Wybierz gdzie chcesz dodac element" << std::endl;
                std::cout << "1) Na koncu " << std::endl;
                std::cout << "2) Na poczatku " << std::endl;
                std::cout << "3) Losowo" << std::endl;
                std::cout << "4) Wroc do menu" << std::endl;
                std::cin >> dodaj;
                std::cout << "Podaj liczbe, ktora chcesz dodac: ";
                std::cin >> liczba;             
                switch(dodaj)
                {
                    case 1:
                        lista.add(liczba);
                        break;
                    case 2:
                        lista.addAtBeginning(liczba);
                        break;
                    case 3:
                        lista.addRand(liczba);
                        break;
                    case 4:

                        break;
                }
                break;
            case 3:
                int usun;
                std::cout << "Wybierz ktory element chcesz usunac" << std::endl;
                std::cout << "1) Ostatni " << std::endl;
                std::cout << "2) Pierwszy " << std::endl;
                std::cout << "3) Losowy" << std::endl;
                std::cout << "4) Wroc do menu" << std::endl;
                std::cin >> usun;
                switch(usun)
                {
                    case 1:
                        lista.removeLast();
                        break;
                    case 2:
                        lista.removeFirst();
                        break;
                    case 3:
                        lista.removeRand();
                        break;
                    case 4:

                        break;
                }
                break;
            case 4:
                std::cout << "Rozmiar listy: " << lista.size() << std::endl;
                break;
            case 5:
                lista.showList();
                break;
            case 6:
                lista.search();
                break;
            case 7:
                lista.clear();
                break;
            case 8:
                exit = true;
                break;

        }
    } while (!exit);
    
}

void menuListaT()
{
    linkedListT lista;
    bool exit = false;
    int opcja;
    do 
    {
        std::cout << std::endl << "----------LISTA----------" << std::endl;
        std::cout << "-------WYBIERZ OPCJE-------" << std::endl;
        std::cout << "1) Generuj dane w liscie / Wyczysc i wygeneruj " << std::endl;
        std::cout << "2) Dodaj element" << std::endl;
        std::cout << "3) Usun element " << std::endl;
        std::cout << "4) Wyswietl rozmiar i pojemnosc listy" << std::endl;
        std::cout << "5) Wyswietl zawartosc listy" << std::endl;
        std::cout << "6) Znajdz element w liscie" << std::endl;
        std::cout << "7) Wyczysc liste" << std::endl;
        std::cout << "8) Zakoncz program" << std::endl;
        std::cin >> opcja;

        switch(opcja)
        {
            case 1:
                int IleLiczb;
                std::cout << "Podaj ile liczb chcesz wygenerowac i dodac do listy: ";
                std::cin >> IleLiczb;
                lista.randomList(IleLiczb);
                break;
            case 2:
                int dodaj;
                int liczba;
                std::cout << "Wybierz gdzie chcesz dodac element" << std::endl;
                std::cout << "1) Na koncu " << std::endl;
                std::cout << "2) Na poczatku " << std::endl;
                std::cout << "3) Losowo" << std::endl;
                std::cout << "4) Wroc do menu" << std::endl;
                std::cin >> dodaj;
                std::cout << "Podaj liczbe, ktora chcesz dodac: ";
                std::cin >> liczba;             
                switch(dodaj)
                {
                    case 1:
                        lista.add(liczba);
                        break;
                    case 2:
                        lista.addAtBeginning(liczba);
                        break;
                    case 3:
                        lista.addRand(liczba);
                        break;
                    case 4:

                        break;
                }
                break;
            case 3:
                int usun;
                std::cout << "Wybierz ktory element chcesz usunac" << std::endl;
                std::cout << "1) Ostatni " << std::endl;
                std::cout << "2) Pierwszy " << std::endl;
                std::cout << "3) Losowy" << std::endl;
                std::cout << "4) Wroc do menu" << std::endl;
                std::cin >> usun;
                switch(usun)
                {
                    case 1:
                        lista.removeLast();
                        break;
                    case 2:
                        lista.removeFirst();
                        break;
                    case 3:
                        lista.removeRand();
                        break;
                    case 4:

                        break;
                }
                break;
            case 4:
                std::cout << "Rozmiar listy: " << lista.size() << std::endl;
                break;
            case 5:
                lista.showList();
                break;
            case 6:
                lista.search();
                break;
            case 7:
                lista.clear();
                break;
            case 8:
                exit = true;
                break;

        }
    } while (!exit);
    
}

int main()
{
    bool powtorz;
    int wybor;
    do
    {
        powtorz = false;
        std::cout << "----------MENU GLOWNE----------" << std::endl;
        std::cout << "-------WYBIERZ STRUKTURE-------" << std::endl;
        std::cout << "1) Tablica dynamiczna (ArrayList)" << std::endl;
        std::cout << "2) Lista jednokierunkowa (head)" << std::endl;
        std::cout << "3) Lista jednokierunkowa (head i tail)" << std::endl;
        std::cin >> wybor;

        switch(wybor)
        {
            case 1:
                menuTablica();
                break;
            case 2: 
                menuLista();
                break;
            case 3: 
                menuListaT();
                break;
            default:
                std::cout << "Wybrano nieprawidlowa opcje." << std::endl << std::endl; 
                powtorz = true;
                break;
        }
    } while (powtorz);
    return 0;
}