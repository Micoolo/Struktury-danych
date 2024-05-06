#include "LinkedList_tail.h"
#include <iostream> 
#include <cstring> 
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include <chrono>

linkedListT::linkedListT()
	:m_head{ new listNodeT(0) }, m_size{ 0 } 
{
    m_tail = m_head;
}

linkedListT::~linkedListT() {
	if (m_head != nullptr) {
		delete m_head;
		m_head = nullptr;
	}
}

void linkedListT::removeFirst() 
{
	auto start = std::chrono::high_resolution_clock::now();
    // Jesli lista jest pusta, nie ma nic do usuniecia
    if (m_size == 0) 
	{
        return;
    }
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
    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl; 
}



void linkedListT::removeLast() {
	auto start = std::chrono::high_resolution_clock::now();
    // Jesli lista jest pusta, nie ma nic do usuniecia
    if (m_size == 0) {
        return;
    }

    listNodeT* prev = m_head;
    listNodeT* node = m_head->nextNode();

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



void linkedListT::removeRand() {
	auto start = std::chrono::high_resolution_clock::now();
    srand(time(NULL));
    int randomNumber = rand() % m_size;  //losuje liczbe z przedzialu od 0 do size - 1 
	
	int i = 0;
	listNodeT* node = m_head->nextNode();
	listNodeT* prev = m_head;


	if (randomNumber == (m_size - 1))
	{
		// Przesun sie do przedostatniego wezla
		while (node->nextNode() != nullptr) {
			prev = node;
			node = node->nextNode();
		}

		// Ustaw wskaznik next poprzedniego wezla na nullptr, aby odciąc ostatni wezel
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

void linkedListT::addRand(int value) {
	auto start = std::chrono::high_resolution_clock::now();
    srand(time(NULL));
    int randomNumber = rand() % m_size;  //losuje liczbe z przedzialu od 0 do size - 1 

    listNodeT* newNode = new listNodeT(value);
    listNodeT* current = m_head;

    // Przesun sie do wezla na pozycji index-1
    for (size_t i = 0; i < randomNumber; ++i) {
        current = current->nextNode();
    }

    // Ustaw nowy wezel jako nastepny dla biezacego wezla
    newNode->setNextNode(current->nextNode());
    // Ustaw nowy wezel jako nastepny dla biezacego wezla
    current->setNextNode(newNode);

    // Zwieksz rozmiar listy
    m_size++;
    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl; 
}

void linkedListT::addAtBeginning(int value) {
	auto start = std::chrono::high_resolution_clock::now();
    // Tworzymy nowy wezel
    listNodeT* newNode = new listNodeT(value);

    // Ustawiamy wskaznik next nowego wezla na aktualny glowny wezel
    newNode->setNextNode(m_head->nextNode());

    // Ustawiamy głowe na nowy wezel
    m_head->setNextNode(newNode);

    // Zwiekszamy rozmiar listy
    m_size++;
    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl; 
}

void linkedListT::add(int newElement) {
	auto start = std::chrono::high_resolution_clock::now();
	listNodeT* newNode = new listNodeT(newElement);
	m_tail->setNextNode(newNode);
	m_tail = newNode;
	m_size++;
    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    std::cout << "Operacja zajela: " << time_taken << " sekundy." << std::endl; 
}



void linkedListT::search() const
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
    
    listNodeT* currentNode = m_head->nextNode(); // Początek listy
    
    int index = 1; // Zmienna do sledzenia indeksu aktualnie przetwarzanego elementu
    
    // Przechodzimy przez liste
    while (currentNode != nullptr)
    {
        if (currentNode->value() == losowa_liczba)
        {    
            std::cout << index << ". " << currentNode->value() << std::endl;
            znaleziony = true;
            break; // Jesli znaleziono, przerywamy pętlę
        }
        
        currentNode = currentNode->nextNode(); // Przechodzimy do nastepnego elementu
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

unsigned int linkedListT::size() const {
	return m_size;
}

void linkedListT::showList() {
	listNodeT* node = m_head->nextNode();

	while (node != nullptr) {
		std::cout << node->value() << std::endl;
		node = node->nextNode();
	}
}

void linkedListT::randomList(int liczba)
{
	clear();
	int lowerBound = -2147483648;
    int upperBound = 2147483647;
    std::mt19937 generator(123); // Inicjalizacja generatora liczb losowych z ziarnem 123
    std::uniform_int_distribution<int> rozklad(lowerBound, upperBound); 

	for (int i = 0; i < liczba; i++) 
    {
        int scaledNumber = rozklad(generator);
		listNodeT* newNode = new listNodeT(scaledNumber);
		m_tail->setNextNode(newNode);
		m_tail = newNode;
		m_size++;
    }
}

void linkedListT::clear() {
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
    m_tail = m_head;
}




