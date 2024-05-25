#include <iostream>
#include "ArrayList.hpp"


Tablica::Tablica() : size{0}, capacity{35}, elements{nullptr}
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


void Tablica::dodaj_losowo(int element)
{
    auto start = std::chrono::high_resolution_clock::now();
    srand(time(NULL));
    int randomNumber = rand() % size;  //losuje liczbe z przedzialu od 0 do size - 1 
    std::cout << "liczba wylosowana to: " << randomNumber << std::endl; 
    if (size == capacity)
    {
        capacity *=2;
        //stworzenie nowej, tymczasowej tablicy o pojemnosci 2x starej 
        int *tempArr = new int[capacity];
        //przekopiowanie elementow z tablicy elements do tymczasowej tablicy (kopiuje elementy po usunietej liczbie i wkleja na jej miejsce)
        std::memcpy(tempArr, elements, sizeof(int) * size);
        //usuwanie zawartosci starej tablicy ("czyszczenie")
        delete[] elements;
        elements = tempArr;
        std::memcpy(tempArr + randomNumber + 1, elements + randomNumber, sizeof(int) * (size - randomNumber));
    }
    else
    {
        //przekopiowanie elementow z tablicy elements do tymczasowej tablicy (kopiuje elementy po usunietej liczbie i wkleja na jej miejsce)
        std::memcpy(elements + randomNumber + 1, elements + randomNumber, sizeof(int) * (size - randomNumber));
    }

    elements[randomNumber] = element; 
    size++;
    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl; 
}


void Tablica::usun_losowy()
{
    auto start = std::chrono::high_resolution_clock::now();
    srand(time(NULL));
    int randomNumber = rand() % size;  //losuje liczbe z przedzialu od 0 do size - 1 

    int *tempArr = new int[capacity];
    //przekopiowanie elementow z tablicy elements do tymczasowej tablicy
    std::memcpy(tempArr, elements, sizeof(int) * size);
    //usuwanie zawartosci starej tablicy ("czyszczenie")
    delete[] elements;
    elements = tempArr; 
    std::memcpy(tempArr + randomNumber, elements + randomNumber + 1, sizeof(int) * (size - randomNumber -1));
    size--;
    if (size == (capacity / 2))
        capacity /= 2;
    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl; 
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