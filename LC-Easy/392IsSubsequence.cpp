/*
392. Is Subsequence - Easy
--------------------------
Given two strings s and t, return true if s is a subsequence of t, 
or false otherwise.

A subsequence of a string is a new string that is formed from the 
original string by deleting some (can be none) of the characters 
without disturbing the relative positions of the remaining characters. 
(i.e., "ace" is a subsequence of "abcde" while "aec" is not).
*/

#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s, string t) {
    if(s.length() > t.length()) return false;

    int i=0, j=0;
    while(i < s.length() and j < t.length()) {
        if(s[i] == t[j]) {
            i++; 
            j++;
        } else {
            j++;
        }
    }

    return (i < s.length()) ? false : true;
}