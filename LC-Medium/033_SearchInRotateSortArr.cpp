/*
33. Search in Rotated Sorted Array
----------------------------------
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
----------------
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  int search(vector<int> &nums, int target)
  {
    int left = 0, right = nums.size() - 1;
    int mid = 0;

    // left <= right, because we want to search the last element (left == right)
    while (left <= right)
    {
      mid = left + (right - left) / 2;

      if (nums[mid] == target)
        return mid;

      // left portion
      if (nums[left] <= nums[mid])
      {
        if ((target > nums[mid]) or (target < nums[left]))
          left = mid + 1;
        else
          right = mid - 1;
      }
      // right portion
      else
      {
        if ((target < nums[mid]) or (target > nums[right]))
          right = mid - 1;
        else
          left = mid + 1;
      }
    }
    return -1;
  }
};