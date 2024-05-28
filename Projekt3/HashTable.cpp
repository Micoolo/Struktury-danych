#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <random> 
#include <chrono>
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

void HashTable::checkIfResizeNeeded()
{
    loadFactor = static_cast<float>(NumberOfElements)/NumberOfBuckets;
    if (loadFactor >= 0.70) {
        resize();
    }
}

void HashTable::sizeAndLoad()
{
    std::cout << "Number of elements: " << NumberOfElements << std::endl;
    checkIfResizeNeeded();
    std::cout << "Load Factor: " << loadFactor << std::endl;
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
    checkIfResizeNeeded();
    if (checkIfKeyExists(key)) {
        std::cout << "Key is already in table. " << std::endl;
        return;
    }
    int index = hashFunc(key);
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
    NumberOfElements++;
}

void HashTable::remove(unsigned int key)
{
    int index = hashFunc(key);
    listNode* prev = Array[index];
    listNode* temp = Array[index];
    if (temp == nullptr) {
        std::cout << "Key does not exist" << std::endl;
        return;
    }
    if (temp->m_key == key) {
        Array[index] = temp->m_nextNode;
        delete temp;
        NumberOfElements--;
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
    NumberOfElements--;
}

bool HashTable::checkIfKeyExists(int key)
{
    int index = hashFunc(key);
    listNode* temp = Array[index];

    while (temp != nullptr) {
        if (temp->m_key == key) {
            return true; 
        }
        temp = temp->m_nextNode;
    }

    return false;
}

int HashTable::findKey()
{
    if (NumberOfElements == 0) {
        return -1;
    }
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();

    std::mt19937 RN(seed);
    std::uniform_int_distribution<int> distribution(0, NumberOfBuckets - 1);
    int randomNumber = distribution(RN);

    for (int i = randomNumber; i < NumberOfBuckets; i++) {
        listNode* temp = Array[i]; 
        if (temp != nullptr) {
            return temp->m_key;
        }
        if (i == NumberOfBuckets - 1) {
            break;
        }
    }
    for (int i = randomNumber - 1; i >= 0; i--) {
        listNode* temp = Array[i]; 
        if (temp != nullptr) {
            return temp->m_key;
        }        
    }
    return -1;
}

int HashTable::randomKey()
{
    int randomNumber;
    do {
        auto keySeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();

        std::mt19937 rp(keySeed);
        std::uniform_int_distribution<int> rozklad(0, std::numeric_limits<int>::max());
        randomNumber = rozklad(rp);
    } while (checkIfKeyExists(randomNumber));
    return randomNumber;
}

int HashTable::randomValue()
{
    auto valueSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();

    int lowerBoundValue = -2147483648;
    int upperBoundValue = 2147483647;
    std::mt19937 rp(valueSeed);
    std::uniform_int_distribution<int> rozklad(lowerBoundValue, upperBoundValue);
    int randomNumber = rozklad(rp);

    return randomNumber;
}

void HashTable::randomHashTable(int number)
{
    if (NumberOfElements != 0) {
        clear();
    }
    int valueSeed = 345;
    int keySeed = 123; // seedy, w ktorych nie powtarzaja sie liczby (123, 158, 1890);
    
    
    int lowerBoundValue = -2147483648;
    int upperBoundValue = 2147483647;  

    std::mt19937 randVal(valueSeed);
    std::mt19937 randKey(keySeed);
    std::uniform_int_distribution<int> distributionValue(lowerBoundValue, upperBoundValue);
    std::uniform_int_distribution<int> distributionKey(0, std::numeric_limits<int>::max());

    for (int i = 0; i < number; i++) {
        int randomValue = distributionValue(randVal);
        int randomKey = distributionKey(randKey);
        insert(randomKey, randomValue);
    }

}

void HashTable::clear() 
{
    for (int i = 0; i < NumberOfBuckets; ++i) {
        listNode* current = Array[i];
        while (current != nullptr) {
            listNode* toDelete = current;
            current = current->m_nextNode;
            delete toDelete;
        }
    }
    
    delete[] Array;

    NumberOfBuckets = 75;
    Array = new listNode*[NumberOfBuckets];
    for (int i = 0; i < NumberOfBuckets; ++i) {
        Array[i] = nullptr;
    }


    NumberOfElements = 0;
}