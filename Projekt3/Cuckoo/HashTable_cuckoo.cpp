#include <iostream>
#include "HashTable_cuckoo.hpp"

HashTableCuckoo::HashTableCuckoo() : size(0), capacity(5)
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
    } else if (resized) {
        hashNumber = 1;
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
    return (key/hashNumber) % capacity;
}

int HashTableCuckoo::hashFunc2(unsigned int key)
{
    return ((((key - 1) * 2) / 3) / hashNumber) % capacity;
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
    rehash(false);
    insert(key, value);
} 

void HashTableCuckoo::sizeAndLoad()
{
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
}

