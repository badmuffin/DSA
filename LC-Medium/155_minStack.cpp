/*
155. Min Stack - Easy
---------------------
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

    MinStack() initializes the stack object.
    void push(int val) pushes the element val onto the stack.
    void pop() removes the element on the top of the stack.
    int top() gets the top element of the stack.
    int getMin() retrieves the minimum element in the stack.

You must implement a solution with O(1) time complexity for each function.
 */

#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
  public:
    MinStack() {}
    stack<int> stk;
    // track the minimum value after each push operation
    stack<int> minStk;

    void push(int val)
    {
        stk.push(val);
        if (minStk.empty())
            minStk.push(val);
        else
            minStk.push(min(val, minStk.top()));
    }

    void pop()
    {
        stk.pop();
        minStk.pop();
    }

    int top()
    {
        return stk.top();
    }

    int getMin()
    {
        return minStk.top();
    }
};
