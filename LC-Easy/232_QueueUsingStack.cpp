/*
232. Implement Queue using Stacks - Easy
----------------------------------------
Implement a first in first out (FIFO) queue using only two stacks.
The implemented queue should support all the functions of a
normal queue (push, peek, pop, and empty).
*/

#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
    MyQueue() {}

    stack<int> input;
    stack<int> output;

    void push(int x)
    {
        input.push(x);
    }

    int pop()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                int val = input.top();
                input.pop();
                output.push(val);
            }
        }
        // if output is not empty
        int topElement = output.top();
        output.pop();
        return topElement;
    }

    int peek()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                int val = input.top();
                input.pop();
                output.push(val);
            }
        }
        return output.top();
    }

    bool empty()
    {
        return (input.empty() and output.empty());
    }
};
