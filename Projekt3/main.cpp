#include <iostream>
#include "HashTable.hpp"
#include <chrono>

void HashTable_menu() {
    HashTable Table(75);
    bool exit = false;
    do {
        std::cout << std::endl << "-------HASHTABLE BUCKETS WITH LIST-------" << std::endl;
        std::cout << "--------------CHOOSE OPTION--------------" << std::endl;
        std::cout << "1) Generate elements " << std::endl;
        std::cout << "2) Insert element (K, V)" << std::endl;
        std::cout << "3) Insert random element " << std::endl;
        std::cout << "4) Remove (K) " << std::endl;
        std::cout << "5) Remove random" << std::endl;
        std::cout << "6) Print" << std::endl;
        std::cout << "7) Size" << std::endl;
        std::cout << "8) Exit" << std::endl;
        int choice;
        std::cin >> choice;
        switch(choice) {
            case 1: {
                std::cout << "How many numbers to generate? ";
                int number; 
                std::cin >> number; 
                Table.randomHashTable(number);
                break;
            }
            case 2: {
                std::cout << "Enter key and value: ";
                int key, value; 
                std::cin >> key >> value;
                Table.insert(key, value);
                break;
            }
            case 3: {
                int key = Table.randomKey();
                int value = Table.randomValue();
                Table.insert(key, value);
                break;
            }
            case 4: {
                int key; 
                std::cin >> key;
                Table.remove(key);
                break;
            }
            case 5: {
                int key = Table.findKey();
                if (key == -1) {
                    std::cout << "Table is empty" << std::endl;
                    break;
                }
                Table.remove(key);
                break;
            }
            case 6: {
                Table.print();
                break;
            }
            case 7: {
                Table.sizeAndLoad();
                break;
            }
            case 8: {
                exit = true;
                break;
            }
            default: {
                break;
            } 
        }
    } while (!exit);
}


int main () {
    HashTable_menu();
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
    // Table.randomHashTable(12);
    // Table.insert(Table.randomKey(), Table.randomValue());
    // Table.print();
    // std::cout << Table.NumberOfBuckets; 
    return 0;
}