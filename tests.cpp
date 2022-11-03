#include "ArrayPriorityQueue.h"
#include "HeapPriorityQueue.h"
#include <gtest/gtest.h>

using namespace std;

TEST(HeapPriorityQueue, EnQueue){

    HeapPriorityQueue<int> heapQueue;

    heapQueue.enQueue(1, 1);
    heapQueue.enQueue(2, 2);
    heapQueue.enQueue(3, 3);

    heapQueue.print();

    ASSERT_TRUE(true);
}













int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}