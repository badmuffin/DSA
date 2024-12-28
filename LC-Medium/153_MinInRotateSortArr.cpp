/*
153. Find Minimum in Rotated Sorted Array
-----------------------------------------
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
---------------
Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times.
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  int findMin(vector<int> &nums)
  {
    int left = 0;
    int right = nums.size() - 1;
    int mid = left + (right - left) / 2;

    while (left < right)
    {
      if (nums[mid] < nums[right])
        right = mid;
      else
        left = mid + 1;
      mid = left + (right - left) / 2;
    }
    return nums[left];
  }
};