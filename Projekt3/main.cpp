#include <iostream>
#include "HashTable.hpp"
#include <chrono>

int main () {
    HashTable Table(15);
    
    // std::cout << std::endl << std::endl;
    // Table.insert(352, 69);
    // Table.insert(21, 11);
    // Table.insert(45, 22);
    // Table.insert(323, 33);
    // Table.insert(41, 44);
    // Table.print();
    // // Table.remove(21);
    // Table.insert(31, 44);
    // Table.insert(11, 44);
    // // Table.remove(11);
    // Table.insert(71, 44);
    // // Table.remove(71);
    // Table.insert(81,44);
    // // Table.remove(81);
    // // Table.insert(91,44);
    // // Table.resize();
    // Table.checkIfResizeNeeded();
    // std::cout << std::endl;
    // Table.print();
    // int tab[10];
    // for (int i = 0; i < 10; i ++) {
    //     tab[i] = Table.randomKey();
    // }
    // for (int i = 0; i < 10; i ++) {
    //     std::cout << tab[i] << std::endl;
    // }    
    Table.randomHashTable(12);
    Table.insert(Table.randomKey(), Table.randomValue());
    Table.print();
    // std::cout << Table.NumberOfBuckets; 
    return 0;
}