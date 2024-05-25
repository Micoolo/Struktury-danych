#pragma once
#include "ArrayList.hpp"

class Tablica
{
    int *elements;
    unsigned int size;
    unsigned int capacity;

public:
    Tablica();
    ~Tablica();
    void resize();
    void dodaj_losowo(int index, int element);
    
    void usun_losowy();

    void wyswietl() const;

    unsigned int rozmiar();
    unsigned int pojemnosc();

};