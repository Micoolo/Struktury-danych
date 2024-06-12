#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <random> 
#include <chrono>
#include "HashTable_open.hpp"

HashTableOpen::HashTableOpen() : size(0), capacity(75) 
{
	tab = new openNode*[capacity];
	for (int i = 0; i < capacity; i++) {
		tab[i] = nullptr;
	}

	removedEntry = new openNode(-1, -1);
}

HashTableOpen::~HashTableOpen() 
{
	clear();
	delete removedEntry;
}

int HashTableOpen::hashFunc(unsigned int key) 
{
	return key % capacity;
}

void HashTableOpen::rehash() 
{
	int oldCapacity = capacity;
	capacity *= 2;
	openNode** oldTab = tab;
	tab = new openNode * [capacity];

	for (int i = 0; i < capacity; i++) {
		tab[i] = nullptr;
	}

	size = 0;

	for (int i = 0; i < oldCapacity; i++) {
		if (oldTab[i] != nullptr && oldTab[i] != removedEntry) {
			insert(oldTab[i]->m_key, oldTab[i]->m_value);
		}
	}
	delete[] oldTab;
}

void HashTableOpen::checkIfRehashNeeded() 
{
	loadFactor = static_cast<float>(size)/capacity;
	if (loadFactor >= 0.70) {
		rehash();
	}
}

bool HashTableOpen::checkIfKeyExists(unsigned int key) 
{
	int index = hashFunc(key);

	if ((tab[index] != nullptr) && (tab[index]->m_key == key) && (tab[index] != removedEntry)) {
		return true;
	}

	int startIndex = (index + 1) % capacity;
	int currentIndex = startIndex;
	while (currentIndex != index) {
		if ((tab[currentIndex] != nullptr) && (tab[currentIndex]->m_key == key) && (tab[currentIndex] != removedEntry)) {
			return true;
		}
		currentIndex = (currentIndex + 1) % capacity;
	}

	return false;
}

void HashTableOpen::sizeAndLoad()
{
	std::cout << "Number of elements: " << size << std::endl;
	checkIfRehashNeeded();
	std::cout << "Load Factor: " << loadFactor << std::endl;
}

void HashTableOpen::insert(unsigned int key, int value) 
{
	checkIfRehashNeeded();

	int index = hashFunc(key);
	while ((tab[index] != nullptr) && (tab[index] != removedEntry) && (tab[index]->m_key != key)) {
		index = (index + 1) % capacity;
	}
	
	if ((tab[index] == nullptr) || (tab[index] == removedEntry)) {
		tab[index] = new openNode(key, value);
		size++;
	}
	else {
		tab[index]->m_value = value;
	}
}

void HashTableOpen::remove(unsigned int key) 
{
	int index = hashFunc(key);
	int index0 = index;

	while (tab[index] != nullptr) {
		if (tab[index]->m_key == key) {
			delete tab[index];
			tab[index] = removedEntry;
			size--;
			break;
		}
		index = (index + 1) % capacity;
		if (index == index0) {
			break;
		}
	}
	if (tab[index] == nullptr) {
		std::cout << "Key does not exist." << std::endl;
	}
}

int HashTableOpen::randomKey()
{
	int randomNumber;
	do {
		auto keySeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();

		std::mt19937 rp(keySeed);
		std::uniform_int_distribution<int> rozklad(0, std::numeric_limits<int>::max());
		randomNumber = rozklad(rp);
	} while (checkIfKeyExists(randomNumber));

	return randomNumber;
}

int HashTableOpen::randomValue()
{
	auto valueSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();

	int lowerBoundValue = -2147483648;
	int upperBoundValue = 2147483647;
	std::mt19937 rp(valueSeed);
	std::uniform_int_distribution<int> rozklad(lowerBoundValue, upperBoundValue);
	int randomNumber = rozklad(rp);

	return randomNumber;
}

void HashTableOpen::randomHashTable(int number)
{
	if (size != 0) {
		clear();
	}
	int valueSeed = 345;
	int keySeed = 123; // seedy, w ktorych nie powtarzaja sie liczby (123, 158, 1890);


	int lowerBoundValue = -2147483648;
	int upperBoundValue = 2147483647;

	std::mt19937 randVal(valueSeed);
	std::mt19937 randKey(keySeed);
	std::uniform_int_distribution<int> distributionValue(lowerBoundValue, upperBoundValue);
	std::uniform_int_distribution<int> distributionKey(0, std::numeric_limits<int>::max());

	for (int i = 0; i < number; i++) {
		int randomValue = distributionValue(randVal);
		int randomKey = distributionKey(randKey);
		insert(randomKey, randomValue);
	}
}

int HashTableOpen::findKey() 
{
	if (size == 0) {
		return -1;
	}

	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::mt19937 RN(seed);
	std::uniform_int_distribution<int> distribution(0, capacity - 1);
	int randomNumber = distribution(RN);

	for (int i = randomNumber; i < capacity; i++) {
		if ((tab[i] != nullptr) && (tab[i] != removedEntry)) {
			return tab[i]->m_key;
		}
	}
	for (int i = randomNumber - 1; i >= 0; i--) {
		if ((tab[i] != nullptr) && (tab[i] != removedEntry)) {
			return tab[i]->m_key;
		}
	}

	return -1;
}

void HashTableOpen::print() 
{
	for (int i = 0; i < capacity; i++) {
		if (tab[i] == nullptr) {
			std::cout << i << ": " << std::endl;
		}
		else if (tab[i] == removedEntry){
			std::cout << i << ": [Removed]" << std::endl;
		}
		else {
			std::cout << i << ":  {" << tab[i]->m_key << ", " << tab[i]->m_value << "}," << std::endl;
		}
	}
}

void HashTableOpen::clear() 
{
	for (int i = 0; i < capacity; i++) {
		if ((tab[i] != nullptr) && (tab[i] != removedEntry)) {
			delete tab[i];
		}
	}

	delete[] tab;
	capacity = 75;

	tab = new openNode * [capacity];
	for (int i = 0; i < capacity; i++) {
		tab[i] = nullptr;
	}

	size = 0;
}