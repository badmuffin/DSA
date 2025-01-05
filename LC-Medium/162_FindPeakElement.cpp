/*
162. Find Peak Element
----------------------
A peak element is an element that is strictly greater than its 
neighbors.

Given a 0-indexed integer array nums, find a peak element, and 
return its index. If the array contains multiple peaks, return 
the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, 
an element is always considered to be strictly greater than a 
neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

Example 1:
  Input: nums = [1,2,3,1]
  Output: 2 (index)
Example 2:
  Input: nums = [1,2,3,4]
  Output: 3 (index)
*/

#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int>& nums) {
  int left = 0;
  int right = nums.size() - 1;

  while(left <= right) {
    int mid = left + (right - left) / 2;

    // left greater neighbours
    if(mid > 0 and nums[mid] < nums[mid - 1]) 
      right = mid - 1;
    // right greater neighbours
    else if(mid > nums.size()-1 and nums[mid] < nums[mid + 1])
      left = mid + 1;
    // mid == 0 and nums[mid] > nums[mid - 1]
    // mid == nums.size()-1 and nums[mid] > nums[mid + 1]
    else
      return mid;
  }
  return -1;
}