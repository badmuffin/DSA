/*
875. Koko Eating Bananas - Medium
---------------------------------

Koko loves to eat bananas. There are n piles of bananas, the 
ith pile has piles[i] bananas. The guards have gone and will 
come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each 
hour, she chooses some pile of bananas and eats k bananas 
from that pile. If the pile has less than k bananas, she 
eats all of them instead and will not eat any more bananas 
during this hour.

Koko likes to eat slowly but still wants to finish eating 
all the bananas before the guards return.

Return the minimum integer k such that she can eat all the 
bananas within h hours.
--------------------------------------

Example 1: 
  Input: piles = [3,6,7,11], h = 8
  Output: 4
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

bool possibleAns(vector<int> &piles, int hour, int h) {
  long long totalHours = 0;
  for(int i = 0; i < piles.size(); i++) {
    totalHours += ceil((double)piles[i]/(double)hour);
  }
  return totalHours <= h;
}

int minEatingSpeed(vector<int> &piles, int h) {
  int n = piles.size() - 1, ans = __INT_MAX__;
  int low = 0, high = *max_element(piles.begin(), piles.end());

  while(low <= high) {
    int mid = low + (high - low) / 2;
    if(possibleAns(piles, mid, h)) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}