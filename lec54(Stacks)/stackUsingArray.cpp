#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Stack {
private:
    int* arr;
    int size;
    int top;
public:
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int data) {
        if (top < size - 1) {
            top++;
            arr[top] = data;
        }
        else {
            cout << "Stack overflow." << endl;
        }
    }
    void pop() {
        if (top >= 0) {
            arr[top] = 0;
            top--;
        }
        else {
            cout << "Stack underflow." << endl;
        }
    }
    int getTop() {
        if (top >= 0) {
            return arr[top];
        }
        else {
            cout << "Stack Empty." << endl;
        }
        return -1;
    }
    int getSize() {
        return top + 1;
    }
    bool empty() {
        return top == -1;
    }
};

int main() {
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    int size = s.getSize();
    for (int i = 0; i < size; i++) {
        cout << s.getTop() << " ";
        s.pop();
    } cout << endl;

    if (s.empty())
        cout << "Stack is empty." << endl;
    else
        cout << "Stack is not empty." << endl;

    return 0;
}