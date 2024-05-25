#pragma once
#include <iostream>
// #include "../Projekt1/arraylist.h"
#include "LinkedList.hpp"

class HashTable {
private:
    unsigned int NumberOfBuckets;
    listNode** Array;

public:
    HashTable(int nrOfBuckets);
    void print();
    void set(int key, int value);

};
