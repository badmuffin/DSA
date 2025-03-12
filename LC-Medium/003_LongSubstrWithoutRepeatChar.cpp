/*
3. Longest Substring Without Repeating Characters
-------------------------------------------------
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/

#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
  int left = 0, right = 0;
  unordered_map<char, int> mp;
  int maxLen = 0;

  while (right < s.size()) {
    char ch = s[right];
    if (mp.count(ch) == 0 || mp[ch] < left) {
      mp[ch] = right;
      maxLen = max(maxLen, right - left + 1);
    } else {
      left = mp[ch] + 1;
      mp[ch] = right;
    }
    right++;
  }
  return maxLen;
}


// second method - by using set, slightly less efficient than above one
int lengthOfLongestSubstringTwo(string s) {
  int left = 0, maxLen = 0;
  unordered_set<char> charSet;

  for(int right = 0; right < s.size(); right++) {
    while(charSet.find(s[right]) != charSet.end()) {
      charSet.erase(s[left]);
      left++;
    }
    charSet.insert(s[right]);
    maxLen = max(maxLen, right - left + 1);
  }

  return maxLen;
}

// NOTE :- Both of them take O(n) of TC and O(m) of sc where
// n is the no of char and m is the unique char
