#ifndef PARALLEL_MERGESORT_H  
#define PARALLEL_MERGESORT_H

#include<iostream>
#include<mutex>
#include<thread>
#include<vector>


class ParallelMergeSort{
  private:
  std::vector<int> *nums;

  public:
  ParallelMergeSort(std::vector<int> *nums);
  ~ParallelMergeSort();
  void sort();
  void recursiveSort(int left, int right);
};







#endif