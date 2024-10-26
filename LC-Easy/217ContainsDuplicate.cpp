/*
217. Contains Duplicate - Easy
------------------------------
Given an integer array nums, return true if any value appears at
least twice in the array, and return false if every element is distinct.
*/

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mySet;

        for(int i=0; i<nums.size(); i++) {
            // if element is already present in the set
            if(mySet.find(nums[i]) != mySet.end()) 
                return true;
            else
                mySet.insert(nums[i]);
        }
        return false;
    }
};