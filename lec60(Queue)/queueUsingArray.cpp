#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Queue {
    int size;
    int* arr;
    int f; // front
    int r; // rear
public:
    Queue() {
        // Implement the Constructor
        size = 100001;
        arr = new int[size];
        f = 0;
        r = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return f == r;
    }

    void push(int data) { // enqueue
        // Implement the enqueue() function
        if (r == size)
            return;
        arr[r++] = data;
    }

    int pop() { // dequeue
        // Implement the dequeue() function
        if (f == r)
            return -1;
        int data = arr[f];
        arr[f++] = -1;
        if (f == size)
            f = r = 0;
        return data;
    }

    int front() {
        // Implement the front() function
        if (isEmpty())
            return -1;
        return arr[f];
    }
};

int main() {
    Queue q = *(new Queue());
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    cout << "Front: " << q.front() << endl;
    if (q.isEmpty())
        cout << "Empty queue." << endl;
    else
        cout << "Queue not empty." << endl;

    return 0;
}