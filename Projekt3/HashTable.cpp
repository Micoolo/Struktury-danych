#include <iostream>
#include "HashTable.hpp"
#include "LinkedList.hpp"
HashTable::HashTable(int nrOfBuckets) : NumberOfBuckets(nrOfBuckets) 
{
    Array = new listNode*[NumberOfBuckets];
    for(int i = 0; i< NumberOfBuckets; i++) {
        Array[i] = nullptr;
    }
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

void HashTable::set(int key, int value)
{
    int index = key;
    listNode* newNode = new listNode(value, key);
    if (Array[index] == nullptr) {
        Array[index] = newNode;
    } else {
        listNode* temp = Array[index];
        while(temp->m_nextNode != nullptr) {
            temp = temp->m_nextNode;
        }
        temp->m_nextNode = newNode;
    }
}