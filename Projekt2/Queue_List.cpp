#include "Queue_List.hpp"
#include <iostream> 
#include <cstring> 
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include <chrono>


listNodeT::listNodeT(int value, int priority): m_value{ value }, m_priority{priority}, m_nextNode{nullptr} 
{

}

listNodeT::~listNodeT(){
	if (m_nextNode != nullptr) {
		delete m_nextNode;
		m_nextNode = nullptr;
	}
}

int listNodeT::value() const {
	return m_value;
}

int listNodeT::priority() const {
	return m_priority;
}

listNodeT *listNodeT::nextNode() const {
	return m_nextNode;
}

void listNodeT::setNextNode(listNodeT* nextNode) {
	m_nextNode = nextNode;
}


/////////////////////////////////////
//////////       LISTA      /////////
/////////////////////////////////////



queueList::queueList(): m_head{ new listNodeT(0, 0) }, m_size{ 0 }
{

}

queueList::~queueList() {
	if (m_head != nullptr) {
		delete m_head;
		m_head = nullptr;
	}
}

void queueList::removeFirst() 
{
    // Jesli lista jest pusta, nie ma nic do usuniecia
    if (m_size == 0) 
	{
        std::cout << "Kolejka jest pusta" << std::endl;
        return;
    }
    std::cout << "(" << m_head->nextNode()->value() << ", " << m_head->nextNode()->priority() << ")" << std::endl; 
    // Zapamietaj wskaznik na pierwszy element
    listNodeT* firstNode = m_head->nextNode();

		// Aktualizuj wskaznik na glowe, aby wskazywal na drugi element
		m_head->setNextNode(firstNode->nextNode());

		// Ustaw wskaznik next pierwszego elementu na nullptr
		firstNode->setNextNode(nullptr);

		// Usunń pierwszy element
		delete firstNode;

    // Zmniejsz rozmiar listy
    m_size--;
}

void queueList::insert(int value, int priority) {
    // Tworzymy nowy wezel
    listNodeT* newNode = new listNodeT(value, priority);
    listNodeT* currentNode = m_head->nextNode();

    //poczatek listy
    if (m_size == 0)
    {
        // Ustawiamy wskaznik next nowego wezla na aktualny glowny wezel
        newNode->setNextNode(m_head->nextNode());

        // Ustawiamy głowe na nowy wezel
        m_head->setNextNode(newNode);
    }
    else
    {
        //jesli lista nie jest pusta, ale dodawany element ma wiekszy priorytet niz pierwszy element
        if(priority > currentNode->priority())
        {
            // Ustawiamy wskaznik next nowego wezla na aktualny glowny wezel
            newNode->setNextNode(m_head->nextNode());

            // Ustawiamy głowe na nowy wezel
            m_head->setNextNode(newNode);
        } 
        else 
        {
            //iteracja po elementach i sprawdzanie czy nastepny element ma mniejszy priorytet
            listNodeT* nextNode = currentNode->nextNode();
            while (currentNode != nullptr)
            {
                if(currentNode->nextNode() == nullptr)
                {
                    currentNode->setNextNode(newNode);
                    newNode->setNextNode(nullptr);
                    break;
                }

                if (nextNode->priority() > priority)
                {    
                    currentNode = currentNode->nextNode(); // Przechodzimy do nastepnego elementu
                    nextNode = nextNode->nextNode();
                } 
                else if (nextNode->priority() <= priority)
                {
                    currentNode->setNextNode(newNode);
                    newNode->setNextNode(nextNode);
                    break;
                }
                
            }
        }
    }

    // Zwiekszamy rozmiar listy
    m_size++;
}

void queueList::peek()
{
    std::cout << "(" << m_head->nextNode()->value() << ", " << m_head->nextNode()->priority() << ")" << std::endl; 
}

void queueList::modify_key()
{
    listNodeT* currentNode = m_head->nextNode();
    bool found = false;
	listNodeT* prev = m_head;
    int randValue = 0;

    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 rp(seed);
    std::uniform_int_distribution<int> rozklad(0, m_size); 
    std::uniform_int_distribution<int> rozkladPrio(1, m_size*5); 
    int randomNumber = rozklad(rp);  //losuje liczbe z przedzialu od 0 do size - 1 
    int randomPriority = rozkladPrio(rp);

    //sprawdzenie jaka jest wartosc value dla wylosowanego elementu
    std::cout << "random num: " << randomNumber << " random prio:" << randomPriority << std::endl;
    for(int i = 0; i <= randomNumber; i++)
    {
        if (i == randomNumber)
        {
            randValue = currentNode->value();
            std::cout << "random val: " << randValue << std::endl;
        }
        currentNode = currentNode->nextNode();
    }
    currentNode = m_head->nextNode();


    while (currentNode != nullptr)
    {
        if (currentNode->value() == randValue && currentNode->nextNode()==nullptr)
        {

            prev->setNextNode(nullptr);
            delete currentNode;
            found = true;
            m_size--;
            break;
        }

        if (currentNode->value() == randValue) 
        {
            prev->setNextNode(currentNode->nextNode());
            currentNode->setNextNode(nullptr);
            delete currentNode;
            found = true;
            m_size--;
            break; // Jesli znaleziono, przerywamy pętlę
        }             
        
        prev = currentNode;
        currentNode = currentNode->nextNode(); // Przechodzimy do nastepnego elementu
    }
    
    if (!found)
    {
        std::cout << "W kolejce nie ma podanego elementu." << std::endl;
    }
    insert(randValue, randomPriority);
}

void queueList::randomQueue(int liczba)
{
	clear();
	int lowerBound = -2147483648;
    int upperBound = 2147483647;
    std::mt19937 generator(123); // Inicjalizacja generatora liczb losowych z ziarnem 123
    std::mt19937 rp(time(nullptr));
    std::uniform_int_distribution<int> rozklad(lowerBound, upperBound); 
    std::uniform_int_distribution<int> rozkladPrio(1, liczba*5); 
	for (int i = 0; i < liczba; i++) 
    {
        int randomPriority = rozkladPrio(rp);
        int scaledNumber = rozklad(generator);
        insert(scaledNumber, randomPriority);
    }
}

void queueList::insert_random()
{
    int lowerBound = -2147483648;
    int upperBound = 2147483647;
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 rp(seed);
    std::uniform_int_distribution<int> rozkladPrio(1, m_size*5); 
    std::uniform_int_distribution<int> rozklad(lowerBound, upperBound); 
    int randomNumber = rozklad(rp);  //losuje liczbe z przedzialu od 0 do size - 1 
    int randomPriority = rozkladPrio(rp);
    insert(randomNumber, randomPriority);
}

void queueList::clear() {
    // Iteruj przez liste, dopoki nie bedzie pusta
    while (m_size > 0) {
        // Sprawdź czy lista nie jest pusta
        if (m_head->nextNode() == nullptr) {
            break; // Wyjdź z petli jesli lista jest pusta
        }
        // Zapamietaj wskaznik na pierwszy element
        listNodeT* firstNode = m_head->nextNode();

        // Aktualizuj wskaznik na glowe, aby wskazywal na drugi element
        m_head->setNextNode(firstNode->nextNode());

        // Ustaw wskaznik next pierwszego elementu na nullptr
        firstNode->setNextNode(nullptr);

        // Usun pierwszy element
        delete firstNode;

        // Zmniejsz rozmiar listy
        m_size--;
    }
    m_head->setNextNode(nullptr);
}

unsigned int queueList::size() const {
	return m_size;
}

void queueList::showList() {
	listNodeT* node = m_head->nextNode();

	while (node != nullptr) {
		std::cout << "(" << node->value() << ", " << node->priority() << ")" << std::endl;
		node = node->nextNode();
	}
}


