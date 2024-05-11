#include "Queue_Heap.hpp"
#include <iostream> 
#include <cstring> 
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include <chrono>


///////////////////////////
///// SUPPORT METHODS /////
///////////////////////////


int queueHeap::getLeftChildIndex(int parentIndex)
{
    return 2 * parentIndex + 1;
}

int queueHeap::getRightChildIndex(int parentIndex)
{
    return 2 * parentIndex + 2;
}

int queueHeap::getParentIndex(int childIndex)
{
    return (childIndex - 1) / 2;
}

bool queueHeap::hasLeftChild(int index)
{
    return getLeftChildIndex(index) < size;
}

bool queueHeap::hasRightChild(int index)
{
    return getRightChildIndex(index) < size;
}

bool queueHeap::hasParent(int index)
{
    return getParentIndex(index) >= 0;
}

QueueElement queueHeap::leftChild(int index)
{
    return elements[getLeftChildIndex(index)];
}

QueueElement queueHeap::rightChild(int index)
{
    return elements[getRightChildIndex(index)];
}

QueueElement queueHeap::parent(int index)
{
    return elements[getParentIndex(index)];
}

void queueHeap::swap(int indexOne, int indexTwo)
{
    QueueElement temporary = elements[indexOne];
    elements[indexOne] = elements[indexTwo];
    elements[indexTwo] = temporary;
}

void queueHeap::ensureExtraCapacity()
{
    if (size == capacity)
    {
        capacity *=2;
        //stworzenie nowej, tymczasowej tablicy o pojemnosci 2x starej 
        QueueElement *tempArr = new QueueElement[capacity];
        //przekopiowanie elementow z tablicy elements do tymczasowej tablicy
        std::memcpy(tempArr, elements, sizeof(QueueElement) * size);
        //usuwanie zawartosci starej tablicy ("czyszczenie")
        delete[] elements;
        elements = tempArr;
    }
}

void queueHeap::heapifyUp(int index)
{
    while (hasParent(index) && parent(index).m_priority < elements[index].m_priority)
    {
        swap(getParentIndex(index), index);
        index = getParentIndex(index);
    }
}

void queueHeap::heapifyDown(int index)
{
    while(hasLeftChild(index))
    {
        int biggerChildIndex = getLeftChildIndex(index);
        if (hasRightChild(index) && rightChild(index).m_priority > leftChild(index).m_priority)
        {
            biggerChildIndex = getRightChildIndex(index);
        }
        if (elements[index].m_priority > elements[biggerChildIndex].m_priority)
        {
            break;
        } else
        {
            swap(index, biggerChildIndex);
        }
        index = biggerChildIndex;
    }
}

//////////////////////////////
///// HEAP/ARRAY METHODS /////
//////////////////////////////




queueHeap::queueHeap() : size{0}, capacity{2}, elements{nullptr}
{
    elements = new QueueElement [capacity];
}

queueHeap::~queueHeap()
{
    if (elements != nullptr)
    {
        delete[] elements;
        elements = nullptr;
    }
}


void queueHeap::insert(int value, int priority)
{
    ensureExtraCapacity();
    elements[size].m_value = value;
    elements[size].m_priority = priority;
    size++;
    heapifyUp(size - 1);
}

void queueHeap::extractMax()
{
    if (size == 0)
    {
        std::cout << "Queue is empty" << std::endl;
    }
    else
    {
        int value = elements[0].m_value;
        int priority = elements[0].m_priority;
        elements[0] = elements[size - 1];
        size--;
        heapifyDown(0);
        std::cout << "Max element extracted is: (" << value << ", " << priority << ")" << std::endl; 
    }
}

void queueHeap::peek()
{
    if (size == 0)
    {
        std::cout << "Queue is empty" << std::endl;
    }
    else
    {
        std::cout << "Max element is: (" << elements[0].m_value << ", " << elements[0].m_priority << ")" << std::endl; 
    }
}

void queueHeap::randomQueue(int numberOfElements)
{
	clear();
	int lowerBound = -2147483648;
    int upperBound = 2147483647;
    std::mt19937 generator(123); // Inicjalizacja generatora liczb losowych z ziarnem 123
    std::mt19937 rp(time(nullptr));
    std::uniform_int_distribution<int> rozklad(lowerBound, upperBound); 
    std::uniform_int_distribution<int> rozkladPrio(1, numberOfElements*5); 
	for (int i = 0; i < numberOfElements; i++) 
    {
        int randomPriority = rozkladPrio(rp);
        int scaledNumber = rozklad(generator);
        insert(scaledNumber, randomPriority);
    }
}

void queueHeap::insertRandom()
{
    int lowerBound = -2147483648;
    int upperBound = 2147483647;
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 rp(seed);
    std::uniform_int_distribution<int> rozkladPrio(1, size*5 + 1); 
    std::uniform_int_distribution<int> rozklad(lowerBound, upperBound); 
    int randomNumber = rozklad(rp);
    int randomPriority = rozkladPrio(rp);
    insert(randomNumber, randomPriority);
}

void queueHeap::modify_key()
{
    //do linii 227 jest to funkcja pomocniczna, ktora szuka wartosci elementu w strukturze,
    // poniewaz wylosowane liczby sa bardzo duze i funkcja nie znajdowalaby elementow do zmodyfikowania 
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 rp(seed);
    std::uniform_int_distribution<int> rozklad(0, size - 1); 
    std::uniform_int_distribution<int> rozkladPrio(1, size*5); 
    int randomNumber = rozklad(rp);  //losuje liczbe z przedzialu od 0 do size - 1 
    int randomPriority = rozkladPrio(rp);

    if (size == 0)
    {
        std::cout << "Queue is empty. " << std::endl;
        return;
    }
    
    //sprawdzenie jaka jest wartosc value dla wylosowanego elementu
    // std::cout << "random num: " << randomNumber << " random prio:" << randomPriority << std::endl;
    int index = 0;
    int temporaryValue = 0;
    bool found = false;
    for (int i = 0; i <= randomNumber; i++)
    {
        if (i == randomNumber)
        {
            temporaryValue = elements[i].m_value;
            // std::cout << "wylosowana wartosc value: " << temporaryValue << std::endl;
        }
    }

    //czesc glowna funkcji modify_key(e, p), (znamy juz e i wylosowalismy p)

    // Znajdz indeks elementu o wartosci 'value'
    for (int i = 0; i < size; ++i) {
        if (elements[i].m_value == temporaryValue) {
            index = i;
            found = true;
            break;
        }
    }


    if (!found) {
        std::cout << "Element with value " << temporaryValue << " not found in the queue." << std::endl;
        return;
    }

    int oldPriority = elements[index].m_priority;
    elements[index].m_priority = randomPriority;

    // Sprawdz czy nalezy przesunac element w gorę czy w dlł
    if (randomPriority > oldPriority) {
        heapifyUp(index);
    } else {
        heapifyDown(index);
    }
}

void queueHeap::show() const
{
    for (int i = 0; i < size; i++)
        std::cout << i + 1 << ". " << "(" << this->elements[i].m_value << ", " << this->elements[i].m_priority << ")" << std::endl;
}

unsigned int queueHeap::getSize()
{
    return size;
}

unsigned int queueHeap::getCapacity()
{
    return capacity;
}

void queueHeap::clear()
{
    delete[] elements;
    capacity = 2;
    size = 0;
    elements = new QueueElement[capacity]; 
}