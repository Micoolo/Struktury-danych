#include <iostream>
#include "BucketsWithLists/HashTable_buckets.hpp"
#include <chrono>
#include "Cuckoo/HashTable_cuckoo.hpp"
#include "OpenAdressing/HashTable_open.hpp"
#include <chrono>

void HashTableBuckets_menu() {
    HashTableBuckets Table;
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
                auto start = std::chrono::high_resolution_clock::now();

                Table.insert(key, value);

                auto end = std::chrono::high_resolution_clock::now();
                double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                time_taken *= 1e-9;
                std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl;                
                break;
            }
            case 3: {
                double avarage_time = 0;
                for(int i = 0; i < 10; i++)
                {
                    int key = Table.randomKey();
                    int value = Table.randomValue();
                    auto start = std::chrono::high_resolution_clock::now();
                    
                    Table.insert(key, value);
                    
                    auto end = std::chrono::high_resolution_clock::now();
                    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                    time_taken *= 1e-9;
                    avarage_time += time_taken;
                }
                std::cout << "Operacja zajela: " << avarage_time / 10 << " sekundy." << std::endl;
                break;
            }
            case 4: {
                int key; 
                std::cin >> key;
                auto start = std::chrono::high_resolution_clock::now();

                Table.remove(key);

                auto end = std::chrono::high_resolution_clock::now();
                double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                time_taken *= 1e-9;
                std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl;
                break;
            }
            case 5: {
                double avarage_time = 0;
                for(int i = 0; i < 10; i++)
                {
                    int key = Table.findKey();
                    if (key == -1) {
                        std::cout << "Table is empty" << std::endl;
                        break;
                    }   
                    auto start = std::chrono::high_resolution_clock::now();
                    
                    Table.remove(key);
                    
                    auto end = std::chrono::high_resolution_clock::now();
                    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                    time_taken *= 1e-9;
                    avarage_time += time_taken;
                }
                std::cout << "Operacja zajela: " << avarage_time / 10 << " sekundy." << std::endl;
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

void HashTableCuckoo_menu() {
    HashTableCuckoo Table;
    bool exit = false;
    do {
        std::cout << std::endl << "-------HASHTABLE CUCKOO HASHING-------" << std::endl;
        std::cout << "-------------CHOOSE OPTION------------" << std::endl;
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
                auto start = std::chrono::high_resolution_clock::now();

                Table.randomHashTable(number);
                
                auto end = std::chrono::high_resolution_clock::now();
                double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                time_taken *= 1e-9;
                std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl;                
                break;
            }
            case 2: {
                std::cout << "Enter key and value: ";
                int key, value; 
                std::cin >> key >> value;
                auto start = std::chrono::high_resolution_clock::now();

                Table.insert(key, value);

                auto end = std::chrono::high_resolution_clock::now();
                double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                time_taken *= 1e-9;
                std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl;
                break;
            }
            case 3: {
                double avarage_time = 0;
                for(int i = 0; i < 10; i++)
                {
                    int key = Table.randomKey();
                    int value = Table.randomValue();
                    auto start = std::chrono::high_resolution_clock::now();
                    
                    Table.insert(key, value);
                    
                    auto end = std::chrono::high_resolution_clock::now();
                    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                    time_taken *= 1e-9;
                    avarage_time += time_taken;
                }
                std::cout << "Operacja zajela: " << avarage_time / 10 << " sekundy." << std::endl;
                break;
            }
            case 4: {
                int key; 
                std::cin >> key;
                auto start = std::chrono::high_resolution_clock::now();

                Table.remove(key);

                auto end = std::chrono::high_resolution_clock::now();
                double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                time_taken *= 1e-9;
                std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl;
                break;
            }
            case 5: {
                double avarage_time = 0;
                for(int i = 0; i < 10; i++)
                {
                    int key = Table.findKey();
                    if (key == -1) {
                        std::cout << "Table is empty" << std::endl;
                        break;
                    }   
                    auto start = std::chrono::high_resolution_clock::now();
                    
                    Table.remove(key);
                    
                    auto end = std::chrono::high_resolution_clock::now();
                    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                    time_taken *= 1e-9;
                    avarage_time += time_taken;
                }
                std::cout << "Operacja zajela: " << avarage_time / 10 << " sekundy." << std::endl;
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

void HashTableOpen_menu() {  
    HashTableOpen Table;
    bool exit = false;
    do {
        std::cout << std::endl << "-------HASH TABLE OPEN ADDRESSING-------" << std::endl;
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
        switch (choice) {
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
            auto start = std::chrono::high_resolution_clock::now();

            Table.insert(key, value);

            auto end = std::chrono::high_resolution_clock::now();
            double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            time_taken *= 1e-9;
            std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl;                
            break;
        }
        case 3: {
            double avarage_time = 0;
            for(int i = 0; i < 10; i++)
            {
                int key = Table.randomKey();
                int value = Table.randomValue();
                auto start = std::chrono::high_resolution_clock::now();
                
                Table.insert(key, value);
                
                auto end = std::chrono::high_resolution_clock::now();
                double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                time_taken *= 1e-9;
                avarage_time += time_taken;
            }
            std::cout << "Operacja zajela: " << avarage_time / 10 << " sekundy." << std::endl;
            break;
        }
        case 4: {
            int key; 
            std::cin >> key;
            auto start = std::chrono::high_resolution_clock::now();

            Table.remove(key);

            auto end = std::chrono::high_resolution_clock::now();
            double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            time_taken *= 1e-9;
            std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl;
            break;
        }
        case 5: {
            double avarage_time = 0;
            for(int i = 0; i < 10; i++)
            {
                int key = Table.findKey();
                if (key == -1) {
                    std::cout << "Table is empty" << std::endl;
                    break;
                }   
                auto start = std::chrono::high_resolution_clock::now();
                
                Table.remove(key);
                
                auto end = std::chrono::high_resolution_clock::now();
                double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                time_taken *= 1e-9;
                avarage_time += time_taken;
            }
            std::cout << "Operacja zajela: " << avarage_time / 10 << " sekundy." << std::endl;
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
    // HashTableCuckoo_menu();
    // HashTableBuckets_menu();
    HashTableOpen_menu();
    
    return 0;
}