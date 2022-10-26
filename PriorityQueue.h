template <class T>
class PriorityQueue {

    public:
        PriorityQueue();
        ~PriorityQueue();

        PriorityQueue(const PriorityQueue<T> & arr);
        PriorityQueue & operator = (const PriorityQueue<T> & rhs);

        virtual void enQueue(T, int);
        virtual T deQueue();
        virtual void print();
        virtual bool isEmpty() const;
        virtual int getSize() const;
};

template <class T>
PriorityQueue<T>::PriorityQueue(){}

template <class T>
PriorityQueue<T>::~PriorityQueue(){}

template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T> & arr){}

template <class T>
T PriorityQueue<T>::deQueue(){}

template <class T>
void PriorityQueue<T>::enQueue(T item, int priority){}

template <class T>
void PriorityQueue<T>::print(){}

template <class T>
bool PriorityQueue<T>::isEmpty() const { return true; }

template <class T>
int PriorityQueue<T>::getSize() const { return 0; }