#pragma once
#include <string>
#include <ctime>
#include <random>
#include <chrono>
class listNode {
private:
	int m_value;

	listNode* m_nextNode;

public:
	listNode(int value);
	listNode(const listNode& other) = delete;
	listNode operator = (const listNode& other) = delete;

	~listNode();
	
	int value() const;
	listNode* nextNode() const;		

	void setNextNode(listNode* nextNode);
};

listNode::listNode(int value)
	:m_value{ value }, m_nextNode{nullptr} 
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



class linkedList {
private:
	listNode* m_head;
	listNode* m_current;
	unsigned int m_size;

public:
	linkedList();
	linkedList(const linkedList& other) = delete;
	linkedList operator = (const linkedList& other) = delete;

	~linkedList();


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