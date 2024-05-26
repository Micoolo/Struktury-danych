#pragma once
#include <iostream>
// #include "../Projekt1/arraylist.h"
#include "LinkedList.hpp"



class HashTable {
private:

public:
    int hashFunc(unsigned int key);
    unsigned int NumberOfBuckets;
    unsigned int NumberOfElements = 0; 
    float loadFactor = 0; 
    listNode** Array;
    void resize();

public:
    HashTable(int nrOfBuckets);
    void print();
    void insert(unsigned int key, int value);
    void remove(unsigned int key);
    void checkIfResizeNeeded();
    bool checkIfKeyExists(int key);
    int randomKey();
    int randomValue();
    void randomHashTable(int number);
};
