/*
LC 496 - Next Greater Element 1
-------------------------------
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
  unordered_map<int, int> firstArrMap;

  for(int i = 0; i < nums1.size(); i++)
    firstArrMap[nums1[i]] = i;

  vector<int> result(nums1.size(), -1);

  for(int i = 0; i < nums2.size(); i++) {
    if(firstArrMap.find(nums2[i]) == firstArrMap.end())
      continue;
    
    for(int j = i+1; j < nums2.size(); j++) {
      if(nums2[i] < nums2[j]) {
        int idx = firstArrMap[nums2[i]];
        result[idx] = nums2[j];
        break;
      }
    }
  }

  return result;
}

// using monotonic stack