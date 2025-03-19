/*
219. Contains Duplicate II
--------------------------
Given an integer array nums and an integer k, return true if there are 
two distinct indices i and j in the array such that nums[i] == nums[j] 
and abs(i - j) <= k.

Input: nums = [1,2,3,1,2,3], k = 2
Output: false

*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// first method :- using hashmap
bool containsNearbyDuplicate(vector<int>& nums, int k) {
  unordered_map<int, int> mp;

  for(int i = 0; i < nums.size(); i++) {
    if(mp.find(nums[i]) != mp.end() && i - nums[i] <= k)
      return true;
    mp[nums[i]] = i;
  }

  return false;
}

// second method :- using hashset
bool containsNearByDuplicateII(vector<int> &nums, int k) {
  unordered_set<int> windowSet;
  int left = 0, right = 0;
  while(right < nums.size()) {
    // invalid condition
    if (right - left > k) {
      windowSet.erase(nums[left]);
      left++;
    }

    // if element is already in the set
    if (windowSet.find(nums[right]) != windowSet.end())
      return true;
    windowSet.insert(nums[right]);

    right++;
  }
  return false;
}