#include <iostream>
#include "BucketsWithLists/HashTable_buckets.hpp"
#include <chrono>
#include "Cuckoo/HashTable_cuckoo.hpp"

void HashTable_menu() {
    HashTableBuckets Table(75);
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
    // HashTable_menu();
    HashTableCuckoo table;
    table.insert(1, 121);
    table.insert(11, 122);
    table.insert(21, 123);
    table.insert(2, 124);
    table.print();
    std::cout << std::endl << std::endl;
    table.insert(22, 125);
    table.insert(12, 126);
    table.insert(44, 127);
    table.insert(457123, 128);
    table.insert(52, 127);
    table.insert(1236, 128);
    table.print();
    table.sizeAndLoad();
    // table.print();
    // table.sizeAndLoad();
    return 0;
}