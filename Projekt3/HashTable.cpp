#include <iostream>
#include <cstring>
#include "HashTable.hpp"
#include "LinkedList.hpp"
HashTable::HashTable(int nrOfBuckets) : NumberOfBuckets(nrOfBuckets) 
{
    Array = new listNode*[NumberOfBuckets];
    for(int i = 0; i< NumberOfBuckets; i++) {
        Array[i] = nullptr;
    }
}
void HashTable::resize()
{
    int oldCapacity = NumberOfBuckets;
    NumberOfBuckets *=2;
    //stworzenie nowej, tymczasowej tablicy o pojemnosci 2x starej 
    listNode **tempArr = new listNode*[NumberOfBuckets];
    for (int i = 0; i < NumberOfBuckets; i++) {
        tempArr[i] = nullptr;
    }
    //przekopiowanie elementow z tablicy elements do tymczasowej tablicy (kopiuje elementy po usunietej liczbie i wkleja na jej miejsce)
    for (int i = 0; i < oldCapacity; i ++) {
        listNode* node = Array[i];
        while(node != nullptr) {
            listNode* nextNode = node->m_nextNode;

            int newIndex = hashFunc(node->m_key);

            node->m_nextNode = tempArr[newIndex];
            tempArr[newIndex] = node;

            node = nextNode;
        }
    }
    delete[] Array;

    // Point the Array to the new array
    Array = tempArr;   
}

int HashTable::hashFunc(unsigned int key)
{
    return key % NumberOfBuckets;
}

void HashTable::print() 
{
    for(int i = 0; i < NumberOfBuckets; i++) {
        std::cout << i << ": ";
        if(Array[i]) {
            listNode* temp = Array[i];
            while(temp) {
                std::cout << "  {" << temp->m_key << ", " << temp->m_value << "},";
                temp = temp->m_nextNode; 
            }
        }
        std::cout << std::endl;
    }
}

void HashTable::insert(unsigned int key, int value)
{
    int index = hashFunc(key);
    listNode* newNode = new listNode(value, key);
    newNode->m_nextNode = nullptr;
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

void HashTable::remove(unsigned int key)
{
    int index = hashFunc(key);
    listNode* prev = Array[index];
    listNode* temp = Array[index];
    if (temp->m_key == key) {
        Array[index] = temp->m_nextNode;
        delete temp;
        return;
    }

    while(temp != nullptr && temp->m_key != key) {
        prev = temp;
        temp = temp->m_nextNode;
    }
    if (temp != nullptr) {
        prev->m_nextNode = temp->m_nextNode;
        delete temp;
    } else {
        std::cout << "Key not found" << std::endl;
    }
}
