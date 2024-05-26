#include <iostream>
#include "LinkedList.hpp"

listNode::listNode(int value, unsigned int key) : m_value{ value }, m_key { key }, m_nextNode{ nullptr } 
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

