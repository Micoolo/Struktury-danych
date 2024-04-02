#include "arraylist.h"
#include <iostream> 
#include <cstring> 
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include <chrono>

//konstruktor
Tablica::Tablica() : size{0}, capacity{2}, elements{nullptr}
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

void Tablica::wyswietl() const
{
    for (int i = 0; i < size; i++)
        std::cout << i + 1 << ". " << elements[i] << std::endl;
}

//wyszukuje podana liczba 
void Tablica::znajdz() const
{   
    auto start = std::chrono::high_resolution_clock::now();
    int lowerBound = -2147483648; // linie 206 - 209 to generator wartosci
    int upperBound = 2147483647;
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();//"losujemy" ziarno
    std::mt19937 generator(seed); 
    std::uniform_int_distribution<int> rozklad(lowerBound, upperBound); 
    int losowa_liczba = rozklad(generator);
    bool znaleziony = false;
    std::cout << "wygenerowana i szukana liczba: " << losowa_liczba << std::endl;
    for (int i = 0; i < size; i++)
    {
        if (losowa_liczba == elements[i])
        {    
            std::cout << i + 1 << ". " << elements[i] << std::endl;
            znaleziony = true;
        }
    }
    if (znaleziony == false)
    {
        std::cout << "W tablicy nie ma podanego elementu." << std::endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl; 
}

void Tablica::dodaj_na_koncu(int element)
{
    auto start = std::chrono::high_resolution_clock::now();
    if (size == capacity)
    {
        capacity *=2;
        //stworzenie nowej, tymczasowej tablicy o pojemnosci 2x starej 
        int *tempArr = new int[capacity];
        //przekopiowanie elementow z tablicy elements do tymczasowej tablicy
        std::memcpy(tempArr, elements, sizeof(int) * size);
        //usuwanie zawartosci starej tablicy ("czyszczenie")
        delete[] elements;
        elements = tempArr;
    }
    elements[size] = element;
    size++;
    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl; 
}

void Tablica::dodaj_na_poczatku(int element)
{
    auto start = std::chrono::high_resolution_clock::now();
    if (size == capacity)
    {
        capacity *=2;
        //stworzenie nowej, tymczasowej tablicy o pojemnosci 2x starej 
        int *tempArr = new int[capacity];
        //przekopiowanie elementow z tablicy elements do tymczasowej tablicy
        std::memcpy(tempArr + 1, elements, sizeof(int) * size);
        //usuwanie zawartosci starej tablicy ("czyszczenie")
        delete[] elements;
        elements = tempArr;
    }
    else
    {
        //przesuwanie elementow o jedno miejsce w przod
        std::memcpy(elements + 1, elements, sizeof(int) * size);
    }

    elements[0] = element;
    size++;
    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl; 
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

void Tablica::usun_ostatni()
{
    auto start = std::chrono::high_resolution_clock::now();
    int *tempArr = new int[capacity];
    //przekopiowanie elementow z tablicy elements do tymczasowej tablicy (bez ostatniego elementu, _MaxCount w funkcji memcpy jest ostawiony na przedostatni element)
    std::memcpy(tempArr, elements, sizeof(int) * (size - 1));
    //usuwanie zawartosci starej tablicy ("czyszczenie")
    delete[] elements;
    elements = tempArr;
    size--;
    if (size == (capacity / 2))
        capacity /= 2;
    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl; 
}

void Tablica::usun_pierwszy()
{
    auto start = std::chrono::high_resolution_clock::now();
    int *tempArr = new int[capacity];
    //przekopiowanie elementow z tablicy elements do tymczasowej tablicy (bez ostatniego elementu, _MaxCount w funkcji memcpy jest ostawiony na przedostatni element)
    std::memcpy(tempArr, elements + 1, sizeof(int) * (size - 1));
    //usuwanie zawartosci starej tablicy ("czyszczenie")
    delete[] elements;
    elements = tempArr;
    size--;
    if (size == (capacity / 2))
        capacity /= 2;
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

unsigned int Tablica::rozmiar()
{
    return size;
}

unsigned int Tablica::pojemnosc()
{
    return capacity;
}

void Tablica::generuj(int liczba)
{
    delete[] elements;
    capacity = 2;
    size = 0;
    elements = new int[capacity];; 
    int lowerBound = -2147483648; // linie 206 - 209 to generator wartosci
    int upperBound = 2147483647;
    std::mt19937 generator(123); // Inicjalizacja generatora liczb losowych z ziarnem 123
    std::uniform_int_distribution<int> rozklad(lowerBound, upperBound); 
    for (int i = 0; i < liczba; i++) 
    {
        int scaledNumber = rozklad(generator);
        if (size == capacity)
        {
        capacity *=2;
            //stworzenie nowej, tymczasowej tablicy o pojemnosci 2x starej 
            int *tempArr = new int[capacity];
            //przekopiowanie elementow z tablicy elements do tymczasowej tablicy
            std::memcpy(tempArr, elements, sizeof(int) * size);
            //usuwanie zawartosci starej tablicy ("czyszczenie")
            delete[] elements;
            elements = tempArr;
        }
        elements[size] = scaledNumber;
        size++;
    }
}

void Tablica::reset()
{
    delete[] elements;
    capacity = 2;
    size = 0;
    elements = new int[capacity];; 

}