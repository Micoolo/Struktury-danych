#include <iostream>
#include "HashTable.hpp"
#include <chrono>

int main () {
    HashTable Table(10);
    
    // std::cout << std::endl << std::endl;
    Table.insert(352, 69);
    Table.insert(21, 11);
    Table.insert(45, 22);
    Table.insert(323, 33);
    Table.insert(41, 44);
    Table.print();
    // Table.remove(21);
    Table.insert(31, 44);
    Table.insert(11, 44);
    Table.remove(31);
    Table.insert(71, 44);
    // Table.remove(71);
    // Table.insert(81,44);
    // Table.remove(81);
    // Table.insert(91,44);
    // Table.resize();
    std::cout << std::endl;
    Table.print();
    // std::cout << Table.NumberOfBuckets; 
    return 0;
}