#include "ArrayPriorityQueue.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    ArrayPriorityQueue<int> arrayQueue;

    arrayQueue.enQueue(100, 10);
    arrayQueue.enQueue(120, 15);
    arrayQueue.enQueue(140, 10);

    return 0;
}