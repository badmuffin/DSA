/*
225. Implement Stack using Queues - Easy
---------------------------------------
Implement a last-in-first-out (LIFO) stack using only two queues.
The implemented stack should support all the functions of a normal
stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
*/

#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
public:
    MyStack() {}
    queue<int> q;

    void push(int x)
    {
        int size = q.size();
        q.push(x);

        // iteration is one less then the total size of queue
        for (int i = 0; i < size; i++)
        {
            int element = q.front();
            q.pop();
            q.push(element);
        }
    }

    int pop()
    {
        int val = q.front();
        q.pop();
        return val;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};