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
    void checkIfResizeNeeded(); //DOME
    bool checkIfKeyExists(unsigned int key); //DONE
    void clear(); //DONE
    int hashFunc1(unsigned int key); //DONE
    int hashFunc2(unsigned int key); //DONE
public:
    void rehash(bool resized);  //DONE
    HashTableCuckoo(); //DONE
    ~HashTableCuckoo(); //DONE
    void print(); //DONE
    void insert(unsigned int key, int value); //DONE
    void remove(unsigned int key); //DONE
    int randomKey(); //DONE
    int randomValue(); //DONE
    void randomHashTable(int number); //DONE
    void sizeAndLoad(); //DONE
    int findKey(); //DONE
};