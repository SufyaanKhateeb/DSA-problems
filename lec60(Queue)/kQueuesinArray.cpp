// best implementation of k queues in a array
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class myQueue {
    int n;
    int k;
    int* front;
    int* rear;
    int* arr;
    int* next;
    int freespot;
public:
    myQueue(int n, int k) {
        this->n = n;
        this->k = k;
        front = new int[k];
        memset(front, -1, (k) * sizeof(int));
        rear = new int[k];
        memset(rear, -1, (k) * sizeof(int));
        arr = new int[n];
        memset(arr, 0, (n) * sizeof(int));
        next = new int[n];
        for (int i = 0; i < n; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
        freespot = 0;
    }
    void enqueue(int x, int m) { // insert x in the mth queue
        // check for overflow
        if (freespot == -1) {
            cout << "Queue is full." << endl;
            return;
        }
        // finding the index to insert
        int index = freespot;

        // updating freespot
        freespot = next[index];

        // if first element in queue
        if (front[m - 1] == -1) {
            front[m - 1] = index;
        }
        else { // other than first element
            next[rear[m - 1]] = index;
        }
        // common operations for any element insertion
        next[index] = -1;
        rear[m - 1] = index;
        arr[index] = x;
    }

    int dequeue(int m) {
        // checking queue is empty
        if (front[m - 1] == -1) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        // finding the index of front of queue
        int index = front[m - 1];
        // updating the front
        front[m - 1] = next[index];
        // setting the next of index to the next freespot and updating freespot
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};

int main() {
    myQueue q(10, 2);
    q.enqueue(1, 1);
    q.enqueue(2, 1);
    q.enqueue(3, 1);
    q.enqueue(4, 1);
    q.enqueue(5, 1);
    q.enqueue(6, 1);
    q.enqueue(7, 2);
    q.enqueue(8, 2);
    q.enqueue(9, 2);
    q.enqueue(10, 2);

    // should give not able to insert, queue is full
    q.enqueue(11, 1);

    cout << q.dequeue(1) << endl;
    q.enqueue(11, 2);
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(2) << endl;

    // should give queue is empty message
    cout << q.dequeue(2) << endl;

    return 0;
}