#pragma once

template <class T>
class PriorityNode {

    public:
        PriorityNode();
        PriorityNode(T, int);
        int priority;
        T value;

        bool operator== (const PriorityNode& rhs){return priority == rhs.priority;};
        bool operator< (const PriorityNode& rhs){return priority < rhs.priority;};
        bool operator> (const PriorityNode& rhs){return  priority > rhs.priority;};
        bool operator<= (const PriorityNode& rhs){return !operator> (rhs);};
        bool operator>= (const PriorityNode& rhs){return !operator< (rhs);};

};
template <class T>
PriorityNode<T>::PriorityNode(){}

template <class T>
PriorityNode<T>::PriorityNode(T item, int p) : priority(p), value(item) {
}