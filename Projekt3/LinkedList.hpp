#pragma once
#include <iostream>

class listNode {
public:
    int m_key; 
	int m_value;
	listNode* m_nextNode;


	listNode(int value, int key);

	~listNode();
	
	int value() const;
	listNode* nextNode() const;		

	void setNextNode(listNode* nextNode);
};

// class linkedList {
// private:
// 	listNode* head;
// 	listNode* current;
// 	unsigned int ListSize;

// public:
// 	linkedList();

// 	~linkedList();


// 	void removeRand();

// 	void showList();
	
// 	void add(int newElement, int key);
// };