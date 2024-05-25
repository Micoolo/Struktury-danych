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
};

HashTable::HashTable(int nrOfBuckets) : NumberOfBuckets(nrOfBuckets) 
{
    Array = new listNode*[NumberOfBuckets];
}

void HashTable::print() 
{
    for(int i = 0; i < NumberOfBuckets; i++) {
        std::cout << i << ": " << std::endl;
        if(Array[i]) {
            listNode* temp = Array[i];
            while(temp) {
                std::cout << "  {" << temp->m_key << ", " << temp->m_value << "}" << std::endl;
                temp = temp->m_nextNode; 
            }
        }
    }
}