template <class T>
class PriorityNode {

    public:
        PriorityNode();
        PriorityNode(T, int);
        int priority;
        T value;

};
template <class T>
PriorityNode<T>::PriorityNode(){}

template <class T>
PriorityNode<T>::PriorityNode(T item, int p) : priority(p), value(item) {
}