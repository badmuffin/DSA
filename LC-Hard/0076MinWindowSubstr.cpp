/*
76. Minimum Window Substring
-------------------------------
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.


Input : s = "ABCAAC", t = "AAC"
Output: "CAA"
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
  int left = 0, right = 0, count = t.size();
  int startIndex = -1, minLen = INT_MAX;
  unordered_map<char, int> mp; // store chars with its index

  for (char ch : t) mp[ch]++;

  while (right < s.size()) {
    if (mp[s[right]] > 0) count--;

    mp[s[right]]--; 

    right++;

    while(count == 0) {
      if (right - left < minLen) { // compare the current size of the window
        minLen = right - left;
        startIndex = left;
      }

      mp[s[left]]++; 
      
      if (mp[s[left]] > 0) count ++;

      left++;
    }
  }

  return startIndex == -1 ? "" : s.substr(startIndex, minLen);
}

int main() {
  string s = "ADOBECODEBANC";
  string t = "ABC";

  cout << minWindow(s, t) << endl;
  return 0;
}