#pragma once
#include <string>
#include <ctime>
#include <random>
#include <chrono>

class listNodeT {
private:
	int m_value;
    int m_priority;
	listNodeT* m_nextNode;

public:
	listNodeT(int value, int priority);
	listNodeT(const listNodeT& other) = delete;
	listNodeT operator = (const listNodeT& other) = delete;

	~listNodeT();
	
	int value() const;
    int priority() const;
	listNodeT* nextNode() const;		

	void setNextNode(listNodeT* nextNode);
};

class queueList {
private:
	listNodeT* m_head;
	listNodeT* m_tail;
	unsigned int m_size;

public:
	queueList();
	queueList(const queueList& other) = delete;
	queueList operator = (const queueList& other) = delete;

	~queueList();

	void removeFirst();

	unsigned int size() const;
	void showList();

	
	void modify_key();
	void peek();
	void insert(int value, int priority);
	void insert_random();
	void randomQueue(int liczba);
	void clear();
};