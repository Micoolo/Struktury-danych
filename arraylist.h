#pragma once

class Tablica
{
    int *elements;
    unsigned int size;
    unsigned int capacity;

public:
    Tablica();
    ~Tablica();

    void dodaj_na_koncu(int element);
    void dodaj_na_poczatku(int element);
    void dodaj_losowo(int element);
    
    void usun_ostatni();
    void usun_pierwszy();
    void usun_losowy();

    void znajdz() const;

    void wyswietl() const;

    unsigned int rozmiar();
    unsigned int pojemnosc();

    void reset();

    void generuj(int liczba);
};