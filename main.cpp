#include <iostream>
#include <chrono>
#include "sorting/parallelMergeSort.hpp"


int main(int argc, char *argv[]) {
    const int SIZE = 1000000000;
    std::vector<int> nums(SIZE);  // Allocate memory

    for(int i = 0; i < SIZE; i++) {
        nums[i] = rand() % SIZE;  // Now safe
    }

    ParallelMergeSort mergeSort(&nums);
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort.sort();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mergeSortDuration = end - start;

    std::cout << "Merge Sort: " << mergeSortDuration.count() << "s" << std::endl;
}
