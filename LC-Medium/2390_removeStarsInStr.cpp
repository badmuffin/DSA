/*
2390. Removing Stars From a String - Medium
-------------------------------------------
You are given a string s, which contains stars *.

In one operation, you can:
   -> Choose a star in s.
   -> Remove the closest non-star character to its left, as well as remove the star itself.

Return the string after all stars have been removed.

Note:
   -> The input will be generated such that the operation is always possible.
   -> It can be shown that the resulting string will always be unique.

*/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string removeStars(string s)
    {
        string result;

        for (int i = 0; i < result.size(); i++)
        {
            // alternatively we can use ternary operator
            // s[i] == '*' ? result.pop_back() : result.push_back(s[i]);
            if (s[i] == '*')
                result.pop_back();
            else
                result.push_back(s[i]);
        }
        return result;
    }
};

/*
while(!stk.empty()) {
    // DON'T - IT ENVOLVE COPYING AND REALLOCATING MEMORY REPEATEDLY, MLE FOR LARGE INPUT
    result = stk.top() + result;
    stk.pop();
}
*/