/*
18. Four Sum
------------
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
  vector<vector<int>> result;

  if (nums.size() <= 3) return result;

  sort(nums.begin(), nums.end());

  for(int i = 0; i < nums.size(); i++) {
    // to handle duplicate value
    if(i > 0 and nums[i-1] == nums[i]) continue;

    for(int j = i+1; j < nums.size(); j++) {
      if(j > i+1 and nums[j-1] == nums[j]) continue;

      int left = j+1;
      int right = nums.size() - 1;

      // normal two sum pattern using two pointers
      while(left < right) {
        long long sum = (long long) nums[i] + nums[j] + nums[left] + nums[right];

        if(sum == target) {
          result.push_back({nums[i], nums[j], nums[left], nums[right]});
          left++;
          right--;

          while(left < right and nums[left-1] == nums[left]) left++;
          while(left < right and nums[right] == nums[right-1]) right--;
        }

        else if(sum < target) left++;
        else right--;
      }
    }
  }

  return result;
}