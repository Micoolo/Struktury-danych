#pragma once
#include <string>
#include <ctime>
#include <random>
#include <chrono>
class listNodeT {
private:
	int m_value;

	listNodeT* m_nextNode;

public:
	listNodeT(int value);
	listNodeT(const listNodeT& other) = delete;
	listNodeT operator = (const listNodeT& other) = delete;

	~listNodeT();
	
	int value() const;
	listNodeT* nextNode() const;		

	void setNextNode(listNodeT* nextNode);
};

listNodeT::listNodeT(int value)
	:m_value{ value }, m_nextNode{nullptr} 
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

listNodeT *listNodeT::nextNode() const {
	return m_nextNode;
}

void listNodeT::setNextNode(listNodeT* nextNode) {
	m_nextNode = nextNode;
}



class linkedListT {
private:
	listNodeT* m_head;
	listNodeT* m_tail;
	unsigned int m_size;

public:
	linkedListT();
	linkedListT(const linkedListT& other) = delete;
	linkedListT operator = (const linkedListT& other) = delete;

	~linkedListT();


	void removeRand();
	void removeLast();
	void removeFirst();

	unsigned int size() const;
	void search() const;
	void showList();
	
	void addAtBeginning (int value);
	void addRand(int value);
	void add(int newElement);
	void randomList(int liczba);
	void clear();
};