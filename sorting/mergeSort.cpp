#include "mergeSort.hpp"
#include <iostream>

MergeSort::MergeSort(std::vector<int> *nums) {
  this->nums = nums;
}

MergeSort::~MergeSort(){}

void MergeSort::sort() {
  if(nums->size() <= 1) return;
  recursiveSort(0, nums->size() - 1);
  for(int i=0; i<nums->size(); i++) {
    std::cout << nums->at(i) << " ";
  }
}
void MergeSort::recursiveSort(int left, int right){
  if(left >= right) return;
  int mid = (left + right) / 2;
  recursiveSort(left, mid);
  recursiveSort(mid + 1, right);

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