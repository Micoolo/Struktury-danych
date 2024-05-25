#include <iostream>
#include "ArrayList.hpp"


Tablica::Tablica() : capacity{35}, elements{nullptr}
{
    elements = new int [capacity];
}

//destruktor (zwalnia pamięć jesli tablica nie jest pusta)
Tablica::~Tablica()
{
    if (elements != nullptr)
    {
        delete[] elements;
        elements = nullptr;
    }
}
void Tablica::resize()
{
    int oldCapacity = capacity;
    capacity *=2;
    //stworzenie nowej, tymczasowej tablicy o pojemnosci 2x starej 
    int *tempArr = new int[capacity];
    //przekopiowanie elementow z tablicy elements do tymczasowej tablicy (kopiuje elementy po usunietej liczbie i wkleja na jej miejsce)
    std::memcpy(tempArr, elements, sizeof(int) * oldCapacity);
    //usuwanie zawartosci starej tablicy ("czyszczenie")
    delete[] elements;
    elements = tempArr;    
}


void Tablica::dodaj_losowo(int index, int element)
{
    elements[index] = element;
}


void Tablica::usun_losowy()
{

}

void Tablica::wyswietl() const
{
    for (int i = 0; i < size; i++)
        std::cout << i + 1 << ". " << elements[i] << std::endl;
}

unsigned int Tablica::rozmiar()
{
    return size;
}

unsigned int Tablica::pojemnosc()
{
    return capacity;
}