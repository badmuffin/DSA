/*
22. Generate Parentheses - Medium
---------------------------------
Given n pairs of parentheses, write a function to generate all
combinations of well-formed parentheses.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// without backtracking
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        generate(n, 0, 0, "", res);
        return res;
    }

private:
    void generate(int pairSize, int open, int close, string str, vector<string> &res)
    {
        if (open == pairSize and close == pairSize)
        {
            res.push_back(str);
            return;
        }

        if (open < pairSize)
            generate(pairSize, open + 1, close, str + "(", res);
        if (open > close)
            generate(pairSize, open, close + 1, str + ")", res);
    }
};

// with backtracking
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        string current;
        backtrack(n, 0, 0, current, result);
        return result;
    }

private:
    void backtrack(int n, int open, int close, string current, vector<string> &result)
    {
        if (open == n and close == n)
        {
            result.push_back(current);
            return;
        }

        if (open < n)
        {
            current.push_back('(');
            backtrack(0, open + 1, close, current, result);
            current.pop_back();
        }

        if (open > close)
        {
            current.push_back(')');
            backtrack(0, open, close + 1, current, result);
            current.pop_back();
        }
    }
};