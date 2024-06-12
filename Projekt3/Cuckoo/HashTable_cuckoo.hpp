#pragma once
#include <iostream>

struct Element {
    unsigned int m_key;
    int m_value;
};

class HashTableCuckoo {
private:
    Element emptyElement = {0, -1};
    const int nrOfIterations = 10000;
    Element *table1;
    Element *table2;
    int rehashCount = 0;
    int reh = 0;
    int size;
    int capacity;
    float loadFactor = 0; 
    int hashNumber = 1;  
    void checkIfResizeNeeded();
    bool checkIfKeyExists(unsigned int key);
    void clear();
    int hashFunc1(unsigned int key);
    int hashFunc2(unsigned int key);
    void rehash(bool resized);
    
public:
    HashTableCuckoo();
    ~HashTableCuckoo();
    void print();
    void insert(unsigned int key, int value);
    void remove(unsigned int key);
    int randomKey();
    int randomValue();
    void randomHashTable(int number);
    void sizeAndLoad();
    int findKey();
};