#pragma once
#include <iostream>
// #include "../Projekt1/arraylist.h"
#include "LinkedList.hpp"



class HashTable {
private:

public:
    int hashFunc(unsigned int key);
    unsigned int NumberOfBuckets;
    listNode** Array;
    void resize();

public:

    HashTable(int nrOfBuckets);
    void print();
    void insert(unsigned int key, int value);
    void remove(unsigned int key);
};
