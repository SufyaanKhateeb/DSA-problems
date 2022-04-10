#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack {
private:
    Node* head;
    int size = 0;
public:
    Stack() {
        head = NULL;
        size = 0;
    }
    Stack(int data) {
        Node* temp = new Node(data);
        head = temp;
        size++;
    }
    void push(int data) {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
        size++;
    }
    void pop() {
        if(head == NULL) {
            cout << "Stack underflow." << endl;
        } else {
            Node* temp = head;
            head = head->next;
            size--;
        }
    }
    int getTop() {
        if(head == NULL){
            cout << "Stack empty.";
            return -1;
        } else
            return head->data;
    }
    int getSize() {
        return size;
    }
    bool empty() {
        return head==NULL;
    }
};

int main() {
    Stack s(1);
    // s.push(1);
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