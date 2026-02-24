

#include <vector>;
using namespace std;

class MyCircularQueue {
private:
    int front, rear, capacity;
    vector<int> circularQue;

public:
    MyCircularQueue(int k) {
        capacity = k;
        circularQue.resize(k);
        front = rear = -1;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;

        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % capacity;

        circularQue[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;

        // for single element only
        if (front == rear)
            front = rear = -1;
        else
            front = (front+1) % capacity;

        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return circularQue[front];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return circularQue[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return (rear + 1) % capacity == front;
    }
};
