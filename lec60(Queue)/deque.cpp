#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class MyCircularDeque {
    int* arr;
    int f;
    int r;
    int size;
public:
    MyCircularDeque(int k) {
        size = k;
        arr = new int[size];
        f = r = -1;
    }

    bool push_front(int value) {
        if (isFull())
            return false;
        else if (f == -1) {
            f = r = 0;
        }
        else if (f == 0 && r != size - 1) {
            f = size - 1;
        }
        else {
            f--;
        }
        arr[f] = value;
        return true;
    }

    bool push_back(int value) {
        if (isFull())
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

    bool pop_front() {
        if (isEmpty())
            return false;
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

    bool pop_back() {
        if (isEmpty())
            return false;
        int data = arr[r];
        arr[r] = -1;
        if (f == r) {
            f = r = -1;
        }
        else if (r == 0) {
            r = size - 1;
        }
        else {
            r--;
        }
        return true;
    }

    int getFront() {
        if (isEmpty())
            return -1;
        else
            return arr[f];
    }

    int getBack() {
        if (isEmpty())
            return -1;
        else
            return arr[r];
    }

    bool isEmpty() {
        return (f == -1);
    }

    bool isFull() {
        return (f == 0 && r == size - 1 || r == f - 1);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main() {

    // our implementation
    MyCircularDeque dq(4);
    dq.push_back(1);
    dq.push_front(2);
    cout << "Front: " << dq.getFront() << endl;
    cout << "Back: " << dq.getBack() << endl;

    dq.pop_front();
    cout << "Front: " << dq.getFront() << endl;
    cout << "Back: " << dq.getBack() << endl;
    dq.pop_back();

    if (dq.isEmpty())
        cout << "Queue is empty." << endl;
    else
        cout << "Queue is not empty." << endl;



    // using stl
    // deque<int> dq;
    // dq.push_back(1);
    // dq.push_front(2);
    // cout << "Front: " << dq.front() << endl;
    // cout << "Back: " << dq.back() << endl;

    // dq.pop_front();
    // cout << "Front: " << dq.front() << endl;
    // cout << "Back: " << dq.back() << endl;
    // dq.pop_back();

    // if (dq.empty())
    //     cout << "Queue is empty." << endl;
    // else
    //     cout << "Queue is not empty." << endl;
    return 0;
}