#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class MyCircularQueue {
    int* arr;
    int f;
    int r;
    int size;
public:
    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
        f = r = -1;
    }

    bool push(int value) {
        if (f == 0 && r == size - 1 || r == (f - 1))
            return false;
        else if (f == -1) {
            f = r = 0;
        }
        else if (r == size - 1 && f != 0) {
            r = 0;
        }
        else {
            r++;
        }
        arr[r] = value;
        return true;
    }

    bool pop() {
        if (f == -1) {
            return false;
        }
        int data = arr[f];
        arr[f] = -1;
        if (f == r) {
            f = r = -1;
        }
        else if (f == size - 1) {
            f = 0;
        }
        else {
            f++;
        }
        return true;
    }

    int front() {
        if (f == -1)
            return -1;
        else
            return arr[f];
    }

    int rear() {
        if (f == -1)
            return -1;
        else
            return arr[r];
    }

    bool isEmpty() {
        return f == -1;
    }

    bool isFull() {
        return (f == 0 && r == size - 1 || r == f - 1);
    }
};

int main() {
    MyCircularQueue q = *(new MyCircularQueue(4));
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