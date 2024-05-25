#include <iostream>
#include "LinkedList.hpp"

listNode::listNode(int value, int key) : m_value{ value }, m_key {key}, m_nextNode{nullptr} 
{

}

listNode::~listNode(){
	if (m_nextNode != nullptr) {
		delete m_nextNode;
		m_nextNode = nullptr;
	}
}

int listNode::value() const {
	return m_value;
}

listNode *listNode::nextNode() const {
	return m_nextNode;
}

void listNode::setNextNode(listNode* nextNode) {
	m_nextNode = nextNode;
}




// linkedList::linkedList()
// 	:head{ new listNode(0, 0) }, ListSize{ 0 } 
// {
//     current = head;
// }

// linkedList::~linkedList() {
// 	if (head != nullptr) {
// 		delete head;
// 		head = nullptr;
// 	}
// }

// void linkedList::removeRand() {
//     srand(time(NULL));
//     int randomNumber = rand() % ListSize;  //losuje liczbe z przedzialu od 0 do size - 1 
	
// 	int i = 0;
// 	listNode* node = head->nextNode();
// 	listNode* prev = head;


// 	if (randomNumber == (ListSize - 1))
// 	{
// 		// Przesun się do przedostatniego wezla
// 		while (node->nextNode() != nullptr) {
// 			prev = node;
// 			node = node->nextNode();
// 		}

// 		// Ustaw wskaznik next poprzedniego wezla na nullptr, aby odciac ostatni wezel
// 		prev->setNextNode(nullptr);

// 		// Usun ostatni wezel
// 		delete node;

// 		// Zmniejsz rozmiar listy
// 		ListSize--;
// 	} else
// 	{
// 		while (node != nullptr && i < randomNumber) {
// 		i++;
// 		prev = node;
// 		node = node->nextNode();
// 		}
// 		if (node != nullptr) 
// 		{
// 			prev->setNextNode(node->nextNode());
// 			node->setNextNode(nullptr);
// 			delete node;
// 		} 
// 	}

// 	ListSize--;
// }

// void linkedList::add(int newElement, int key) {

// 	listNode* newNode = new listNode(newElement, key);

// 	// Jesli lista jest pusta, dodaj nowy element jako pierwszy
// 	if (head->nextNode() == nullptr) {
// 		head->setNextNode(newNode);
// 	} else {
// 		// Znajdz ostatni element listy
// 		listNode* lastNode = head->nextNode();
// 		while (lastNode->nextNode() != nullptr) {
// 			lastNode = lastNode->nextNode();
// 		}
// 		// Ustaw wskaznik next ostatniego elementu na nowy węzeł
// 		lastNode->setNextNode(newNode);
// 	}

// 	ListSize++;
// }

// void linkedList::showList() {
// 	listNode* node = head->nextNode();

// 	while (node != nullptr) {
// 		std::cout << node->value() << std::endl;
// 		node = node->nextNode();
// 	}
// }
