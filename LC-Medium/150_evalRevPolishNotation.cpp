/*
150. Evaluate Reverse Polish Notation - Medium
----------------------------------------------
You are given an array of strings tokens that represents an arithmetic expression
in a Reverse Polish Notation.
Evaluate the expression. Return an integer that represents the value of the
expression.

Note that:
    ->The valid operators are '+', '-', '*', and '/'.
    ->Each operand may be an integer or another expression.
    ->The division between two integers always truncates toward zero.
    ->There will not be any division by zero.
    ->The input represents a valid arithmetic expression in a reverse polish notation.
    ->The answer and all the intermediate calculations can be represented in a
    32-bit integer.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int first = st.top();
                st.pop();

                int second = st.top();
                st.pop();

                if (tokens[i] == "+")
                    st.push(second + first);
                else if (tokens[i] == "-")
                    st.push(second - first);
                else if (tokens[i] == "*")
                    st.push(second * first);
                else if (tokens[i] == "/")
                    st.push(second / first);
            }
            else
                st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};