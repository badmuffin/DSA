/*
242. Valid Anagram - Easy
-------------------------
Given two strings s and t, return true if t is
an anagram of s, and false otherwise.
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;

    // create a map to store the count of the characters
    unordered_map<char, int> charCount;

    // increase the count of the characters found in the s string
    for (auto ch : s)
        charCount[ch]++;

    // decrease the count of the characters found in the t string
    for (auto ch : t)
        charCount[ch]--;

    // now check whether the count of all the characters in the map is zero or not
    for (auto count : charCount)
    {
        if (count.second != 0)
            return false;
    }

    return true;
}

