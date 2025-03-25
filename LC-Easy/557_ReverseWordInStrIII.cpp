/*
557. Reverse Words in s String III
-----------------------------------
Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
*/

#include <iostream>
#include <vector>
using namespace std;

string reverseWords(string s) {
  int left = 0;
  for(int right = 0; right < s.size(); right++) {
    if(s[right] == ' ' || right == s.size() - 1) {
      int tempLeft = left;
      int tempRight = s[right] == ' ' ? right - 1 : right;

      while(tempLeft < tempRight) {
        swap(s[tempLeft++], s[tempRight--]);
      }

      left = right + 1;
    }
  }
  return s;
}