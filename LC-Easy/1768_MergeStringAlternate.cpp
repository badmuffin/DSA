/*
1768. Merge Strings Alternately - Easy
--------------------------------------
Example 1 :
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
  word1:  a   b   c
  word2:    p   q   r
  merged: a p b q c r
*/

#include <iostream>
#include <string>
using namespace std;

string mergeAlternately(string word1, string word2)
{
  int i = 0;
  int j = 0;
  string res = "";
  while (i < word1.length() && j < word2.length()) {
    res.push_back(word1[i++]);
    res.push_back(word2[j++]);
  }

  while (i < word1.length()) {
    res.push_back(word1[i++]);
  }
  while (j < word2.length()) {
    res.push_back(word2[j++]);
  }
  return res;
}