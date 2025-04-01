/*
35. Search Insert Position
--------------------------
Input: nums = [1,3,5,6], target = 5
Output: 2

Input: nums = [1,3,5,6], target = 7
Output: 4
*/

#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
  int left = 0;
  int right = nums.size() - 1;
  int mid = left + (right - left) / 2;

  while (left <= right)
  {
    if (nums[mid] == target)
      return mid;
    else if (nums[mid] < target)
      left = mid + 1;
    else
      right = mid - 1;

    mid = left + (right - left) / 2;
  }
  return left;
}