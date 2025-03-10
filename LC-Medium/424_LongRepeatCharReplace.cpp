/*
424. Longest Repeating Character Replacement
--------------------------------------------
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa. 
*/

#include <iostream>
using namespace std;

int characterReplacement(string s, int k) {
  int left = 0, right = 0;
  int maxLen = 0, maxFreq = 0;
  int hash[26] = {0};

  while(right < s.size()) {
    hash[s[right] - 'A']++; // store the count of current char
    maxFreq = max(maxFreq, hash[s[right] - 'A']); // calc the max Freq

    // right - left + 1 is the size of the current window
    // len - maxFreq = total replacment is needed to make substr repeated
    if((right - left + 1) - maxFreq > k) {
      hash[s[left = 'A']]--;
      left++;
    }

    // if the condition is valid then 
    if((right - left + 1) - maxLen <= k)
      maxLen = max(maxLen, right - left + 1);
    right++;
  }
}