#include "PriorityQueue.h"
#include "PriorityNode.h"
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class HeapPriorityQueue : public PriorityQueue<T> {
    
    public:
        HeapPriorityQueue();

        HeapPriorityQueue(const HeapPriorityQueue<T> & arr);
        HeapPriorityQueue & operator = (const HeapPriorityQueue<T> & rhs);


        ~HeapPriorityQueue();

        void enQueue(T, int = 0);
        T deQueue();
        void print();
        bool isEmpty() const;
        int getSize() const;

    private:
        vector<PriorityNode<T>> m_values;

        int getParent(int);
        int getLeft(int);
        int getRight(int);

        void heapifyDown(int);
        void heapifyUp(int);
};

template <class T>
int HeapPriorityQueue<T>::getParent(int i){
    return (i - 1)/2;
}

template <class T>
int HeapPriorityQueue<T>::getLeft(int i){
    return (2*i + 1);
}

template <class T>
int HeapPriorityQueue<T>::getRight(int i){
    return (2*i + 2);
}

template <class T>
void HeapPriorityQueue<T>::heapifyUp(int i){

    int parentIndex = getParent(i);

    if (i && m_values[parentIndex] < m_values[i]){
        swap(m_values[i], m_values[parentIndex]);
        heapifyUp(parentIndex);
    }
}

template <class T>
void HeapPriorityQueue<T>::heapifyDown(int i){

    int leftIndex = getLeft(i);
    int rightIndex = getRight(i);

    int largestIndex = i;

    PriorityNode<T> & currNode = m_values[i];
    PriorityNode<T> & leftNode = m_values[leftIndex];
    PriorityNode<T> & rightNode = m_values[rightIndex];

    if (leftIndex < m_values.size()){

        // If within the same priority
        if (leftNode > currNode){
            largestIndex = leftIndex;
        }
    }

    if (rightIndex < m_values.size()){
        // If within the same priority
        if (rightNode > currNode){
            largestIndex = rightIndex;
        }
    }


    if (largestIndex != i){
        swap(m_values[i], m_values[largestIndex]);
        heapifyDown(largestIndex);
    }


}




template <class T>
HeapPriorityQueue<T>::HeapPriorityQueue(){
    //TODO: Constructor
}

template <class T>
HeapPriorityQueue<T>::~HeapPriorityQueue(){
    //TODO: Delete
}

template <class T>
HeapPriorityQueue<T>::HeapPriorityQueue(const HeapPriorityQueue<T> & arr){

    // Loop through and deep copy m_values
    vector<PriorityNode<T>> m_values;

    for(int i = 0; i < arr.m_values.size(); i++){
        PriorityNode<T> node = arr.m_values[i];
        enQueue(node.value, node.priority);
    }

}



template <class T>
void HeapPriorityQueue<T>::enQueue(T item, int priority){

    PriorityNode<T> node(item, priority);

    m_values.push_back(node);

    heapifyUp(m_values.size() - 1);
}

template <class T>
T HeapPriorityQueue<T>::deQueue(){

    // We can't dequeue from an empty queue
    if (m_values.size() == 0) throw "Empty queue";


    PriorityNode<T> highestValue = m_values[0];

    m_values[0] = m_values.back();
    m_values.pop_back();

    heapifyDown(0);

    return highestValue.value;
}

template <class T>
bool HeapPriorityQueue<T>::isEmpty() const{
    // Returns if the size is 0
    return (m_values.size() == 0);
}

template <class T>
void HeapPriorityQueue<T>::print() {

    // Creates a copy of the queue we can mess around with
    HeapPriorityQueue<T> copyQueue = *this;

    // Loop through all values of this copy queue (the m_size is equal)
    for(int i = 0; i < m_values.size(); i++){
        // The deQueue function automatically returns the highest priority item
        // We can just loop through every single item and it'll return them to us in descending order
        T item = copyQueue.deQueue();
        cout << to_string(item) << ", ";
    }
    cout << endl;
}

template <class T>
int HeapPriorityQueue<T>::getSize() const {
    // Returns the size
    return m_values.size();
}