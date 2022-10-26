#include "PriorityQueue.h"
#include "PriorityNode.h"
#include <iostream>

using namespace std;

template <class T>
class ArrayPriorityQueue : public PriorityQueue<T> {
    
    public:
        ArrayPriorityQueue();

        ArrayPriorityQueue(const ArrayPriorityQueue<T> & arr);
        ArrayPriorityQueue & operator = (const ArrayPriorityQueue<T> & rhs);


        ~ArrayPriorityQueue();

        void enQueue(T, int);
        T deQueue();
        void print();
        bool isEmpty() const;
        int getSize() const;

    private:
        PriorityNode<T> * m_values;
        int m_size = 0;
        int m_maxSize;
};

template <class T>
ArrayPriorityQueue<T>::ArrayPriorityQueue() : m_maxSize(100){
    //TODO: Constructor
    m_values = new PriorityNode<T>[m_maxSize];
}

template <class T>
ArrayPriorityQueue<T>::~ArrayPriorityQueue(){
    //TODO: Delete
    delete[] m_values;
}

template <class T>
ArrayPriorityQueue<T>::ArrayPriorityQueue(const ArrayPriorityQueue<T> & arr){
    // Deep copy max size and regular size
    m_maxSize = arr.m_maxSize;
    m_size = arr.m_size;

    // Loop through and deep copy m_values
    m_values = new PriorityNode<T>[m_maxSize];

    for(int i = 0; i < m_size; i++){
        m_values[i] = arr.m_values[i];
    }

}



template <class T>
void ArrayPriorityQueue<T>::enQueue(T item, int priority){

    if (m_size == m_maxSize) return;

    PriorityNode<T> node(item, priority);

    m_values[m_size] = node;
    m_size++;
}

template <class T>
T ArrayPriorityQueue<T>::deQueue(){
    // Max priority should be as low as possible
    int maxPriority = -2147483648;

    // Keep track of which node is the highest priority
    int nodeIndex = -1;

    // We can't dequeue from an empty queue
    if (m_size == 0) throw "Empty queue";

    // Loop through every element
    for(int i = 0; i < m_size; i++){

        PriorityNode<T> node = m_values[i];

        // If this node has the highest priority we've seen so far, set it as our current highest ("king?")
        if (node.priority > maxPriority){
            nodeIndex = i;
            maxPriority = node.priority;
        }
    }

    // Get our highest node from the stored index
    PriorityNode<T> highestNode = m_values[nodeIndex];

    // Loop through every node from the one we're removing, and shift it to the left
    for(int j = nodeIndex; j < m_size - 1; j++){
        m_values[j] = m_values[j + 1];
    }
    // Decrease size
    m_size--;

    // Return the value of the node. Memory will be automatically deallocated
    return highestNode.value;
}

template <class T>
bool ArrayPriorityQueue<T>::isEmpty() const{
    // Returns if the size is 0
    return (m_size == 0);
}

template <class T>
void ArrayPriorityQueue<T>::print() {

    // Creates a copy of the queue we can mess around with
    ArrayPriorityQueue<T> copyQueue = *this;

    // Loop through all values of this copy queue (the m_size is equal)
    for(int i = 0; i < m_size; i++){
        // The deQueue function automatically returns the highest priority item
        // We can just loop through every single item and it'll return them to us in descending order
        T item = copyQueue.deQueue();
        cout << to_string(item) << ", ";
    }
    cout << endl;
}

template <class T>
int ArrayPriorityQueue<T>::getSize() const {
    // Returns the size
    return m_size;
}