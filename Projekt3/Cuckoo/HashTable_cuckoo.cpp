#include <iostream>
#include "HashTable_cuckoo.hpp"
#include <random>
#include <chrono>
#include <string>
#include <utility>

HashTableCuckoo::HashTableCuckoo() : size(0), capacity(75)
{
    table1 = new Element[capacity];
    table2 = new Element[capacity];
    for (int i = 0; i < capacity; i++) {
        table1[i] = emptyElement;
        table2[i] = emptyElement;
    }
}

HashTableCuckoo::~HashTableCuckoo()
{
    delete[] table1;
    delete[] table2;
}

void HashTableCuckoo::rehash(bool resized)
{
    int oldCapacity = capacity;
    if (resized) {
        capacity *= 2;
    }

    Element* oldTable1 = table1;
    Element* oldTable2 = table2;

    table1 = new Element[capacity];
    table2 = new Element[capacity];
    for (int i = 0; i < capacity; ++i) {
        table1[i] = emptyElement;
        table2[i] = emptyElement;
    }

    size = 0;
    if (!resized) {
        hashNumber++;
        rehashCount++;
    } else if (resized) {
        hashNumber = 1;
        rehashCount = 0;
    }

    for (int i = 0; i < oldCapacity; ++i) {
        if (oldTable1[i].m_key != emptyElement.m_key) {
            insert(oldTable1[i].m_key, oldTable1[i].m_value);
        }
        if (oldTable2[i].m_key != emptyElement.m_key) {
            insert(oldTable2[i].m_key, oldTable2[i].m_value);
        }
    }

    delete[] oldTable1;
    delete[] oldTable2;
}

int HashTableCuckoo::hashFunc1(unsigned int key)
{
    int k = 7;
    k = ((11 * key) / hashNumber) % capacity;
    return k;
}

int HashTableCuckoo::hashFunc2(unsigned int key)
{
    int k = 7;
    k = ((5 * key) / hashNumber) % capacity;
    return k;
}


void HashTableCuckoo::insert(unsigned int key, int value) 
{
    checkIfResizeNeeded();
    Element newElement = {key, value};
    int index = hashFunc1(key);
    
    for (int i = 0; i < nrOfIterations; i++) {
        if (table1[index].m_key == emptyElement.m_key) {
            table1[index] = newElement;
            size++;
            checkIfResizeNeeded();
            return;
        }

        std::swap(newElement, table1[index]);
        index = hashFunc2(newElement.m_key);

        if (table2[index].m_key == emptyElement.m_key) {
            table2[index] = newElement;
            size++;
            checkIfResizeNeeded();
            return;
        } 
        
        std::swap(newElement, table2[index]);
        index = hashFunc1(newElement.m_key);
    }

    if (rehashCount > 10) {
        rehash(true);    
    } else {
        rehash(false);
    }
    insert(newElement.m_key, newElement.m_value);
} 

void HashTableCuckoo::sizeAndLoad()
{
    checkIfResizeNeeded();
    std::cout << "Number of elements: " << size << std::endl;
    std::cout << "Capacity: " << capacity * 2 << std::endl;
    std::cout << "Load Factor: " << loadFactor << std::endl;
}

void HashTableCuckoo::checkIfResizeNeeded()
{
    loadFactor = static_cast<float>(size)/(capacity*2);
    if (loadFactor >= 0.50) {
        rehash(true);
    }
}

void HashTableCuckoo::print()
{
    for (int i = 0; i < capacity; i++) {
        if (table1[i].m_key != emptyElement.m_key || table2[i].m_key != emptyElement.m_key) {
            if (table1[i].m_key == emptyElement.m_key) {
                std::cout << "Table 1 [" << i << "]: empty      Table 2 [" << i << "]: {" << table2[i].m_key << ", " << table2[i].m_value << "}" << std::endl;  
            } else if (table2[i].m_key == emptyElement.m_key) {
                std::cout << "Table 1 [" << i << "]: {" << table1[i].m_key << ", " << table1[i].m_value << "}       " "Table 2 [" << i << "]: empty" << std::endl;  
            } else {
                std::cout << "Table 1 [" << i << "]: {" << table1[i].m_key << ", " << table1[i].m_value << "}       " "Table 2 [" << i << "]: {" << table2[i].m_key << ", " << table2[i].m_value << "}" << std::endl;
            }
        }
        
    }
}

bool HashTableCuckoo::checkIfKeyExists(unsigned int key)
{
    int index = hashFunc1(key);
    if (table1[index].m_key == key) 
        return true;
    index = hashFunc2(key);
    if (table2[index].m_key == key)
        return true;
    return false;
}

void HashTableCuckoo::remove(unsigned int key) 
{
    int index = hashFunc1(key);
    if (table1[index].m_key == key) 
        table1[index] = emptyElement;
    index = hashFunc2(key);
    if (table2[index].m_key == key)
        table2[index] = emptyElement;
    size--;
}

void HashTableCuckoo::clear()
{
    delete[] table1;
    delete[] table2;
    
    capacity = 75;
    size = 0;
    loadFactor = 0;
    hashNumber = 1;

    table1 = new Element[capacity];
    table2 = new Element[capacity];
    for (int i = 0; i < capacity; i++) {
        table1[i] = emptyElement;
        table2[i] = emptyElement;
    }
}

int HashTableCuckoo::randomKey()
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

int HashTableCuckoo::randomValue()
{
    auto valueSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();

    int lowerBoundValue = -2147483648;
    int upperBoundValue = 2147483647;
    std::mt19937 rp(valueSeed);
    std::uniform_int_distribution<int> rozklad(lowerBoundValue, upperBoundValue);
    int randomNumber = rozklad(rp);

    return randomNumber;
}

int HashTableCuckoo::findKey()
{
    if (size == 0) {
        return -1;
    }
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();

    std::mt19937 RN(seed);
    std::uniform_int_distribution<int> tableDist(1, 2);
    std::uniform_int_distribution<int> distribution(0, capacity - 1);
    int tableNumber = tableDist(RN);
    int randomNumber = distribution(RN);

    if (tableNumber == 2) {
        for (int i = randomNumber; i < capacity; i++) {
            if (table2[i].m_key != emptyElement.m_key) {
                return table2[i].m_key;
            }
        }
        for (int i = randomNumber - 1; i >= 0; i--) {
            if (table2[i].m_key != emptyElement.m_key) {
                return table2[i].m_key;
            }
        }
    }  

    for (int i = randomNumber; i < capacity; i++) {
        if (table1[i].m_key != emptyElement.m_key) {
            return table1[i].m_key;
        }
    }
    for (int i = randomNumber - 1; i >= 0; i--) {
        if (table1[i].m_key != emptyElement.m_key) {
            return table1[i].m_key;
        }
    }  

    return -1;
}

void HashTableCuckoo::randomHashTable(int number)
{
    if (size != 0) {
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