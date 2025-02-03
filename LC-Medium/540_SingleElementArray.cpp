/*
540. Single Element in a Sorted Array
-------------------------------------
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
-------------------------------------
Explanation:
  before the single element all the pairs are in the form of (even, odd) pair
  after the single element all the pairs are in the form of (odd, even) pair
  so we can use binary search to find the single element
*/

#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
  int len = nums.size();

  // edge cases at the edge of the array
  if (len == 1 or nums[0] != nums[1])
    return nums[0];
  if (nums[len - 1] != nums[len - 2])
    return nums[len - 1];

  int low = 0, high = len - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (nums[mid] != nums[mid - 1] and nums[mid] != nums[mid + 1])
      return nums[mid];

    // left side (even, odd) pair -> move right
    else if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) or (mid % 2 == 1 && nums[mid - 1] == nums[mid]))
      low = mid + 1;

    // right side (odd, even) pair -> move left
    else
      high = mid - 1;
  }
  return -1;
}
