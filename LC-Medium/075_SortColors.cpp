/*
75. Sort Colors - Medium
------------------------
Given an array nums with n objects colored red, white, or blue, 
sort them in-place so that objects of the same color are 
adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, 
white, and blue, respectively.

You must solve this problem without using the library's sort 
function.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;

        while(mid <= high) {
            if(nums[mid] == 0)
                swap(nums[low++], nums[mid++]);
            else if(nums[mid] == 1)
                mid++;
            else
                swap(nums[mid], nums[high--]);
        }
    }
};

/*
Note - in last case, we don't increment the mid pointer, because the swapped 
element need to be evaluated.
*/