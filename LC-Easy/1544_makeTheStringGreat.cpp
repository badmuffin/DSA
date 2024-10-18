/*
1544. Make The String Great - Easy
-----------------------------------
Given a string s of lower and upper case English letters.

A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:
    0 <= i <= s.length - 2
    s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.

To make the string good, you can choose two adjacent characters that make the string bad and
remove them. You can keep doing this until the string becomes good.

Return the string after making it good. The answer is guaranteed to be unique under the
given constraints.

Notice that an empty string is also good.
*/

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string makeGood(string s)
    {
        stack<char> st;
        string result;

        for (int i = 0; i < s.size(); i++)
            (!st.empty() and (abs(s[i] - st.top()) == 32)) ? st.pop() : st.push(s[i]);

        // insert the remaining characters in the result string
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }

        // to retain the correct order of the string
        reverse(result.begin(), result.end());

        return result;
    }
};