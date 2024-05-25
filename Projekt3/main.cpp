#include <iostream>
#include "HashTable.hpp"

int main () {
    HashTable Table(7);
    Table.print();
    std::cout << std::endl << std::endl;
    Table.set(3, 69);
    Table.set(2, 11);
    Table.set(4, 22);
    Table.set(3, 33);
    Table.set(5, 44);
    Table.print();
     
    return 0;
}