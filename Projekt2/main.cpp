#include <iostream>
#include <chrono>
#include "Queue_List.hpp"


void menu_queue_list()
{
    queueList queue;
    bool exit = false;
    do 
    {
        std::cout << std::endl << "-------QUEUE ON LIST-------" << std::endl;
        std::cout << "-------CHOOSE OPTION-------" << std::endl;
        std::cout << "1) GENERATE ELEMENTS " << std::endl;
        std::cout << "2) Insert element (e, p)" << std::endl;
        std::cout << "3) Extract-MAX " << std::endl;
        std::cout << "4) Peek / find MAX" << std::endl;
        std::cout << "5) Modify element (element picked randomly, new priority also set randomly)" << std::endl;
        std::cout << "6) Return size" << std::endl;
        std::cout << "7) Show queue" << std::endl;
        std::cout << "8) Insert random number" << std::endl;
        std::cout << "9) Exit" << std::endl;
        int choice;
        std::cin >> choice;
        switch(choice)
        {
            case 1: 
            {
                std::cout << "How many numbers to generate" << std::endl;
                int number;
                std::cin >> number;
                auto start = std::chrono::high_resolution_clock::now();

                queue.randomQueue(number);

                auto end = std::chrono::high_resolution_clock::now();
                double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                time_taken *= 1e-9;
                std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl;
                break;
            }
            case 2: 
            {
                int element, priority;
                std::cin >> element >> priority;
                auto start = std::chrono::high_resolution_clock::now();

                queue.insert(element, priority);

                auto end = std::chrono::high_resolution_clock::now();
                double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                time_taken *= 1e-9;
                std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl; 
                break;
            }
            case 3:
            {   
                double avarage_time = 0;
                for(int i = 0; i < 10; i++)
                {
                    auto start = std::chrono::high_resolution_clock::now();
                    
                    queue.removeFirst();
                    
                    auto end = std::chrono::high_resolution_clock::now();
                    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                    time_taken *= 1e-9;
                    avarage_time += time_taken;
                }
                std::cout << "Operacja zajela: " << avarage_time / 10 << " sekundy." << std::endl;
                break;
            }
            case 4:
            {
                double avarage_time = 0;
                for(int i = 0; i < 10; i++)
                {
                    auto start = std::chrono::high_resolution_clock::now();

                    queue.peek();

                    auto end = std::chrono::high_resolution_clock::now();
                    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                    time_taken *= 1e-9;
                    avarage_time += time_taken;
                }
                std::cout << "Operacja zajela: " << avarage_time / 10 << " sekundy." << std::endl;
                break;
            }
            case 5:
            {
                double avarage_time = 0;
                for(int i = 0; i < 10; i++)
                {
                    auto start = std::chrono::high_resolution_clock::now();

                    queue.modify_key();

                    auto end = std::chrono::high_resolution_clock::now();
                    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                    time_taken *= 1e-9;
                    avarage_time += time_taken;
                }
                std::cout << "Operacja zajela: " << avarage_time / 10 << " sekundy." << std::endl;
                break;
            }
            case 6:
            {
                double avarage_time = 0;
                for(int i = 0; i < 10; i++)
                {
                    auto start = std::chrono::high_resolution_clock::now();

                    std::cout << "Size of queue: " << queue.size() << std::endl;

                    auto end = std::chrono::high_resolution_clock::now();
                    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                    time_taken *= 1e-9;
                    avarage_time += time_taken;
                }
                std::cout << "Operacja zajela: " << avarage_time / 10 << " sekundy." << std::endl;
                break;
            }
            case 7:
            {
                auto start = std::chrono::high_resolution_clock::now();

                queue.showList();

                auto end = std::chrono::high_resolution_clock::now();
                double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                time_taken *= 1e-9;
                std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl;
                break;
            }
            case 8:
            {
                double avarage_time = 0;
                for(int i = 0; i < 10; i++)
                {
                    auto start = std::chrono::high_resolution_clock::now();

                    queue.insert_random();

                    auto end = std::chrono::high_resolution_clock::now();
                    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                    time_taken *= 1e-9;
                    avarage_time += time_taken;
                }
                std::cout << "Operacja zajela: " << avarage_time << " sekundy." << std::endl;
                break;
            }
            case 9:
                exit = true;
                break;
        }
    } while (exit == false);
}


int main()
{
    menu_queue_list();

    return 0;
}