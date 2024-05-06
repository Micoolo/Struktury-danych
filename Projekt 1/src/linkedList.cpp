#include "linkedList.h"
#include <iostream> 
#include <cstring> 
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include <chrono>

linkedList::linkedList()
	:m_head{ new listNode(0) }, m_size{ 0 } 
{
    m_current = m_head;
}

linkedList::~linkedList() {
	if (m_head != nullptr) {
		delete m_head;
		m_head = nullptr;
	}
}

void linkedList::removeFirst() 
{
	auto start = std::chrono::high_resolution_clock::now();
    // Jesli lista jest pusta, nie ma nic do usunięcia
    if (m_size == 0) 
	{
        return;
    }
    // Zapamiętaj wskaźnik na pierwszy element
    listNode* firstNode = m_head->nextNode();

		// Aktualizuj wskaznik na glowę, aby wskazywal na drugi element
		m_head->setNextNode(firstNode->nextNode());

		// Ustaw wskaznik next pierwszego elementu na nullptr
		firstNode->setNextNode(nullptr);

		// Usuń pierwszy element
		delete firstNode;

    // Zmniejsz rozmiar listy
    m_size--;
    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl; 
}



void linkedList::removeLast() {
	auto start = std::chrono::high_resolution_clock::now();
    // Jesli lista jest pusta, nie ma nic do usunięcia
    if (m_size == 0) {
        return;
    }

    listNode* prev = m_head;
    listNode* node = m_head->nextNode();

    // Przesun sie do przedostatniego wezla
    while (node->nextNode() != nullptr) {
        prev = node;
        node = node->nextNode();
    }

    // Ustaw wskaznik next poprzedniego wezla na nullptr, aby odciac ostatni wezel
    prev->setNextNode(nullptr);

    // Usun ostatni wezel
    delete node;

    // Zmniejsz rozmiar listy
    m_size--;
    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl; 
}

void linkedList::removeRand() {
	auto start = std::chrono::high_resolution_clock::now();
    srand(time(NULL));
    int randomNumber = rand() % m_size;  //losuje liczbe z przedzialu od 0 do size - 1 
	
	int i = 0;
	listNode* node = m_head->nextNode();
	listNode* prev = m_head;


	if (randomNumber == (m_size - 1))
	{
		// Przesun się do przedostatniego wezla
		while (node->nextNode() != nullptr) {
			prev = node;
			node = node->nextNode();
		}

		// Ustaw wskaznik next poprzedniego wezla na nullptr, aby odciac ostatni wezel
		prev->setNextNode(nullptr);

		// Usun ostatni wezel
		delete node;

		// Zmniejsz rozmiar listy
		m_size--;
	} else
	{
		while (node != nullptr && i < randomNumber) {
		i++;
		prev = node;
		node = node->nextNode();
		}
		if (node != nullptr) 
		{
			prev->setNextNode(node->nextNode());
			node->setNextNode(nullptr);
			delete node;
		} 
	}

	m_size--;
    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl; 
}

void linkedList::addRand(int value) {
	auto start = std::chrono::high_resolution_clock::now();
    srand(time(NULL));
    int randomNumber = rand() % m_size;  //losuje liczbe z przedzialu od 0 do size - 1 

    listNode* newNode = new listNode(value);
    listNode* current = m_head;

    // Przesuń się do węzła na pozycji index-1
    for (size_t i = 0; i < randomNumber; ++i) {
        current = current->nextNode();
    }

    // Ustaw nowy wezel jako nastepny dla biezacego wezla
    newNode->setNextNode(current->nextNode());
    // Ustaw nowy wezel jako nastepny dla bieżącego wezla
    current->setNextNode(newNode);

    // Zwieksz rozmiar listy
    m_size++;
    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl; 
}

void linkedList::addAtBeginning(int value) {
	auto start = std::chrono::high_resolution_clock::now();
    // Tworzymy nowy wezel
    listNode* newNode = new listNode(value);

    // Ustawiamy wskaznik next nowego wezla na aktualny glowny wezel
    newNode->setNextNode(m_head->nextNode());

    // Ustawiamy head na nowy wezel
    m_head->setNextNode(newNode);

    // Zwiekszamy rozmiar listy
    m_size++;
    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl; 
}

void linkedList::add(int newElement) {
	auto start = std::chrono::high_resolution_clock::now();
	listNode* newNode = new listNode(newElement);

	// Jesli lista jest pusta, dodaj nowy element jako pierwszy
	if (m_head->nextNode() == nullptr) {
		m_head->setNextNode(newNode);
	} else {
		// Znajdz ostatni element listy
		listNode* lastNode = m_head->nextNode();
		while (lastNode->nextNode() != nullptr) {
			lastNode = lastNode->nextNode();
		}
		// Ustaw wskaznik next ostatniego elementu na nowy węzeł
		lastNode->setNextNode(newNode);
	}

	m_size++;

	auto end = std::chrono::high_resolution_clock::now();
	double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl; 
}


void linkedList::search() const
{   
    auto start = std::chrono::high_resolution_clock::now();
    int lowerBound = -2147483648; 
    int upperBound = 2147483647;
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();//"losujemy" ziarno
    std::mt19937 generator(seed); 
    std::uniform_int_distribution<int> rozklad(lowerBound, upperBound); 
    int losowa_liczba = rozklad(generator);
    bool znaleziony = false;
    std::cout << "wygenerowana i szukana liczba: " << losowa_liczba << std::endl;
    
    listNode* currentNode = m_head->nextNode(); // Początek listy
    
    int index = 1; // Zmienna do sledzenia indeksu aktualnie przetwarzanego elementu
    
    // Przechodzimy przez listę
    while (currentNode != nullptr)
    {
        if (currentNode->value() == losowa_liczba)
        {    
            std::cout << index << ". " << currentNode->value() << std::endl;
            znaleziony = true;
            break; // Jesli znaleziono, przerywamy pętlę
        }
        
        currentNode = currentNode->nextNode(); // Przechodzimy do następnego elementu
        index++; // Inkrementujemy indeks
    }
    
    if (!znaleziony)
    {
        std::cout << "W liscie nie ma podanego elementu." << std::endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl; 
}

unsigned int linkedList::size() const {
	return m_size;
}

void linkedList::showList() {
	listNode* node = m_head->nextNode();

	while (node != nullptr) {
		std::cout << node->value() << std::endl;
		node = node->nextNode();
	}
}

void linkedList::randomList(int liczba)
{
	clear();
	int lowerBound = -2147483648;
    int upperBound = 2147483647;
    std::mt19937 generator(123); // Inicjalizacja generatora liczb losowych z ziarnem 123
    std::uniform_int_distribution<int> rozklad(lowerBound, upperBound); 

	for (int i = 0; i < liczba; i++) 
    {
        int scaledNumber = rozklad(generator);
		listNode* newNode = new listNode(scaledNumber);
		m_current->setNextNode(newNode);
		m_current = newNode;
		m_size++;
    }
}

void linkedList::clear() {
    while (m_size > 0) {
        // Sprawdz czy lista nie jest pusta
        if (m_head->nextNode() == nullptr) {
            break; 
        }
        // Zapamiętaj wskaznik na pierwszy element
        listNode* firstNode = m_head->nextNode();

        // Aktualizuj wskaznik na glowe, aby wskazywal na drugi element
        m_head->setNextNode(firstNode->nextNode());

        // Ustaw wskaźnik next pierwszego elementu na nullptr
        firstNode->setNextNode(nullptr);

        delete firstNode;

        m_size--;
    }
    m_head->setNextNode(nullptr);
    m_current = m_head;
}




