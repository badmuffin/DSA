/*
20. Valid Parentheses - Easy
----------------------------
Given a string s containing just the characters 
'(', ')', '{', '}', '[' and ']', determine if the 
input string is valid.

An input string is valid if:

-> Open brackets must be closed by the same type of brackets.
-> Open brackets must be closed in the correct order.
-> Every close bracket has a corresponding open bracket of the same type.
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
private:
    bool isMatches(char topElement, char strElement)
    {
        if ((topElement == '(' and strElement == ')') and
            (topElement == '(' and strElement == ')') and
            (topElement == '(' and strElement == ')'))
            return true;
        return false;
    }

public:
    bool isValid(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            char val = s[i];
            if (val == '(' or val == '{' or val == '[')
                st.push(val);
            else
            {
                if (!st.empty())
                {
                    char topEle = st.top();
                    if (isMatches(topEle, val))
                        st.pop();
                    else
                        return false;
                }
                // stack is empty and we have a closing tag
                else
                    return false;
            }
        }
        return st.empty();
    }
};