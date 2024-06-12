#pragma once
#include <iostream>

struct openNode {
	unsigned int m_key{};
	int m_value{};
	openNode(unsigned int key, int value) : m_key(key), m_value(value){}
};

class HashTableOpen {
private:
	int capacity;
	int size;
	openNode** tab;
	openNode* removedEntry;
	float loadFactor = 0.0;
	int hashFunc(unsigned int key);
	void checkIfRehashNeeded();
	void clear();
	void rehash();
public:
	HashTableOpen();
	~HashTableOpen();
	void print();
	void insert(unsigned int key, int value);
	void remove(unsigned int key);
	int randomKey();
	int randomValue();
	void randomHashTable(int number);
	void sizeAndLoad();
	int findKey();
	bool checkIfKeyExists(unsigned int key);
};