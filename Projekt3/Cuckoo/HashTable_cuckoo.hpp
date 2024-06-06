#pragma once
#include <iostream>

struct Element {
    unsigned int m_key;
    int m_value;
};

class HashTableCuckoo {
private:
    Element emptyElement = {0, -1};
    const int nrOfIterations = 5000;
    Element *table1;
    Element *table2;
    int size;
    int capacity;
    float loadFactor = 0; 
    void resize();
    void checkIfResizeNeeded(); //DOME
    bool checkIfKeyExists(int key);
    void clear();   
    int hashFunc1(unsigned int key); //DONE
    int hashFunc2(unsigned int key); //DONE
    int hashNumber = 1;  
    void rehash(bool resized);  
public:
    HashTableCuckoo(); //DONE
    ~HashTableCuckoo(); //DONE
    void print();
    void insert(unsigned int key, int value); //DONE
    void remove(unsigned int key);
    int randomKey();
    int randomValue();
    void randomHashTable(int number);
    void sizeAndLoad(); //DONE
    int findKey();
};