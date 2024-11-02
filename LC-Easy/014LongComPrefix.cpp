/*
14. Longest Common Prefix - Easy
--------------------------------
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Time Complexity - O(m.n), Space Complexity - O(n)
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string res = "";
        for (int i = 0; i < strs.size(); i++)
        {
            for (auto s : strs)
            {
                if (s[i] != strs[0][i])
                    return res;
            }
            res.push_back(strs[0][i]);
        }
        return res;
    }
};

// Time Complexity - O(nlogn + m), Space complexity - O(m)
class Solution1
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string res = "";

        // Sorting arranges the strings in lexicographical (dictionary) order.
        // This means that the strings that are lexicographically closest will
        // be grouped together.
        sort(strs.begin(), strs.end());
        int size = strs.size();

        string first = strs[0];
        string last = strs[size - 1];

        for (int i = 0; i < min(first.size(), last.size()); i++)
        {
            if (first[i] != last[i])
                return res;
            res.push_back(first[i]);
        }
        return res;
    }
};