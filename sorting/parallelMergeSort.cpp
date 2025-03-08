#include "parallelMergeSort.hpp"
#include <iostream>
#include <thread>
#include <mutex>
#include <thread>
#include <vector>


ParallelMergeSort::ParallelMergeSort(std::vector<int> *nums) {
  this->nums = nums;
}

ParallelMergeSort::~ParallelMergeSort() {}

void ParallelMergeSort::sort() {
  // if(nums->size() <= 1) return;
  // recursiveSort(0, nums->size() - 1);
  // for(int i=0; i<nums->size(); i++) {
  //   std::cout << nums->at(i) << " ";
  // }
}

void ParallelMergeSort::recursiveSort(int left,int right){
  if(left>=right) return;
  int mid = (left+right)/2;

  std::thread t1(&ParallelMergeSort::recursiveSort,this,left,mid);
  std::thread t2(&ParallelMergeSort::recursiveSort,this,mid+1,right);
  t1.join();
  t2.join();

  std::vector<int> ans;
  int i = left, j = mid + 1;
  while(i <= mid && j <= right) {
    if(nums->at(i) <= nums->at(j)) {
      ans.push_back(nums->at(i));
      i++;
    } else {
      ans.push_back(nums->at(j));
      j++;
    }
  }
  while(i <= mid) {
    ans.push_back(nums->at(i));
    i++;
  }
  while(j <= right) {
    ans.push_back(nums->at(j));
    j++;
  }
  for(int k=0; k<ans.size(); k++) {
    nums->at(left + k) = ans.at(k);
  }
  return;
}