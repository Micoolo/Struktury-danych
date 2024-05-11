#pragma once

struct QueueElement {
    int m_value;
    int m_priority;
};

class queueHeap
{
    QueueElement *elements;
    unsigned int size;
    unsigned int capacity;

    int getLeftChildIndex(int parentIndex);
    int getRightChildIndex(int parendIndex);
    int getParentIndex(int childIndex);

    bool hasLeftChild(int index);
    bool hasRightChild(int index);
    bool hasParent(int index);

    QueueElement leftChild(int index);
    QueueElement rightChild(int index);
    QueueElement parent(int index);

    void swap(int indexOne, int indexTwo);
    void ensureExtraCapacity();//DONE

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    queueHeap(); // DONE
    ~queueHeap(); //DONE

    void insert(int value, int priority); //DONE
    void extractMax(); //DONE
    void peek();//DONE

    void show() const; //DONE

    unsigned int getSize(); //DONE
    unsigned int getCapacity(); //DONE

    void clear(); //DONE
    void randomQueue(int numberOfElements); //DONE
    void insertRandom();//DONE
    void modify_key();//DONE
};