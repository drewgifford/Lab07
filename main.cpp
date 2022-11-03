#include "ArrayPriorityQueue.h"
#include "HeapPriorityQueue.h"
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;
typedef chrono::high_resolution_clock Clock;

vector<int> createArray(int size){
    vector<int> array;
    int maxN = size * 2;
    int minN = 0;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(minN, maxN);

    cout << "Creating array of size " << size << endl;

    for (int i = 0; i < size; i++){

        int generated = distr(gen);
        array.push_back(generated);
    }

    return array;
}

int millisBetween(chrono::_V2::system_clock::time_point t1, chrono::_V2::system_clock::time_point t2){
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

vector<vector<int>> generateArrays(){
    cout << "Generating Arrays... ";

    auto t1 = Clock::now();

    vector<vector<int>> arrays;

    arrays.push_back(createArray(500));
    arrays.push_back(createArray(1000));
    arrays.push_back(createArray(2000));
    arrays.push_back(createArray(5000));

    auto t2 = Clock::now();
    cout << "Done! (" << millisBetween(t1, t2) << "ms)" << endl;

    return arrays;
}


int main(){

    vector<vector<int>> arrays = generateArrays();

    vector<ArrayPriorityQueue<int>> arrayQueues;
    vector<HeapPriorityQueue<int>> heapQueues;

    cout << "Loading Queues..." << endl;


    cout << "Queues loaded." << endl;

    cout << "Running analysis..." << endl;

    for(int s = -1; s < 4; s++){
        string sortString;

        if (s == -1){
            sortString = "";
        }
        if (s == 0){
            sortString = "Array: Queue";
        }
        else if (s == 1){
            sortString = "Heap: Queue";
        }
        else if (s == 2){
            sortString = "Array: Dequeue";
        }
        else if (s == 3){
            sortString = "Heap: Dequeue";
        }

        cout << setw(20) << left << sortString;


        for (int i = 0; i < arrays.size(); i++){

            vector<int> currentArray = arrays.at(i);

            if (s == -1){
                cout << setw(10) << left << currentArray.size();
                continue;
            }

            auto t1 = Clock::now();

            if (s == 0){
                ArrayPriorityQueue<int> aq;
                for (int j = 0; j < currentArray.size(); j++){
                    aq.enQueue(currentArray[j], currentArray[j]);
                }
                arrayQueues.push_back(aq);
            }
            else if (s == 1){
                HeapPriorityQueue<int> hq;
                for (int j = 0; j < currentArray.size(); j++){
                    hq.enQueue(currentArray[j], currentArray[j]);
                }
                heapQueues.push_back(hq);
            }

            else if (s == 2){
                ArrayPriorityQueue<int> & aq = arrayQueues.at(i);

                for (int j = 0; j < currentArray.size(); j++){
                    aq.deQueue();
                }
            }
            else if (s == 3){
                HeapPriorityQueue<int> & hq = heapQueues.at(i);
                for (int j = 0; j < currentArray.size(); j++){
                    hq.deQueue();
                }
            }
            

            auto t2 = Clock::now();

            string msString = "";

            if (chrono::duration_cast<chrono::minutes>(t2 - t1).count() > 5){
                cout << setw(10) << "> 5 minutes";
                continue;
            }

            if (chrono::duration_cast<chrono::microseconds>(t2 - t1).count() > 1000){
                msString = to_string(chrono::duration_cast<chrono::milliseconds>(t2 - t1).count()) + " ms";
            }
            else {
                msString = to_string(chrono::duration_cast<chrono::microseconds>(t2 - t1).count()) + " μs";
            }

            cout << setw(10) << left << msString;

        }
        cout << endl;
    }






    return 0;
};