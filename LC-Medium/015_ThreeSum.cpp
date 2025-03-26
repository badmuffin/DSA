/*
15. Three Sum
--------------
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
*/


/*
Algorithm 
----------
1. Sort the List -> [-4, -1, -1, 0, 1, 2]
2. If curr and prev element are same then skip the current element... because 
   they will result in duplicate triplets
3. Use for loop to get the first number
4. use two pointers to get the remaining two numbers, l and r will be at the
   extreme end. (Two Pointer Problem)
5. if there sum is greater than the target, reduce the rightmost pointer and
   vice-vers.
6. If sum is equal to target include it.
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> result;

  for(int i = 0; i < nums.size(); i++) {

    // if curr and prev element are same -> to avoid duplicate triplets
    if(i > 0 and nums[i] == nums[i - 1]) 
      continue;

    int left = i + 1;
    int right = nums.size() - 1;

    while(left < right) {
      if(nums[i] + nums[left] + nums[right] > 0)
        right--;
      else if(nums[i] + nums[left] + nums[right] < 0)
        left++;
      else {
        result.push_back({nums[i], nums[left], nums[right]});
        left++;

        // skip duplicated for left pointer
        while(nums[left] == nums[left - 1] and left < right) {
          left++;
        }
      }
    }
  }

  return result;
}

int main() {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> ans = threeSum(nums);

  for(const auto &triplet: ans) {
    cout << "[ ";
    for (int num : triplet) {
        cout << num << " ";
    }
    cout << "]\n";
  }

  return 0;
}